#include "Tree.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> t;
        // t.push_back(1);
        if (root == NULL)
            return t;
        inorderTraversal(root, t);
        return t;
    }
    void inorderTraversal(TreeNode *root, vector<int> &t)
    {
        if (root != NULL)
        {
            inorderTraversal(root->left, t);
            t.push_back(root->val);
            inorderTraversal(root->right, t);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int arr[] = {1, 2, 3, NULL, 4, 5, 6, 7, 8, 9};
    vector<int> v(begin(arr), end(arr));
    TreeNode *root = Tree(v);
    vector<int> ans = s.inorderTraversal(root);
    prettyPrintTree(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ", ";
    }
    return 0;
}
