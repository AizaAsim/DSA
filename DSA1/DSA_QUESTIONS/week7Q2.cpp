#include<iostream>
using namespace std;
/*Write a program and recurrence relation to find the Factorial of n where n>2.*/
int factorial(int n){
  if(n==0){return 1;}
  return n*factorial(n-1);
}
int main(){
  int n;
  cout<<"Choose the number you want the factorial for: ";
  cin>>n;
  cout<<"Factorial of "<< n<<": "<<factorial(n);
}