#include "Tree.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool ans = true;
        if (p == NULL && q == NULL)
            return true;
        else if (p == NULL || q == NULL)
            return false;
        queue<TreeNode *> nodeQueue1, nodeQueue2;
        nodeQueue1.push(p);
        nodeQueue2.push(q);
        while (!nodeQueue1.empty() && !nodeQueue2.empty())
        {
            p = nodeQueue1.front();
            nodeQueue1.pop();
            q = nodeQueue2.front();
            nodeQueue2.pop();
            if (p == NULL && q == NULL)
                continue;
            else if (p == NULL || q == NULL)
                return false;
            else if (p->val != q->val)
                return false;
            else
            {
                nodeQueue1.push(p->left);
                nodeQueue1.push(p->right);
                nodeQueue2.push(q->left);
                nodeQueue2.push(q->right);
            }
        }

        if (nodeQueue1.empty() && nodeQueue2.empty())
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int arr[] = {1, 2, 3, NULL, 4, 5, 6, 7, 8, 9};
    vector<int> v(begin(arr), end(arr));
    TreeNode *root = Tree(v);
    int arr1[] = {1, 2, 3, NULL, 4, 6, 7, 8, 9};
    vector<int> v1(begin(arr1), end(arr1));
    TreeNode *root1 = Tree(v1);
    bool ans = s.isSameTree(root, root1);
    // prettyPrintTree(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << ", ";
    // }
    cout << ans << endl;
    return 0;
}
