// #include "../List/SeqList.h"
#include "Tree/Tree.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, NULL, 4, 5, 6, 7, 8, 9};
    vector<int> v(begin(a), end(a));

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
    TreeNode *root = Tree(v);
    prettyPrintTree(nullptr);
    TreeNode *p = new TreeNode(11);
    prettyPrintTree(p);
    prettyPrintTree(root);
    return 0;
}