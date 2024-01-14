#include<iostream>
using namespace std;

class Array
{
    private:
        int rows;
        int cols;
        int **ptr;
        int *ptr1;
    public:

        Array(int r, int c)
        {
            rows = r;
            cols = c;
            ptr1 = new int[(r*c)];
            ptr = new int*[rows];
            for(int i=0; i<rows; i++)
            {
                ptr[i] = new int[cols];
            }
        }

        void set_values()
        {
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                {
                    cout<< "Enter value for " << i << " " << j << ": ";
                    cin>> ptr[i][j];
                }
            }
        }

        void set_values1d()
        {
            int c = 0, i = 0, j = 0;
            while(true)
            {
                ptr1[c] = ptr[i][j];
                i++;
                if(i == rows)
                {
                    j++;
                    i = 0;
                }
                if(j == cols)
                {
                    break;
                }
                c++;
            }
        }


        void display()
        {
            cout<< "2d Array: " << endl;
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                {
                    cout<< ptr[i][j] << " ";
                }
                cout<< endl;
            }
        }


        void display1d()
        {
            cout<< "1D Array: " << endl;
            for(int i=0; i<rows*cols; i++)
            {
                cout<< ptr1[i];
            }
        }

};

int main()
{
    int r, c;
    cout<< "Enter number of rows: ";
    cin>> r;
    cout<< "Enter number of cols: ";
    cin>> c;
	Array arr(r, c);
	arr.set_values();
	arr.set_values1d();
 	arr.display();
  	arr.display1d();
	return 0;
}
