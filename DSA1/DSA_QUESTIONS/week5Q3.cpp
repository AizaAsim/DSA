/*Write a program using stacks which takes an expression as input and determines whether the
delimiters are matched or not.*/
#include<iostream>
using namespace std;
class Node{public:
  char data;
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
char pop(){if(!isempty()){
  Node*temp=top;
  char temp2=temp->data;
top=top->next;
delete temp;
cout<<"popped"<<endl;
return temp2;
}else{cout<<"The stack is empty"<<endl;
return '0';}
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
void check_delimmiter(){
  string s2;
  Stack s1;
  bool flag=false; 
  cout<<"Enter the string"<<endl;
  cin>>s2;
  int i=0;
  while(s2[i]!='\0')
  {
    if(s2[i]=='['||s2[i]=='{'||s2[i]=='('){ flag=true;
    while(s2[i]!=']'||s2[i]=='}'||s2[i]==')')
    s1.push(s2[i]);
  i++;
    }
    if(s2[i]==']')
  }
   while(!s1.isempty() ||  ){
if(s2[i]=='['||s2[i]=='{'||s2[i]=='('){ flag=true;
  while(s2[i]!=']'|| s2[i]!='}' || s2[i]!=')' || s2[i]!='\0'){
    s1.push(s2[i]);
  }
if(!s1.isempty())
{
  s1.pop();
}

}}
  }

