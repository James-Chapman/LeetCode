class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        // handle empty and single word arrays
        if (strs.size() == 0)
        {
            return {};
        }
        else if (strs.size() == 1)
        {
            return strs[0];
        }

        // populate prefix with first word
        std::vector<char> prefix(strs[0].begin(), strs[0].end());

        for (int i = 1; i < strs.size(); ++i)
        {
            // empty string means no prefix
            if (strs[i].size() == 0)
            {
                return {};
            }

            // prefix can't be longer than any word
            if (strs[i].size() < prefix.size())
            {
                prefix.resize(strs[i].size());
            }

            for (int j = 0; j < prefix.size(); ++j)
            {
                // if word letter matches prefix, move to next letter, else
                // resize the prefix to the common size
                if (prefix[j] == strs[i][j])
                {
                    continue;
                }
                else
                {
                    prefix.resize(j);
                    break;
                }
            }
        }

        std::string retval(prefix.begin(), prefix.end());
        return retval;
    }
};