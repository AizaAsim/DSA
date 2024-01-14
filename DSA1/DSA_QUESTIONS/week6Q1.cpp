#include<iostream>
using namespace std;
class Queue {
private:
int front, rear, size;
unsigned capacity;
int* array;
public:
Queue(int siz):rear(-1),size(0),capacity(siz),front(0){
array=new int [capacity];
}
void insert(int j){
if(!isFull()){rear = (rear + 1) % capacity;
  array[size]=j;
  size++;
cout<<j<<" inserted"<<endl;
}
else{
  cout<<"The queue is full"<<endl;
}
}
int remove(){if(!isEmpty()){
cout<<array[front]<<"removed"<<endl;
front=(front+1)% capacity;
size--;
}
else
  {
    cout<<"The queue is empty"<<endl;
  }
}
int peek(){ if(!isEmpty()){return array[front];}

else
  {
    cout<<"The queue is empty"<<endl;
  }
}
bool isEmpty(){
 return size==0;
}
bool isFull(){
  return size==capacity;
  
}

int size1(){
  return size;
}
};
int main(){
  Queue q1(8);
  q1.insert(3);
   q1.insert(0);
    q1.insert(2);
     q1.insert(1);
      q1.insert(7);
       q1.insert(10);
       q1.remove();
          q1.remove();
             q1.remove();
             cout<<q1.peek();
           
             


}