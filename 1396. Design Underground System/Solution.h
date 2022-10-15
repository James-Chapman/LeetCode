struct SingleJourney
{
    int id;
    std::string startStation;
    int startTime;
};

using DestinationMap = std::map<std::string, std::vector<int>>;
using DestinationPair = std::pair<std::string, std::vector<int>>;

class UndergroundSystem
{
public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        auto idTravellingIt = m_idTravelling.find(id);
        if (idTravellingIt == m_idTravelling.end())
        {
            SingleJourney j{id, stationName, t};
            m_idTravelling.insert(std::pair<int, SingleJourney>(id, j));
        }
        else
        {
            return;
        }
    }

    void checkOut(int id, string stationName, int t)
    {
        // Delete journey
        auto idTravellingIt = m_idTravelling.find(id);
        if (idTravellingIt == m_idTravelling.end())
        {
            return;
        }

        auto travelTime = t - idTravellingIt->second.startTime;

        {
            auto journeyTimesIt = m_journeyTimes.find(idTravellingIt->second.startStation);
            if (journeyTimesIt == m_journeyTimes.end())
            {
                // currently no record
                std::vector<int> v;
                v.push_back(travelTime);
                DestinationMap m;
                m.insert(DestinationPair(stationName, v));
                m_journeyTimes.insert(std::pair<std::string, DestinationMap>(idTravellingIt->second.startStation, m));
            }
            else
            {
                // start station record exists, but does end station?
                auto destinationIt = journeyTimesIt->second.find(stationName);
                if (destinationIt == journeyTimesIt->second.end())
                {
                    std::vector<int> v;
                    v.push_back(travelTime);
                    journeyTimesIt->second.insert(DestinationPair(stationName, v));
                }
                else
                {
                    destinationIt->second.push_back(travelTime);
                }
            }
        }

        m_idTravelling.erase(idTravellingIt);
    }

    double getAverageTime(string startStation, string endStation)
    {
        double retval{0};
        auto journeyTimesIt = m_journeyTimes.find(startStation);
        if (journeyTimesIt == m_journeyTimes.end())
        {
            return 0;
        }
        double total{0};
        for (const auto &time : journeyTimesIt->second.at(endStation))
        {
            total += time;
        }
        if (journeyTimesIt->second.at(endStation).size() > 0)
        {
            retval = total / journeyTimesIt->second.at(endStation).size();
            return retval;
        }
        else
        {
            return 0;
        }
    }

private:
    std::map<std::string, std::map<std::string, std::vector<int>>> m_journeyTimes;
    std::map<int, SingleJourney> m_idTravelling;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */