#include<iostream>
using namespace std;
void search(int arr[],int size,int key){
  int i;for(i=0;i<size;i++){
    if(arr[i]==key){
      break;
    }
  }
  if(i==size){cout<<"Element not found";}
  else{
    cout<<"Element found in the index "<<i;
  }
}
int main(){
int arr[]={1,2,3,4,5,6,7,8,9,0};
search(arr,10,5);
}