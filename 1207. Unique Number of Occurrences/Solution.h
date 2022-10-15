class Solution
{
public:
    bool uniqueOccurrences(std::vector<int> &arr)
    {
        std::set<int> counts;
        std::map<int, int> m;
        auto it = m.end();
        for (const auto &n : arr)
        {
            it = m.find(n);
            if (it == m.end())
            {
                m.insert(std::pair<int, int>(n, 1));
            }
            else
            {
                it->second += 1;
            }
        }

        for (auto mit = m.begin(); mit != m.end(); mit++)
        {
            if (counts.find(mit->second) != counts.end())
            {
                return false;
            }
            else
            {
                counts.insert(mit->second);
            }
        }

        return true;
    }
};