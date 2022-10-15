class Solution
{
public:
    string intToRoman(int num)
    {
        std::string retval;
        std::vector<std::pair<std::string, int>> symbols{{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};

        for (auto &pair : symbols)
        {
            int ans = num / pair.second;
            if (ans >= 1)
            {
                while (ans > 0)
                {
                    retval += pair.first;
                    ans--;
                }
                num = num % pair.second;
            }
        }

        return retval;
    }
};