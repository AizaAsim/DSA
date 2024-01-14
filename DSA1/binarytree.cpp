#include<iostream>
using namespace std;
class Node{public:
  int data;
  Node*left;
  Node*right;
Node(int x):data(x),left(nullptr),right(nullptr){}
Node(){}
};
class binary_tree{

public:
  Node*root;
  Node*create(){int x;
  cout<<"Enter the data"<<endl;
cin>>x;if(x==-1){return nullptr;}    Node*newnode=new Node(x);
cout<<"Enter data for the left node"<<x<<endl;
newnode->left=create();
cout<<"Enter data for the right node"<<x<<endl;
newnode->right=create();
return newnode;

  }
void preorder_traversal(Node*newnode){
  if(newnode==nullptr||newnode->data==-1){return;}
  cout<<newnode->data<<" ";;
   preorder_traversal(newnode->left);
  preorder_traversal(newnode->right);
  
}
void inorder_traversal(Node*newnode){if(newnode==nullptr||newnode->data==-1){return;}
   preorder_traversal(newnode->left);
   cout<<newnode->data<<" ";;
  preorder_traversal(newnode->right);
  
   
}
void postorder_traversal(Node*newnode){if(newnode==nullptr||newnode->data==-1){return;}
 
   preorder_traversal(newnode->left);
  preorder_traversal(newnode->right);
   cout<<newnode->data<<" ";;
  
}
void level_order_traversal(){
  
}
int count_leaf(Node*newnode){
  if(newnode->right==nullptr &&newnode->left==nullptr){return 1;}

   return(count_leaf(newnode->left)+count_leaf(newnode->right));


}int nodes=0;
int count_nodes(Node*newnode){if(newnode==nullptr || newnode->data==-1){return 0;}
nodes++;

count_nodes(newnode->left);
count_nodes(newnode->right);
return nodes;
}int max=0;
int findmax(Node*newnode){
if(newnode==nullptr || newnode->data==-1){return 0;}
if(newnode->data>max){max=newnode->data;}
findmax(newnode->left);
findmax(newnode->right);
return max;
}

};
int main(){
  binary_tree b1;
  b1.root=b1.create();
  //int leaf=b1.count_leaf(b1.root);
  //cout<<"Leaves"<<leaf;
//cout<<b1.count_nodes(b1.root);
cout<<b1.findmax(b1.root);
}
