#include <iostream>
using namespace std;

class Sort {
    int *arr;
    string technique;
    int size;
    int swap_count;
    int no_of_comparisons;
    int temp;

public:
    Sort(int n) : size(n) {
        arr = new int[size];
    }

    void setarr(int *arr1) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = arr1[i];
        }
    }

    void setvalues() {
        cout << "Enter the values in the array" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Value " << i << ": ";
            cin >> arr[i];
        }
    }

    void display() {
        cout << "Sorted Array" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Array[" << i << "] = " << arr[i] << endl;
        }
    }

    void BubbleSort() {
        swap_count = 0;
        no_of_comparisons = 0;
        bool flag;
        for (int i = 0; i < size - 1; i++) {
            flag = false;
            for (int j = 0; j < size - i - 1; j++) {
                no_of_comparisons++;
                if (arr[j] > arr[j + 1]) {
                    flag = true;
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swap_count++;
                }
            }
            if (!flag) {
                break;
            }
        }
    }

    void InsertionSort() {
        swap_count = 0;
        no_of_comparisons = 0;
        int j;
        for (int i = 1; i < size; i++) {
            temp = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                no_of_comparisons++;
                arr[j + 1] = arr[j];
                j--;
                swap_count++;
            }
            arr[j + 1] = temp;
        }
    }

    void SelectionSort() {
        swap_count = 0;
        no_of_comparisons = 0;
        for (int i = 0; i < size - 1; i++) {
            int min = i;
            for (int j = i + 1; j < size; j++) {
                no_of_comparisons++;
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (min != i) {
                swap_count++;
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }
    }

    int get_swapcount() {
        return swap_count;
    }

    int get_no_of_comparisons() {
        return no_of_comparisons;
    }
};

void Analysis(int n, int *arr1) {
    Sort s1(n);
    s1.setarr(arr1);
    fflush(stdin);
    s1.SelectionSort();
    Sort s2(n);
    s2.setarr(arr1);
    s2.BubbleSort();
    Sort s3(n);
    s3.setarr(arr1);

    s3.InsertionSort();
   
 
    fflush(stdin);
    int swaps[3] = {s1.get_swapcount(), s2.get_swapcount(), s3.get_swapcount()};
    int compares[3] = {s1.get_no_of_comparisons(), s2.get_no_of_comparisons(), s3.get_no_of_comparisons()};


  
    cout << "Sorted Array" << endl;
    cout<<"Selection Sort"<<endl;
    s1.display();
    cout<<"No of Swaps: "<<swaps[0]<<endl;
    cout<<"No of Comparisons:"<<compares[0]<<endl;
    cout << "Bubble Sort" << endl;
    s2.display();
    cout<<"No of Swaps: "<<swaps[1]<<endl;
    cout<<"No of Comparisons:"<<compares[1]<<endl;
    cout << "Insertion Sort" << endl;
    s3.display();
    cout<<"No of Swaps: "<<swaps[2]<<endl;
    cout<<"No of Comparisons:"<<compares[2]<<endl;
    
    cout << endl <<endl<< "*****************RESULT OF ANALYSIS********************" <<endl<< endl;
    cout<<"=====================In Terms Of Swapping=================="<<endl;
    if(( swaps[0]== swaps[1]) && (swaps[0] == swaps[2])){cout<<"All of the techniques will have the equal number of swaps so can't say which would be best"<<endl;}
      else{if(( swaps[0]<= swaps[1]) && (swaps[0] <= swaps[2])) 
      {
	  
      cout<< "Selection Sort is the best technique"<<endl;
      } 
       else if((swaps[1] <= swaps[0]) && (swaps[1] <= swaps[2])){
       	cout<< "Bubble Sort is the best technique"<<endl;
       	
	   }
	   else if((swaps[2] <= swaps[0]) && (swaps[2] <= swaps[1]))
	   {
	   		cout<< "Insertion Sort is the best technique"<<endl;
       	
		} 
		if(( swaps[0]>= swaps[1]) && (swaps[0] >= swaps[2])) 
      {
	  
      cout<< "Selection Sort is the worst technique"<<endl;
      } 
       else if((swaps[1] >= swaps[0]) && (swaps[1] >= swaps[2])){
       	cout<< "Bubble Sort is the worst technique"<<endl;
       	
	   }
	   else if((swaps[2] >= swaps[0]) && (swaps[2] >= swaps[1]))
	   {
	   		cout<< "Insertion Sort is the worst technique"<<endl;
       	
		} 
      }
	    cout<<endl<<"==================In Terms Of Comparison================"<<endl;
      if(( compares[0]== compares[1]) && (compares[0] == compares[2])){cout<<"All of the techniques will have the equal number of comparisions so can't say which would be best"<<endl;}
else{      if(( compares[0]<= compares[1]) && (compares[0] <= compares[2])) 
      {
	  
      cout<< "Selection Sort is the best technique"<<endl;
      } 
       else if((compares[1] <= compares[0]) && (compares[1] <= compares[2])){
       	cout<< "Bubble Sort is the best technique"<<endl;
       	
	   }
	   else if((compares[2] <= compares[0]) && (compares[2] <= compares[2]))
	   {
	   		cout<< "Insertion Sort is the best technique"<<endl;
       	
		} 
		if(( compares[0]>= compares[1]) && (compares[0] >= compares[2])) 
      {
	  
      cout<< "Selection Sort is the worst technique"<<endl;
      } 
       else if((compares[1] >= compares[0]) && (compares[1] >= compares[2])){
       	cout<< "Bubble Sort is the worst technique"<<endl;
       	
	   }
	   else if((compares[2] >= compares[0]) && (compares[2] >= compares[2]))
	   {
	   		cout<< "Insertion Sort is the worst technique"<<endl;
       	
		} 
		
}
    
}

int main() {
    int choice;
    int n;

    cout << "Select one of the following options" << endl;
    cout << "1: Selection Sort" << endl;
    cout << "2: Bubble Sort" << endl;
    cout << "3: Insertion Sort" << endl;
    cout << "4: Analysis for all Sorting Techniques" << endl;
    cin >> choice;


        cout << "Enter the number of elements you want to sort" << endl;
        cin >> n;
        int arr1[n];

        Sort sort1(n);

    

        switch (choice) {
            case 1:
                sort1.setvalues();
                sort1.SelectionSort();
                sort1.display();
                break;
            case 2:
              sort1.setvalues();
                sort1.BubbleSort();
                sort1.display();
                break;
            case 3:
               sort1.setvalues();
                sort1.InsertionSort();
                sort1.display();
                break;
                case 4:  cout << "Enter the values in the array" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Value " << i << ": ";
            cin >> arr1[i];
            fflush(stdin);
        }
fflush(stdin);
        Analysis(n, arr1);
        break;
            default:
                cout << "Enter the correct option" << endl;
                break;
        }
    return 0;
}
