
#include<iostream>
#include<algorithm>
using namespace std;
class Toys{
  int N;
int K;
int counter=0;
int sum=0;
int *arr1;
int *arr;
  public:
Toys(){

  cout<<"Enter the number of toys"<<endl;
  cin>>N;
  cout<<"Enter the amount"<<endl;
  cin>>K;
 cout<<"Enter the values in the array"<<endl;
  arr1 = new int[N]; 
        arr = new int[N];
  for(int i=0;i<N;i++)
  {
    cin>>arr[i];
  }

}
void calculate (){
sort(arr, arr + N);
  
  for(int i=0;i<N;i++)
  {if(sum<K)
  { sum=sum+arr[i];
  if(sum<K){arr1[counter]=arr[i];counter++; }
 else if(sum==K)
  {arr1[counter]=arr[i];counter++;
    break;
  }
  else{
    break;

  }
    
  }}
}
void display(){
cout<<"We can buy "<<counter<<" items by the amount "<<K<<endl;
   cout<<"The prizes of items that could be bought are"<<endl;
  for(int i=0;i<counter;i++)
  {
    cout<<arr1[i]<<endl;
   

  }

}
};
int main()
{
  Toys t1;
  t1.calculate();
  t1.display();
}