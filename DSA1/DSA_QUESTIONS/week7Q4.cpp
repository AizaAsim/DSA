/*Write a recursive function which will raise a number (double) to a non-negative integer
power n. The function receives the double value and integer as arguments.*/
#include<iostream>
using namespace std;
double power(double x,int y){
  if(y==0){
    return 1;
  }
  return (x*power(x,y-1));

}
int main(){
  int y;
  double x;
  cout<<"Enter the double value you want the power of: ";
  cin>>x;
  cout<<"Enter the power: ";
  cin>>y;
  cout<<x <<" raised to the power "<<y<<" is: "<< power(x,y);
}