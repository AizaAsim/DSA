#include<iostream>
using namespace std;
class heap{
public:  int *arr;
  int n;
  int size;
  heap(int n1){
    size=0;
    n=n1;
    arr=new int[n];
arr[0]=-1;
  }
  void insert(int val){
    if(n>size){
      size++;
      int index=size;
      arr[index]=val;
      while(index>1  && arr[index] > arr[index/2])
      {
    swap(arr[index],arr[index/2]);
index=index/2;
      }


    }
    else{
      cout<<"no space"<<endl;
    }
  }
void delete1(){
arr[1]=arr[size];
size--; int i=1;
while(i<size){
  int leftindex=2*i;
  int rightindex=2*i+1;
  int maxIndex=i;
  if(leftindex<=size && arr[maxIndex]<arr[leftindex])
  {
maxIndex=leftindex;
  }
  if(rightindex<=size && arr[maxIndex]<arr[rightindex])
{
  maxIndex=rightindex;
}
if(maxIndex !=i){
  swap(arr[maxIndex],arr[i]);
}
else{
  return;
}
}
}

void display(){
  for (int i=1;i<=size;i++)
  {
    cout<<arr[i]<<endl;
  }
}

};
void heapify_max(int *arr, int size, int i){
int left=2*i;
int right=2*i+1;
int maxIndex=i;
if(left<=size && arr[maxIndex]<arr[left]){
maxIndex=left;
}
if(right<=size && arr[maxIndex]<arr[right])
{
  maxIndex=right;
}
if(maxIndex != i){
  swap(arr[maxIndex],arr[i]);
  heapify_max(arr,size,maxIndex);
}
}
void heapsort(int * arr,int n){
  int size=n;
  while(size>1){
    swap(arr[1],arr[size]);
    size--;
    heapify_max(arr,size,1);
  }

}
void display(int *arr2,int n){
  for(int i=1;i<=n;i++){
    cout<<arr2[i];
  }
}


int main(){
 heap h1(10);
 h1.insert(3);
 h1.insert(5);
 h1.insert(18);
 h1.insert(10);
 h1.insert(27);
 h1.display();
 h1.delete1();
h1.display();
int arr1[]={-1,1,2,3,5,14,15};
int n=6;
for(int i=n/2;i>=0;i--){
heapify_max(arr1,n,i);
}
display(arr1,6);
int arr2[]={-1,5,3,2,31,87,34};
heapsort(arr2,7);
}