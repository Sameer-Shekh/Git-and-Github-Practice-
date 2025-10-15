#include <iostream>
#include <queue>
using namespace std;

// Color macros (ANSI escape codes)
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Tree
{
public:
    Node *root;

    Tree()
    {
        root = nullptr;
    }

    void preorder(Node *node)
    {
        if (node == nullptr)
            return;
        cout << RED << node->data << " " << RESET;
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << GREEN << node->data << " " << RESET;
        inorder(node->right);
    }

    void postorder(Node *node)
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << YELLOW << node->data << " " << RESET;
    }

    void levelOrder(Node *node)
    {
        if (node == nullptr)
            return;
        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            cout << CYAN << curr->data << " " << RESET;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    void levelOrderNewLine(Node *node)
    {
        if (node == nullptr)
            return;
        queue<Node *> q;
        q.push(node);
        q.push(nullptr);

        // APPROACH 1

        while (q.size() > 1)
        {
            Node *curr = q.front();
            q.pop();
            if (curr == nullptr)
            {
                if (!q.empty())
                {
                    cout << endl;
                    q.push(nullptr);
                    continue;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cout << MAGENTA << curr->data << " " << RESET;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }

        // APPROACH 2

        // while (!q.empty()) {
        //     int size = q.size();
        //     for (int i = 0; i < size; i++) {
        //         Node* curr = q.front();
        //         q.pop();
        //         cout << BLUE << curr->data << " " << RESET;
        //         if (curr->left) q.push(curr->left);
        //         if (curr->right) q.push(curr->right);
        //     }
        //     cout << endl;
        // }
    }
};

int main()
{
    Tree t;
    t.root = new Node(1);
    t.root->left = new Node(2);
    t.root->right = new Node(3);
    t.root->left->left = new Node(4);
    t.root->left->right = new Node(5);
    t.root->right->right = new Node(6);

    cout << BOLD << WHITE << "Preorder: " << RESET;
    t.preorder(t.root);
    cout << endl;

    cout << BOLD << WHITE << "Inorder: " << RESET;
    t.inorder(t.root);
    cout << endl;

    cout << BOLD << WHITE << "Postorder: " << RESET;
    t.postorder(t.root);
    cout << endl;

    cout << BOLD << WHITE << "Level Order (Single Line): " << RESET;
    t.levelOrder(t.root);
    cout << endl;

    cout << BOLD << WHITE << "Level Order (Each Level New Line):" << RESET << endl;
    t.levelOrderNewLine(t.root);

    return 0;
}
