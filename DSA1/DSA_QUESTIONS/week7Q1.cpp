/*Write a program and recurrence relation to find the Fibonacci series of n where n>2.*/
#include<iostream>
using namespace std;
int fibonacci(int n){
  if(n<=1) {
    return n;
  }
  return (fibonacci(n-1)+fibonacci(n-2));

}
int main(){
int n;
cout<<"Enter the number you want for fibonacci series"<<endl;
cin>>n;
cout<<fibonacci(n);
}