class Solution
{
public:
    int nearestExit(std::vector<std::vector<char>> &maze, std::vector<int> &entrance)
    {
        std::vector<std::pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        std::queue<std::vector<int>> bfsQueue;
        std::set<std::pair<int, int>> visited;

        bfsQueue.push({entrance[0], entrance[1], 0});
        visited.insert({entrance[0], entrance[1]});
        while (!bfsQueue.empty())
        {
            auto coords = bfsQueue.front();
            bfsQueue.pop();
            int row = coords[0];
            int col = coords[1];
            int dist = coords[2];

            for (const auto &dir : directions)
            {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                int newDist = dist + 1;

                if ((newRow >= 0) && (newRow < maze.size()) && (newCol >= 0) && (newCol < maze[0].size()))
                {
                    if ((maze[newRow][newCol] == '.') && (visited.find({newRow, newCol}) == visited.end()))
                    {
                        if (newRow == 0 || newRow == maze.size() - 1 || newCol == 0 || newCol == maze[0].size() - 1)
                        {
                            return newDist;
                        }

                        bfsQueue.push({newRow, newCol, newDist});
                        visited.insert({newRow, newCol});
                    }
                }
            }
        }
        return -1;
    }
};