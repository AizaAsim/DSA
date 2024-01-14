#include<iostream>
using namespace std;
int partition(int A[],int lb,int ub){
  int pivot=A[lb];
int start=lb+1;
int end=ub;
  while(start<end){
    while(A[start]<=pivot){start++;}
    while(A[end]>pivot){
      end--;
    }
    if(start<end){
      swap(A[start],A[end]);
    }

  }
  swap(A[lb],A[end]);
}
void QuickSort(int A[],int lb,int ub){
int loc;if(lb<ub){
  loc=partition(A,lb,ub);
  partition(A,lb,loc-1);
  partition(A,loc+1,ub);


}
}
int main(){
 int A[]={7,6,10,5,9,2,1,15,7};
 int n = sizeof(A) / sizeof(A[0]);

}