#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> preOrder) { // T.C: O(n)--> linear time complexity
    idx++;
    if(preOrder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);// generate left side of tree
    root->right = buildTree(preOrder);// generate right side of tree
    return root;
}

// Preorder traversal
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder traversal
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// PostOrder traversal
void postOrder(Node* root) {
    if(root==NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main (){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);
    preOrder(root); // 1 2 3 4 5
    cout << endl;
    inorder(root); // 2 1 4 3 5
    cout << endl;
    postOrder(root); // 2 4 5 3 1
    return 0;
}
