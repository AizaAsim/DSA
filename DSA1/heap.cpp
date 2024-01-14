#include<iostream>
using namespace std;

class heap {
public:
    int *arr;
    int size = 0;
    int n;

    heap(int n) {
        this->n = n;
        arr = new int[n];
arr[0]=-1;
    }

    void insert(int val) {
        if (n > size) {
          size = size + 1;
            int index = size;
            
            arr[index] = val;
            while (index > 1 && arr[index] > arr[index / 2]) {
                swap(arr[index], arr[index / 2]);
                index = index / 2;
            }
        }
        else {
            cout << "No space" << endl;
            return;
        }
    }
    void delete_from_heap(){
      if(size==0){
        cout<<"nothing to delete"<<endl;
return;
      }
      arr[1]=arr[size];
      size--;
      int i=1;  while (i <= size) {
    int leftindex = 2 * i;
    int rightindex = 2 * i + 1;

    int maxIndex = i;

    if (leftindex <= size && arr[i] < arr[leftindex]) {
        maxIndex = leftindex;
    }

    if (rightindex <= size && arr[maxIndex] < arr[rightindex]) {
        maxIndex = rightindex;
    }

    if (maxIndex != i) {
        swap(arr[i], arr[maxIndex]);
        i = maxIndex;
    } else {
        return;
    }
}
}

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
  



};
void heapify_max(int arr[],int n,int i){

  int largest=i;
  int left =2*i;
  int right =2*i+1;
  if(left<n && arr[largest]<arr[left]){
    largest=left;
  }
  else if(right<n && arr[largest]<arr[right]){
    largest=right;
  }
if(largest !=i){
  swap(arr[largest],arr[i]);
  heapify_max(arr,n,largest);
}  

}void heapify_min(int arr[], int n, int i) {
    int smallest = i; // from 0;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify_min(arr, n, smallest);
    }
}
void heapsort(int arr[],int n){
int size=n;
while(size>1){
  swap(arr[size],arr[1]);
  size--;
  heapify_max(arr,size,1);
}
}

int main() {
    heap h1(9);
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    h1.print();
h1.delete_from_heap();
h1.print();
    

int arr[6]={-1,54,53,55,52,50};
int n=5;
/*for(int i=n/2 ; i>0;i--){
heapify_max(arr,n,i);
}
for(int i=1;i<=n;i++){
  cout<<arr[i]<<" ";
  
}
cout<<endl;
return 0;

*/
for(int i=n/2;i>=0;i--){
  heapify_min(arr,n,i);
}
for(int i=1;i<=n;i++){
  cout<<arr[i]<<" ";
  
}
heapsort(arr,n);

}
