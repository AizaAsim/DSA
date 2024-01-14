#include<iostream>
using namespace std;
class Node{public:
  int data;
Node *next;
};
class Queue{
  Node* rear;Node* front;
  public:
  Queue():rear(nullptr),front(nullptr){}
  bool isempty(){
    if(front==nullptr && rear==nullptr){
      return true;
    }
    return false;
  }
void enqueue(int x){
  Node *newnode=new Node;
newnode->data=x;
newnode->next=nullptr;
if(isempty()){
front=rear=newnode;
cout<<rear->data<<" enqueued!"<<endl;
}
else{
  rear->next=newnode;
  rear=newnode;
  cout<<rear->data<<" enqueued!"<<endl;
}
}
void dequeue(){
  if(!isempty()){ Node *temp;
  temp=front;
  front=front->next;

  cout<<temp->data<<" dequeued!"<<endl;
    delete temp;
  }
  else{cout<<"The queue is empty"<<endl;}
}
void display(){
  Node*temp;
  temp=front;
  if(!isempty()){
while(temp!=nullptr){
  cout<<temp->data<<"->";
  temp=temp->next;

}
  }
  else{cout<<"the queue is empty"<<endl;}
}
void peek(){cout<<front->data<<endl;}



};
int main(){
   Queue q1;
  q1.enqueue(2);
    q1.enqueue(2);
      q1.enqueue(2);
        q1.enqueue(2);
          q1.enqueue(9);
            q1.enqueue(8);
              q1.enqueue(3);
                q1.enqueue(5);
                q1.enqueue(5);
q1.dequeue();
q1.peek();


 q1.display();
}