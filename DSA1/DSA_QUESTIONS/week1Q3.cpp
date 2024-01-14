#include<iostream>
using namespace std;
int main(){int n=2;
  string **arr=new string*[n];
  int rows[n];
  for(int i=0;i<n;i++)
  {cout<<"Enter the number of columns you want in row"<<i+1<<endl;
  cin>>rows[i];
  }
  for(int i=0;i<n;i++)
  {
arr[i]=new string[rows[i]];
  }
for(int i=0;i<n;i++)
{
  for(int j=0;j<rows[i];j++)
  {
    cout<<"Enter the name of student "<<j+1<<" of the row"<<i+1<<endl;
  cin>>arr[i][j];  
  }
}
string key;
cout<<"Enter the name you want to search"<<endl;
cin>>key;
for(int i=0;i<n;i++)
{
for(int j=0;j<rows[i];j++)
{
  if(key==arr[i][j])
  {
    cout<<"The name has been found at the index of row "<<i+1<<" and column"<<j+1<<endl;
    break; 
  }
}
}
 for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;}

