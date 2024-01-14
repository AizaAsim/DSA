/*A palindrome is a word, phrase, number, or another sequence of characters that reads the same
backward and forwards. Can you determine if a given string, s, is a palindrome? Write a
Program using stack for checking whether a string is palindrome or not.*/
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
  //cout<<"pushed"<<endl;
}
char pop(){if(!isempty()){
  Node*temp=top;
  char temp2=temp->data;
top=top->next;
delete temp;
//cout<<"popped"<<endl;
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
void isPalindrome(){
  Stack s1;
  string s2;
  cout<<"Enter the string to check if it's a palindrome or not"<<endl<<endl<<endl;
  cin>>s2;
  int i=0;
while(s2[i]!='\0'){
s1.push(s2[i]);
i++;
}
int j=0;
while(j<i){
  if(s2[j]!=s1.pop()){
break;
  }
  j++;}
  cout<<endl<<endl<<endl;
if(i==j)
{
  cout<<"The entered string is a palindrome"<<endl<<endl<<endl;
}
else{
  cout<<"The entered string is not a palindrome"<<endl<<endl<<endl;
}
}
int main(){
 isPalindrome(); 
}



