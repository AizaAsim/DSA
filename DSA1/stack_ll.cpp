#include<iostream>
using namespace std;
class Node{public:
  int data;
  Node * next;

};
class Stack{
Node*top;
public:
Stack():top(nullptr){
}
bool isempty(){
  return (top==nullptr);
  }
void push(int x){
  Node *newnode=new Node;
  newnode->data=x;
  newnode->next=top;
  top=newnode;
  cout<<"pushed"<<endl;
}
void pop(){if(!isempty()){
  Node*temp=top;
top=top->next;
delete temp;
cout<<"popped"<<endl;
}else{cout<<"The stack is empty"<<endl;}
}
int length(){int counter=0;Node *temp=top;
  while(temp!=nullptr){temp=temp->next;
counter++;
  }
  return counter;
}
void display(){
  if(!isempty()){Node *temp=top;
    for(int i=0;i<length();i++){
cout<<temp->data;
temp=temp->next;
    }
  }
}
void peek(){
  cout<<"The top element of the stack is "<<top->data;
}
};

int main(){
  Stack s1;
s1.push(3);
s1.push(4);
s1.push(9);
s1.push(1);
s1.push(0);
s1.pop();
s1.pop();
s1.peek();
s1.display();

s1.push(7);
}