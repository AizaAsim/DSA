


#include<iostream>
using namespace std;
void insertionsort(int *arr,int size) {
  int j,temp;for(int i=1;i<size;i++)
  {
    j=i-1;
temp=arr[i];
while(j>=0 && arr[j]>temp)
{

  arr[j+1]=arr[j];
    j--;
}
  }
  arr[j+1]=temp;
}
  