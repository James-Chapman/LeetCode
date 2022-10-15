/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        int level{0};
        int nodesOnLevel{0};

        std::deque<TreeNode *> myqueue;
        myqueue.push_back(root);

        std::vector<std::vector<int>> retVec;
        bool reverse = false;

        while (!myqueue.empty())
        {
            ++level;
            nodesOnLevel = myqueue.size();
            std::vector<int> v;
            for (int i = 0; i < nodesOnLevel; ++i)
            {
                if (level % 2 == 0)
                {
                    reverse = true;
                }
                else
                {
                    reverse = false;
                }

                if (!reverse)
                {
                    auto node = myqueue.front();
                    myqueue.pop_front();
                    v.push_back(node->val);
                    if (node->left != nullptr)
                        myqueue.push_back(node->left);
                    if (node->right != nullptr)
                        myqueue.push_back(node->right);
                }
                else
                {
                    auto node = myqueue.back();
                    myqueue.pop_back();
                    v.push_back(node->val);
                    if (node->right != nullptr)
                        myqueue.push_front(node->right);
                    if (node->left != nullptr)
                        myqueue.push_front(node->left);
                }
            }
            retVec.push_back(v);
        }

        return retVec;
    }
};