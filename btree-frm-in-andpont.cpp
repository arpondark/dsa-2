#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<int, int> inorderIndex;
int postIdx;

TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight) {
    if (inLeft > inRight) return NULL;

    int rootVal = postorder[postIdx--];
    TreeNode* root = new TreeNode(rootVal);

    int idx = inorderIndex[rootVal];

    root->right = build(inorder, postorder, idx + 1, inRight);
    root->left  = build(inorder, postorder, inLeft, idx - 1);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    postIdx = postorder.size() - 1;
    inorderIndex.clear();

    for (int i = 0; i < inorder.size(); i++) {
        inorderIndex[inorder[i]] = i;
    }

    return build(inorder, postorder, 0, inorder.size() - 1);
}

void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> inorder(n), postorder(n);

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) cin >> inorder[i];

    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; i++) cin >> postorder[i];

    TreeNode* root = buildTree(inorder, postorder);

    cout << "Preorder traversal of constructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
/*
Enter number of nodes: 5
Enter inorder traversal: 9 3 15 20 7
Enter postorder traversal: 9 15 7 20 3
Preorder traversal of constructed tree: 3 9 20 15 7

*/