#include<iostream>
using namespace std;
class matrix{
int **p;
int r;
int c;
int *rowmajor;
int *multiply1D;
int total;
public:
matrix (int row,int col):r(row),c(col)
{
   total=r*c;
  p=new int*[r];
  for(int i=0;i<r;i++)
  {
    p[i]=new int[c];
  }
rowmajor=new int[total];
}
void input(){
  cout<<"Enter the values in the 2D matrix"<<endl;
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      cout<<"Matrix["<<i<<"]["<<j<<"]=";
      cin>>p[i][j];
    }
  }
}

void disp2D(){
  
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      cout<<"Matrix["<<i<<"]["<<j<<"]="<<p[i][j]<<endl;
    }
  }
}
void dispRowMajor(){
 
  
  int k=0;
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++){
      rowmajor[k]=p[i][j];
      k++;
    }
  }

}

void dispRowMajor1(){
  for(int i=0;i<total;i++)
  {
cout<<"Matrix["<<i<<"]="<<rowmajor[i]<<endl;
  }
}
void Multiply_rowMajor(matrix & x)
{ if(total==x.total){
  for(int i=0;i<total;i++){
multiply1D[i]=rowmajor[i]*x.rowmajor[i];
  rowmajor[i]=multiply1D[i];
  }}
  else
  {
    cout<<"The number of elements are unequal therefore the muliplication us not possible"<<endl;
    exit(0);
  }

}
void rowMajor_2D(){
int k=0;
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++){
    p[i][j] = multiply1D[k];
      k++;
    }
  }
}
~matrix(){
  for(int i=0;i<r;i++)
  {
    delete p[i];

  }
  delete[]p;
  delete[]rowmajor;
  delete[]multiply1D;
}
};
int main()
{
   matrix a(4,3);
    matrix b(3,4);
a.input();a.disp2D();
b.input();b.disp2D();
a.dispRowMajor();
a.dispRowMajor1();
b.dispRowMajor();
b.dispRowMajor1();
a.Multiply_rowMajor(b);
a.dispRowMajor1();
a.rowMajor_2D();
a.disp2D();


    return 0;
}