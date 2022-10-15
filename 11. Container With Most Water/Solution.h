class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int a = 0;
        int b = height.size() - 1;
        int maxVol = 0;
        int vol = 0;
        int length = 0;
        int h = 0;

        while (a < b)
        {
            length = b - a;
            h = std::min(height[a], height[b]);
            vol = length * h;
            if (vol > maxVol)
            {
                maxVol = vol;
            }
            if (height[a] <= height[b])
            {
                a++;
            }
            else
            {
                b--;
            }
        }
        return maxVol;
    }
};