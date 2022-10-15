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
    int maxDiff{0};

public:
    int maxAncestorDiff(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        diffCalc(root, root->val, root->val);
        return maxDiff;
    }

    void diffCalc(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->val > high)
        {
            high = root->val;
        }
        if (root->val < low)
        {
            low = root->val;
        }
        if (high - low > maxDiff)
        {
            maxDiff = high - low;
        }
        diffCalc(root->left, low, high);
        diffCalc(root->right, low, high);
    }
};