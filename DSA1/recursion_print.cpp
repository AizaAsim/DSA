#include<iostream>
using namespace std;
void call(int n){
if(n==0){return ;}
 call(n-1);
cout<<n;
}
int main(){
  call(5);}