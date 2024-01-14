#include<iostream>
using namespace std;
class Node{public:
int data;
Node * left;
Node*right;
Node(int x){
  data=x;
  left=nullptr;
  right=nullptr;
}
};
class BinaryTree{public:
  Node *root;
Node* BuildTree(){
  int x;
  cout<<"Enter the data for the node (-1 for no node)"<<endl;
  cin>>x;
  if(x==-1){
    return nullptr;
  }
Node *newnode=new Node(x);
cout<<"Enter data fot the left node of "<<x<<endl;
newnode->left=BuildTree();
cout<<"Enter data fot the right node of "<<x<<endl;
newnode->right=BuildTree();
return newnode;

}
void preorder_traversal(Node * root1){
if(root1==nullptr || root1->data ==-1){
  return;
}
cout<<root1->data<<" ";
preorder_traversal(root1->left);
preorder_traversal(root1->right);

}

void postorder_traversal(Node * root1){
  if(root1==nullptr || root1->data==-1){
    return;
  }
  postorder_traversal(root1->left);
  postorder_traversal(root1->right);
  cout<<root1->data<<" ";
}
void inorder_traversal(Node *root1){
if(root1==nullptr || root1->data==-1)
{
  return;
}
inorder_traversal(root1->left);
cout<<root1->data<<" ";
inorder_traversal(root1->right);
}
};



int main(){
  BinaryTree b1;
  b1.root=b1.BuildTree();
  cout<<"preorder"<<endl;
b1.preorder_traversal(b1.root);
cout<<"postorder"<<endl;
b1.postorder_traversal(b1.root);
cout<<"inorder"<<endl;
b1.inorder_traversal(b1.root);
}