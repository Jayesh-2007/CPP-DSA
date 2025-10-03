#include <iostream>
#include <vector>
#include <queue>
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

Node* buildTree(vector<int> preorderVec) { // T.C: O(n)--> linear time complexity
    idx++;
    if(preorderVec[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorderVec[idx]);
    root->left = buildTree(preorderVec);// generate left side of tree
    root->right = buildTree(preorderVec);// generate right side of tree
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


// LevelOrder traversal
void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else {
                break;
            }
        }

        cout << curr->data << " ";
        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

int main (){
    vector<int> preorderVec = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorderVec);
    preOrder(root); // 1 2 3 4 5
    cout << endl;
    inorder(root); // 2 1 4 3 5
    cout << endl;
    postOrder(root); // 2 4 5 3 1
    cout << endl;
    levelOrder(root); // 1 
                      // 2 3 
                      // 4 5
    return 0;
}
