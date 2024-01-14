/*Write a recursive function which will take input from the user until a special character
(also selected by the user) is not entered. Then print all the input in reverse.
Sample Input:
Enter Special Character: !
Enter Character: A
Enter Character: B
Enter Character: C
Enter Character: !
Sample Output: C B A*/
#include<iostream>
using namespace std;
void abc()
{char character;bool flag=false;
  cout<<"Enter the character"<<endl;
  cin>>character;
  if(character>='A' && character <='Z' ||character>='a' && character <='z' ||character>='0' && character <='9'){
    flag=true;
  }
  if(flag==false){return;}
  abc();
  cout<<character;

}
int main(){
  abc();
}