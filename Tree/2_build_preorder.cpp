#include <iostream>
#include <vector>
using namespace std;

// -------------------------
// Node Class
// -------------------------
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// -------------------------
// Function to Build Tree
// -------------------------
Node* buildTree(vector<int>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == -1) {
        index++;  // move past the null marker
        return nullptr;
    }

    Node* root = new Node(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}

// -------------------------
// Function to Print Preorder
// -------------------------
void printPreorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// -------------------------
// Main Function
// -------------------------
int main() {
    // Preorder with -1 representing NULL
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    int index = 0;
    Node* root = buildTree(preorder, index);

    cout << "Preorder of constructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
