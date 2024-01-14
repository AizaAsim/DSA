#include<iostream>
using namespace std;
/*Write a recursive method that for a positive integer n prints odd numbers

a. between 1 and n
b. between n and 1*/

void print_odd_a(int n){
  if(n<=0){return;}

  cout<<n;

print_odd_a(n-1-1);



}

void print_odd_b(int n){
  if(n<=0){return;}

 

print_odd_b(n-1-1);
 cout<<n;


}
int main(){int n;
  cout<<"1: Enter the number to print from 1 to n :";
cin>>n;
if(n<0){cout<<"Please enter correct number"<<endl;
return 0;}
cout<<endl;
print_odd_b(n);
  cout<<"2: Enter the number to print from n to 1 :";
cin>>n;
if(n<0){cout<<"Please enter correct number"<<endl;
return 0;}
print_odd_a(n);

}


