#include<iostream>
using namespace std;
class Node{public:
  int data;
  Node *left;
  Node *right;
Node(int x):left(nullptr),right(nullptr),data(x){}
};
Node*insert_bst(Node *root,int val){

  if(root==nullptr){
    return new Node(val);

  }
  if(val<root->data){
    root->left=insert_bst(root->left,val);
  }
  else{
    root->right=insert_bst(root->right,val);
  }
  return root;
}
int inorder_traversal(Node *newnode){
  if(newnode==nullptr){return 0;}
  inorder_traversal(newnode->left);
  cout<<newnode->data;
  inorder_traversal(newnode->right);

  
 }
bool search(Node*newnode,int val){
 if(newnode==nullptr){return false;}
  if(val==newnode->data){return true;}

  if(val<newnode->data){ return search(newnode->left,val);

  }
  else{
    return search(newnode->right,val);
 }



}

Node* minval(Node *newnode) {
  if (newnode == nullptr || newnode->left == nullptr) {
    return newnode;
  }
  return minval(newnode->left);
}

Node* maxval(Node *newnode) {
  if (newnode == nullptr || newnode->right == nullptr) {
    return newnode;
  }
 
  return maxval(newnode->right);
}
Node *delete1(Node*temp,int val){
  if(temp==nullptr){ return 0;}
if(temp->data==val){
if(temp->right==nullptr && temp->left==nullptr){

  delete temp;
  return nullptr;
}
 if(temp->right==nullptr && temp->left !=nullptr){
Node*newnode=temp->left;
delete temp;
return newnode;


}

 if(temp->left==nullptr && temp->right !=nullptr){
Node*newnode=temp->right;
delete temp;
return newnode;



}

if(temp->left!=nullptr && temp->right !=nullptr){
 int newnode;
 newnode=minval(temp)->data;
 temp->data=newnode;
 temp->right=delete1(temp->right,newnode);

}

}
else if (temp->data>val){
  temp->left=delete1(temp->left,val);
return temp;

}
else{temp->right=delete1(temp->right,val);
return temp;


}
}

int main(){
  Node *root=nullptr;
  root=insert_bst(root,5);
  insert_bst(root,6);
  insert_bst(root,2);
   insert_bst(root,3);
  insert_bst(root,9);
   insert_bst(root,1);
  insert_bst(root,4);
 cout<<endl;
cout<<maxval(root)->data;

 
}