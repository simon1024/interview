#include <iostream>
#include "TreeUtil.h"
using namespace std;


int findMaxPathSum(BinaryTree* root, int& maxSum2Root) {
    if(!root) {
        maxSum2Root = 0;
        return 0;
    }

    int leftMax = 0;
    int rightMax = 0;
    int leftMaxSum2Root = 0;
    int rightMaxSum2Root = 0;

    leftMax = findMaxPathSum(root->left, leftMaxSum2Root);
    rightMax = findMaxPathSum(root->right, rightMaxSum2Root);
    
    maxSum2Root = max(leftMaxSum2Root, rightMaxSum2Root) + root->value;
    
    return max(max(leftMax, rightMax), leftMaxSum2Root + rightMaxSum2Root + root->value);
}

int main() {

    {
        string treeDesc = "1|"
                         "2,3|"
                       "4,5,6,7|";
        BinaryTree* root = TreeUtil::buildTree(treeDesc);
        int maxSum2Root;
        int maxSum = findMaxPathSum(root, maxSum2Root);
        cout << "max sum:" << maxSum << endl;
        cout << "max sum to root:" << maxSum2Root << endl;
    }
    {
        string treeDesc = "1|"
                         "2,#|"
                       "4,#,#,#|";
        BinaryTree* root = TreeUtil::buildTree(treeDesc);
        int maxSum2Root;
        int maxSum = findMaxPathSum(root, maxSum2Root);
        cout << "max sum:" << maxSum << endl;
        cout << "max sum to root:" << maxSum2Root << endl;
    }

    {
        string treeDesc = "1|"
                         "#,3|"
                       "#,#,#,7|";
        BinaryTree* root = TreeUtil::buildTree(treeDesc);
        int maxSum2Root;
        int maxSum = findMaxPathSum(root, maxSum2Root);
        cout << "max sum:" << maxSum << endl;
        cout << "max sum to root:" << maxSum2Root << endl;
    }

    {
        string treeDesc = "1|"
                         "2,3|"
                       "4,5,#,#|"
                   "7,8,9,#,#,#,#,#|"
                "#,#,#,8,9,#,#,#,#,#|";
        BinaryTree* root = TreeUtil::buildTree(treeDesc);
        int maxSum2Root;
        int maxSum = findMaxPathSum(root, maxSum2Root);
        cout << "max sum:" << maxSum << endl;
        cout << "max sum to root:" << maxSum2Root << endl;
    }

    return 0;
}
