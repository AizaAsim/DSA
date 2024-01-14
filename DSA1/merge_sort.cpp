#include<iostream>
using namespace std;

void Merge(int arr[], int lb, int mid, int ub) {
    int b[ub - lb + 1];

    int i = lb;
    int j = mid + 1;
    int k = 0; 
    while (i <= mid && j <= ub) {
        if (arr[i] < arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= ub) {
        b[k] = arr[j];
        j++;
        k++;
    }

      for (k = 0; k < ub - lb + 1; k++) {
        arr[lb + k] = b[k];
    }
}

void Merge_Sort(int arr[], int lb, int ub) {
    int mid;
    if (lb < ub) {
        mid = (lb + ub) / 2;
        Merge_Sort(arr, lb, mid);
        Merge_Sort(arr, mid + 1, ub);
        Merge(arr, lb, mid, ub);
    }
}

int main() {
    int arr[9] = {9, 4, 3, 2, 6, 5, 0, 1, 10};
    int arr_size =9; 

    Merge_Sort(arr, 0, arr_size - 1);

    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
