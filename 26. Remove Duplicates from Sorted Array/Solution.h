class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int previous{0};
        int cursor{0};
        int forward{0};
        int startSize = nums.size();

        if (nums.size() <= 1)
        {
            return nums.size();
        }

        for (cursor = 1; cursor < nums.size(); ++cursor)
        {
            if (nums[previous] >= nums[cursor])
            {
                while (1)
                {
                    ++forward;
                    if (forward == startSize)
                    {
                        return cursor;
                    }
                    if (nums[previous] < nums[forward])
                    {
                        break;
                    }
                }
                nums[cursor] = nums[forward];
            }
            ++previous;
        }
        return cursor;
    }
};