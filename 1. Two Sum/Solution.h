class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        if (nums.size() < 2 || nums.size() > 100000)
        {
            return {};
        }
        if (target < -10000000000 || target > 10000000000)
        {
            return {};
        }

        auto n = nums.size() - 1;
        std::map<int, int> m;

        for (int i = 0; i <= n; ++i)
        {
            auto it = m.find(target - nums[i]);
            if (it != m.end())
            {
                return std::vector<int>{it->second, i};
            }
            m.insert(std::pair<int, int>(nums[i], i));
        }

        return {};
    }
};