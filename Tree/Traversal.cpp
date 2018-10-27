#include "Tree.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Traversal
{
  public:
    void preOrder1(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *p = root;

        while (p || !s.empty())
        {
            if (p)
            {
                v.push_back(p->val);
                if (p->right)
                    s.push(p->right);
                p = p->left;
            }
            else
            {
                p = s.top();
                s.pop();
            }
        }

        cout << "Pre Order 1 is:" << endl;
        printVector(v);
    }

    void preOrder2(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *p = root;
        s.push(p);

        while (!s.empty())
        {
            p = s.top();
            s.pop();
            if (p)
            {
                v.push_back(p->val);
                s.push(p->right);
                s.push(p->left);
            }
        }

        cout << "Pre Order 2 is:" << endl;
        printVector(v);
    }

    void inOrder(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *p = root;

        while (p || !s.empty())
        {
            if (p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                s.pop();
                v.push_back(p->val);
                p = p->right;
            }
        }

        cout << "In Order is:" << endl;
        printVector(v);
    }

    void postOrder(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *p = root, *r;
        // s.push(p);

        while (p || !s.empty())
        {
            if (p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                if (p->right && p->right != r)
                {
                    p = p->right;
                    s.push(p);
                    p = p->left;
                }
                else
                {
                    p = s.top();
                    s.pop();
                    v.push_back(p->val);
                    r = p;
                    p = NULL;
                }
            }
        }

        cout << "Post Order is:" << endl;
        printVector(v);
    }

    void levelOrder(TreeNode *root)
    {
        vector<int> v;
        queue<TreeNode *> q;

        if (!root)
            return;

        TreeNode *p = root;
        q.push(p);

        while (!q.empty())
        {
            p = q.front();
            q.pop();

            v.push_back(p->val);

            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }

        cout << "Level Order is:" << endl;
        printVector(v);
    }

    void reverseOrder(TreeNode *root)
    {
        vector<int> v;
        queue<TreeNode *> q;
        stack<TreeNode *> s;

        if (!root)
            return;

        TreeNode *p = root;
        q.push(p);

        while (!q.empty())
        {
            p = q.front();
            q.pop();
            s.push(p);

            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }

        while (!s.empty())
        {
            p = s.top();
            s.pop();
            v.push_back(p->val);
        }

        cout << "Reverse Order is:" << endl;
        printVector(v);
    }

    void printVector(vector<int> v)
    {
        cout << "[ ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }

    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<TreeNode *> q;
        TreeNode *p = root, *r = root;
        int height = 0;
        q.push(p);

        while (!q.empty())
        {
            p = q.front();
            q.pop();

            if (p->left)
                q.push(p->left);

            if (p->right)
                q.push(p->right);

            if (p == r)
            {
                height++;
                r = q.back();
            }
        }
        return height;
    }

    int width(TreeNode *root)
    {
        if (!root)
            return 0;
        int width = 0;
        int levelwidth = 0;
        queue<TreeNode *> q;
        TreeNode *p = root, *r = root;
        q.push(p);

        while (!q.empty())
        {
            p = q.front();
            q.pop();
            levelwidth++;

            if (p->left)
                q.push(p->left);

            if (p->right)
                q.push(p->right);

            if (p == r)
            {
                width = (levelwidth > width) ? levelwidth : width;
                levelwidth = 0;
                r = q.back();
            }
        }
        return width;
    }

    TreeNode *buildTree(vector<int> pre, int s1, int e1, vector<int> in, int s2, int e2)
    {

        if (s1 > e1)
            return NULL;

        int f = pre[s1];
        TreeNode *p = new TreeNode(f);
        int i;
        for (i = 0; in[s2 + i] != f; i++)
            ;
        p->left = buildTree(pre, s1 + 1, s1 + i, in, s2, s2 + i - 1);
        p->right = buildTree(pre, s1 + i + 1, e1, in, s2 + i + 1, e2);

        cout << "Build Tree is:" << endl;
        prettyPrintTree(p);
        return p;
    }

    bool fullTree(TreeNode *root)
    {
        queue<TreeNode *> q;

        if (!root)
        {
            cout << "This Tree is a full tree!" << endl;
            return true;
        }
        TreeNode *p = root;
        q.push(root);

        while (!q.empty())
        {
            p = q.front();
            q.pop();
            if (p)
            {
                q.push(p->left);
                q.push(p->right);
            }
            else
            {
                while (!q.empty())
                {
                    p = q.front();
                    q.pop();
                    if (p)
                    {
                        cout << "This Tree is not a full tree!" << endl;
                        return false;
                    }
                }
            }
        }
        cout << "This Tree is a full tree!" << endl;
        return true;
    }

    int doubleNode(TreeNode *root)
    {
        if (!root)
            return 0;

        if (root->left && root->right)
            return doubleNode(root->left) + doubleNode(root->right) + 1;
        else
            return doubleNode(root->left) + doubleNode(root->right);
    }

    TreeNode *swapLeftAndRight(TreeNode *root)
    {
        if (root)
        {
            swapLeftAndRight(root->left);
            swapLeftAndRight(root->right);
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        return root;
    }

    int preOrderOfK(TreeNode *root, int &i, int k)
    {
        if (!root)
            return -1;
        if (i == k)
            return root->val;
        i++;
        int val = preOrderOfK(root->left, i, k);
        if (val != -1)
            return val;
        val = preOrderOfK(root->right, i, k);
        return val;
    }

    void deleteTree(TreeNode *root)
    {
        if (root)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }

    TreeNode *deleteValOfX(TreeNode *root, int x)
    {
        if (!root)
            return NULL;
        if (root->val == x)
        {
            deleteTree(root);
            root = NULL;
        }
        else
        {
            root->left = deleteValOfX(root->left, x);
            root->right = deleteValOfX(root->right, x);
        }
        return root;
    }

    vector<int> ancestor(TreeNode *root, int x)
    {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *p = root, *r;
        // s.push(p);

        while (p || !s.empty())
        {
            if (p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                if (p->right && p->right != r)
                {
                    p = p->right;
                    s.push(p);
                    p = p->left;
                }
                else
                {
                    p = s.top();
                    s.pop();
                    v.push_back(p->val);

                    if (p->val == x)
                    {
                        s.push(p);
                        break;
                    }

                    r = p;
                    p = NULL;
                }
            }
        }

        vector<int> a;

        while (!s.empty())
        {
            int p = s.top()->val;
            s.pop();
            a.push_back(p);
        }

        cout << "The ancestor of " << x << " is:" << endl;
        printVector(a);
        return a;
    }

    int commonAncestor(TreeNode *root, int p, int q)
    {
        vector<int> r1 = ancestor(root, p);
        vector<int> r2 = ancestor(root, q);

        for (int i = 0; i < r1.size(); i++)
        {
            int r = r1[i];
            for (int j = 0; j < r2.size(); j++)
            {
                if (r == r2[j])
                {
                    cout << "Common ancestor is : " << r << endl;
                    return r;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Traversal s;
    vector<TreeNode *> v = treeList();

    for (int i = 0; i < v.size(); i++)
    {
        prettyPrintTree(v[i]);
        // s.preOrder1(v[i]);
        // s.preOrder2(v[i]);
        // s.inOrder(v[i]);
        // s.postOrder(v[i]);
        // s.levelOrder(v[i]);
        // s.reverseOrder(v[i]);
        cout << "The height is : " << s.height(v[i]) << endl;
        cout << "The width  is : " << s.width(v[i]) << endl;
        // s.fullTree(v[i]);
        // cout << "The number of double node is : " << s.doubleNode(v[i]) << endl;
        // prettyPrintTree(s.swapLeftAndRight(v[i]));
        // int j = 1, k = 5;
        // cout << "The " << k << "th of Pre Order is : " << s.preOrderOfK(v[i], j, k) << endl;
        // prettyPrintTree(s.deleteValOfX(v[i], 4));
        // s.ancestor(v[i], 9);
        // s.ancestor(v[i], 8);
        // s.commonAncestor(v[i], 6, 9);
        cout << endl;
    }

    // int arr[] = {1, 2, 4, 7, 8, 3, 5, 9, 6};
    // vector<int> v(begin(arr), end(arr));

    // int arr1[] = {2, 7, 4, 8, 1, 9, 5, 3, 6};
    // vector<int> v1(begin(arr1), end(arr1));

    // TreeNode *p = s.buildTree(v, 0, 8, v1, 0, 8);
    // prettyPrintTree(p);

    return 0;
}
