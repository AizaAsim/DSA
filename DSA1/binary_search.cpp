#include<iostream>
using namespace std;
int search(int arr[],int left,int right,int key ){int mid;bool found;

while(left<=right){
  mid=left+(right-left)/2;
  if(arr[mid]==key){cout<<"The element found at index "<<mid;
  return mid;

  }
else if (arr[mid]<key){ 
 left=mid+1;
}
else{
 right=mid-1;
}
}
  
} 
int main(){int arr[]={1,2,3,4,5,6,7,8,9,0};
  search(arr,0,10,3);

}