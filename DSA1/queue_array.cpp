#include<iostream>
using namespace std;
class Queue{
int rear;int front;
int size;int *queue;
public:
Queue(int s):front(-1),rear(-1),size(s){
queue=new int[size];

  }  
  void enqueue(int x){
    if(isfull()){
      cout<<"The queue is full"<<endl;
    }
else if(rear==-1 && front==-1 )
  {
    rear++;front++;
    queue[rear]=x;
    cout<<x<<" enqueued!"<<endl; 
  }
else{rear++;
 queue[rear]=x;
    cout<<x<<" enqueued!"<<endl; 
}}
bool isempty(){
  if(front==-1 && rear==-1){
  
    return true;
  }
  else{
    return false;
  }
}
void dequeue(){
  if(isempty()){
  cout<<"The queue is full"<<endl;
}
else if(front==rear){ cout<<queue[front]<<" dequeued"<<endl;
  front=-1;
  rear=-1;

}
else{
  cout<<queue[front]<<" dequeued"<<endl;
  front++;
  
}
}
bool isfull(){
  if(rear>size-1){
    return true;
  }
  return false;
}
int peek(){if(!isempty()){
  return queue[front];
}
else{cout<<"The queue is empty"<<endl;}}
void resize(int newsize){
int *new_queue;
new_queue=new int[newsize];
for(int i=0;i<size;i++){
  new_queue[i]=queue[i];
}
delete []queue;
queue=new_queue;
size=newsize;
}
void display(){if(!isempty()){
  for(int i=front;i<rear+1;i++){
    cout<<queue[i];
  }
}
else{cout<<"The queue is empty"<<endl;}
}
  

};
int main(){
  Queue q1(7);
  q1.enqueue(2);
    q1.enqueue(2);
      q1.enqueue(2);
        q1.enqueue(2);
          q1.enqueue(2);
            q1.enqueue(2);
              q1.enqueue(2);
                q1.enqueue(2);
q1.dequeue();
q1.dequeue();
q1.dequeue();

q1.dequeue();

q1.dequeue();

q1.dequeue();

q1.dequeue();
 q1.resize(10);
 q1.peek();
 q1.display();

}