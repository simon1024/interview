#include "StringUtil.h"
#include <queue>
using namespace std;

struct BinaryTree {
    BinaryTree* left;
    BinaryTree* right;
    int value;
    BinaryTree(int d) {
        value = d;
        left = NULL;
        right = NULL;
    }
};

class TreeUtil {
public:
    TreeUtil() {}
    ~TreeUtil() {}

public:
    static BinaryTree* buildTree(const string& desc);
    static void layerTraverse(BinaryTree* root);
};

BinaryTree* TreeUtil::buildTree(const std::string& desc) {
    if(desc.empty()) {
        return NULL;
    }
    vector<string> layerList = StringUtil::split(desc, "|");
    vector<BinaryTree*> treeNodeList;
    treeNodeList.push_back(NULL);

    if(layerList[0] == "#") {
        cout << "invalid tree desc";
        return NULL;
    }

    BinaryTree* root = new BinaryTree(stoi(layerList[0]));
    treeNodeList.push_back(root);
    int count = 1;

    for(size_t i = 1; i < layerList.size(); ++i) {
        vector<string> nodeList = StringUtil::split(layerList[i], ",");
        for(size_t j = 0; j < nodeList.size(); ++j) {
            count++;
            if(nodeList[j] == "#") {
                treeNodeList.push_back(NULL);
                continue;
            }
            BinaryTree* node = new BinaryTree(stoi(nodeList[j]));
            treeNodeList.push_back(node);
            int parentIdx = count/2;
            if(treeNodeList[parentIdx] == NULL) {
                cout << "invalid tree desc";
                return NULL;
            }

            if(count%2) {
                treeNodeList[parentIdx]->right = node;
            }else {
                treeNodeList[parentIdx]->left = node;
            }
        }
    }

    return root;
}

void TreeUtil::layerTraverse(BinaryTree* root) {
    if(!root) {
        return ;
    }

    queue<BinaryTree*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTree* node = q.front();
        q.pop();
        cout << node->value << ",";
        if(node->left) {
            q.push(node->left);
        }

        if(node->right) {
            q.push(node->right);
        }
    }

}
