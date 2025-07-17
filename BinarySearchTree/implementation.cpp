#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};

// insert each value 
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
}

Node* getInorderSuccesor(Node* root) {
    while(root != NULL && root->left == NULL) {
        root = root->left;
    }
    return root;
}

// for deleting node
Node* delNode(Node* root, int key) { // key => value to delete
    if(root == NULL) {
        return NULL;
    }

    if(key < root->data) {
        root->left = delNode(root->left, key);
    } else if(key > root->data) {
        root->right = delNode(root->right, key);
    } else {
        // key == root->data
        // 1 child
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->left == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            // 2 children
            Node* IS = getInorderSuccesor(root->right);
            root->data = IS->data;
            delNode(root->right, IS->data);
        }
    }
    return root;
}

Node *buildBST(vector<int> arr)
{
    Node *root = NULL;
    for (int val : arr)
    {
        root = insert(root, val);
    }
    return root;
}

// Search value in BST(BINARY SEARCH TREE)
bool search(Node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }
    if (root->data > val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr);
    // inorder(root);
    // search val 6
    // cout << search(root, 6) << endl; // true
    // cout << search(root, 8) << endl; // false
    cout << "Before: " << endl;
    inorder(root);
    cout << endl;
    delNode(root, 5);
    cout << "After" << endl;
    inorder(root);
    return 0;
}