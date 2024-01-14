#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *right;
    Node *left;

    Node(int d) {
        data = d;
        right = nullptr;
        left = nullptr;
    }

    Node() {}
};

class BinaryTree {
public:
    Node* root;

    Node* BuildTree() {
        int x;
        cout << "Enter the data for the node (-1 for no node): ";
        cin >> x;

        if (x == -1) {
            return nullptr;
        }

        Node* newNode = new Node(x);
        cout <<endl<<endl<< "Enter the left child of " << x << ": ";
        newNode->left = BuildTree();
        cout << endl<<endl<<"Enter the right child of " << x << ": ";
        newNode->right = BuildTree();

        return newNode;
    }

    void preorder_traversal(Node*newnode){
if(newnode == nullptr ||newnode->data==-1){return;}
cout<<newnode->data<<" ";
preorder_traversal(newnode->left);
preorder_traversal(newnode->right);

    }
    void inorder_traversal(Node *newnode){
      if(newnode == nullptr ||newnode->data==-1){return;}
      inorder_traversal(newnode->left);
      cout<<newnode->data<<" ";
      inorder_traversal(newnode->right);


    }

    void postorder_traversal(Node *newnode){
      if(newnode == nullptr ||newnode->data==-1){return;}
postorder_traversal(newnode->left);
postorder_traversal(newnode->right);
cout<<newnode->data<<" ";

    }
};

int main() {
    BinaryTree b1;
    b1.root = b1.BuildTree();
    cout<<endl<<endl<<endl;
    cout<<"PREORDER TRAVERSAL"<<endl;
    b1.preorder_traversal(b1.root);
    cout<<endl<<endl<<endl;
     cout<<"INORDER TRAVERSAL"<<endl;
    b1.inorder_traversal(b1.root);
    cout<<endl<<endl<<endl;
      cout<<"POSTORDER TRAVERSAL"<<endl;
 b1.postorder_traversal(b1.root);
    return 0;
}
