#include <iostream>
#include "TreeUtil.h"

using namespace std;

int maxDistance(BinaryTree* root, int& deep) {
    if(!root) {//null node
        deep = 0;
        return 0;
    }

    if(!root->left && !root->right) {// leaf node
        deep = 0;
        return 0;
    }

    int leftDeep = 0;
    int rightDeep = 0; 
    int leftDis = 0; 
    int rightDis = 0;
    if(root->left) {
        leftDis = maxDistance(root->left, leftDeep);
        leftDeep++;
    }

    if(root->right) {
        rightDis = maxDistance(root->right, rightDeep);
        rightDeep++;
    }

    deep = max(leftDeep, rightDeep);
    int dis = max( max(leftDis, rightDis), leftDeep + rightDeep);
    return dis;
}

int main() {
    int deep, dis;

    {
        string treeDesc = "1|"
                         "2,3|"
                       "4,5,6,7|";
        BinaryTree* root = TreeUtil::buildTree(treeDesc);
        dis = maxDistance(root, deep);
        cout << "max distance:" << dis << endl;
        cout << "deep:" << deep << endl;
        TreeUtil::layerTraverse(root);
    }

    {
        string treeDesc = "1|"
                         "2,#|"
                       "4,#,#,#|";
        BinaryTree* root = TreeUtil::buildTree(treeDesc);
        dis = maxDistance(root, deep);
        cout << "max distance:" << dis << endl;
        cout << "deep:" << deep << endl;
        TreeUtil::layerTraverse(root);
    }

    {
        string treeDesc = "1|"
                         "#,3|"
                       "#,#,#,7|";
        BinaryTree* root = TreeUtil::buildTree(treeDesc);
        dis = maxDistance(root, deep);
        cout << "max distance:" << dis << endl;
        cout << "deep:" << deep << endl;
        TreeUtil::layerTraverse(root);
    }

    {
        string treeDesc = "1|"
                         "2,3|"
                       "4,5,#,#|"
                   "7,8,9,#,#,#,#,#|"
                "#,#,#,8,9,#,#,#,#,#|";
        BinaryTree* root = TreeUtil::buildTree(treeDesc);
        dis = maxDistance(root, deep);
        cout << "max distance:" << dis << endl;
        cout << "deep:" << deep << endl;
        TreeUtil::layerTraverse(root);
    }

    return 0;
}
