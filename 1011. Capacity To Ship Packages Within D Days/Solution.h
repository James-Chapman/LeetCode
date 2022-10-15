class Solution
{
public:
    int countDays(vector<int> &weights, int ship)
    {
        int d = 1;
        int container{0};

        for (const auto &w : weights)
        {
            if (container + w > ship)
            {
                ++d;
                container = 0;
            }
            container += w;
        }
        return d;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int total{0};
        int biggest{0};

        for (const auto &w : weights)
        {
            total += w;
            if (w > biggest)
            {
                biggest = w;
            }
        }

        int d{0};
        int left = biggest;
        int right = total;
        int mid = (left + right) / 2;

        while (left < right)
        {
            d = countDays(weights, mid);

            if (d > days)
            {
                left = mid + 1;
            }
            else if (d <= days)
            {
                right = mid;
            }
            mid = (left + right) / 2;
        }

        if (mid < biggest)
        {
            mid = biggest;
        }
        return mid;
    }
};