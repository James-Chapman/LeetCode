/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

enum Direction
{
    UP = 0,
    RIGHT,
    DOWN,
    LEFT
};

class Solution
{
public:
    std::set<std::pair<int, int>> visited;

    void cleanRoom(Robot &robot)
    {
        backtrack(robot, 0, 0, 0);
    }

    void backtrack(Robot &robot, int x, int y, int direction)
    {
        visited.insert({x, y});
        robot.clean();

        for (int i = 0; i < 4; ++i)
        {
            int newX = x;
            int newY = y;
            int newDirection = (direction + i) % 4;

            if (newDirection == UP)
            {
                ++newY;
            }
            else if (newDirection == RIGHT)
            {
                ++newX;
            }
            else if (newDirection == DOWN)
            {
                --newY;
            }
            else if (newDirection == LEFT)
            {
                --newX;
            }

            while (visited.find({newX, newY}) == visited.end() && robot.move())
            {
                backtrack(robot, newX, newY, newDirection);
                goBack(robot);
            }
            robot.turnRight();
        }
    }

    void goBack(Robot &robot)
    {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
};