#include<iostream>
#include<vector>
using namespace std;

class heap {
public:
    int *arr;
    int n;
    int size=0;

    heap(int n1) {
        n = n1;
        arr = new int[n];
        arr[0] = -1;
    }

    void insert(int val) {
        if(size < n) {
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1 && arr[index] > arr[index/2]) {
                swap(arr[index], arr[index/2]);
                index = index/2;
            }
        } else {
            cout << "Not enough space" << endl;
        }
    }

    void delete_max_from_heap() {
        if(size == 0) {
            cout << "Heap is empty" << endl;
            return;
        } else {
            arr[1] = arr[size];
            size--;

            int i = 1;

            while(i <= size) {
                int leftindex = 2 * i;
                int rightindex = 2 * i + 1;
                int maxindex = i;

                if(leftindex <= size && arr[i] < arr[leftindex]) {
                    maxindex = leftindex;
                }

                if(rightindex <= size && arr[maxindex] < arr[rightindex]) {
                    maxindex = rightindex;
                }

                if(maxindex != i) {
                    swap(arr[i], arr[maxindex]);
                    i = maxindex;
                } else {
                    return;
                }
            }
        }
    }
 void delete_min_from_heap() {
        if(size == 0) {
            cout << "Heap is empty" << endl;
            return;
        } else {
            arr[1] = arr[size];
            size--;

            int i = 1;

            while(i <= size) {
                int leftindex = 2 * i;
                int rightindex = 2 * i + 1;
                int maxindex = i;

                if(leftindex <= size && arr[i] > arr[leftindex]) {
                    maxindex = leftindex;
                }

                if(rightindex <= size && arr[maxindex] > arr[rightindex]) {
                    maxindex = rightindex;
                }

                if(maxindex != i) {
                    swap(arr[i], arr[maxindex]);
                    i = maxindex;
                } else {
                    return;
                }
            }
        }
    }
int peek(){
return arr[1];
}
    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};
void heapify_max(int arr[],int n,int i){

int largest=i;
int left=2*i;
int right=2*i+1;
if(left<n && arr[largest]<arr[left]){
  largest=left;
}
if(right<n && arr[largest]<arr[right])
{
  largest=right;
}
if(largest!=i){
  swap(arr[largest],arr[i]); i=largest;
}
else{
  return;
}
}

void heapify_min(vector<int>&arr,int n,int i){
int smallest=i;
int left=2*i+1;
int right=2*i+2;
if(left<n && arr[smallest]>arr[left]){
  smallest=left;
}
if(right<n && arr[smallest]>arr[right]){
  smallest=right;
}
if(smallest!=i){
  swap(arr[smallest],arr[i]);
  heapify_min(arr,n,smallest);


}

else{
  return;
}
}
vector<int> buildminheap(vector<int> & arr,int n){
  for(int i=n/2-1;i>=0;i--){
heapify_min(arr,n,i);
  }
  return arr;
}
void heap_sort(int arr[],int n){
  int size=n;
  while(size>1){swap(arr[size],arr[1]);
  size--;
  heapify_max(arr,size,1);}

}

int main() {
    heap h1(10);

    h1.insert(63);
    h1.insert(60);
    h1.insert(65);
    h1.insert(55);
    h1.insert(67);

    h1.print();
    
    h1.delete_max_from_heap();
    
    h1.print();


int arr[7]={-1,65,78,23,99,10,55};
int n=7;
for(int i=n/2;i>0;i--){
  heapify_max(arr,7,i);
}
for(int i=1;i<n;i++){
  cout<<arr[i]<<" ";
}
cout<<endl;
cout<<"min heap build"<<endl;
 vector<int> arr1 = {23, 10, 55, 78, 99, -1, 65};
    int n1 = arr1.size();

    cout << "Original array: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    // Applying heapify_min to the array
    heapify_min(arr1, n1, 0);

    cout << "Array after heapify_min: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    // Building a min heap
    vector<int> minHeap = buildminheap(arr1, n1);

    cout << "Min Heap: ";
    for (int num : minHeap) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}