#include <iostream>
using namespace std;
class Stack
{
  int top;
  int size;
  int *stack;

public:
  Stack(int s) : top(-1), size(s)
  {
    stack = new int[size];
  }
  bool isempty()
  {

      return (top == -1);
  
  }
  bool isfull()
  {
  
  
      return  (top == size - 1);
  
  }
  void push(int x)
  {if(!isfull()){
    top++;
    stack[top] = x;
    cout << x << " Pushed in the stack" << endl;
  }
  else{
    cout<<"The stack is full"<<endl;
  }}
  int pop()
  {
    if (!isempty())
    {
      int temp;
      temp = stack[top];
      top--;
      cout << temp << " Popped from stack" << endl;
      return temp;
    }
    else
    {
      cout << "The stack is empty" << endl;
    }
  }
  int peek()
  {
    if (!isempty())
    {cout<<"The top element is"<<stack[top]<<endl;
      return stack[top];
    }
    else
    {
      cout << "The stack is empty" << endl;
    }
  }
  void resize(int newsize){if(newsize>size){
    int *newstack;
    newstack=new int[newsize];
    for(int i=0;i<size;i++){
      newstack[i]=stack[i];
    }
    delete [] stack;
   size=newsize; 
   stack=newstack;
  }
  else{
    cout<<"The stack is already of that size"<<endl;
  }
  }
  void display(){
    cout<<"STACK"<<endl;
    for(int i=0;i<size;i++){
      cout<<stack[i]<<endl;
    }
  }
};
int main(){
  Stack s1(5);
s1.push(3);
s1.push(4);
s1.push(9);
s1.push(1);
s1.push(0);
s1.pop();
s1.pop();
s1.peek();
s1.display();
s1.resize(9);
s1.push(7);
}