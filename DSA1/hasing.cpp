#include<iostream>
using namespace std;
class HashTable{
int arr[7];
int size;
public:
HashTable(int s=0){
size=s;
for(int i=0;i<size;i++){
  arr[i]=0;
}
}
int HashFunction1(int key){
  return key%size;
}
int HashFunction2(int key){
  return (3*key)%7;
}
int LinearProbing(int u){
  for(int i=1;i<size;i++){
    if(arr[u+i] % size==0){
      return (u+i)%size;
    }

  }

}
int DoubleHashing(int u,int v){
for(int i=1;i<size;i++){
  if(arr[u*(v+i)]==0){
    return (u*(v+i));
  }
}

}
int QuadraticProbing(int u){
  for(int i=1;i<size;i++){
    if(arr[u +(i*i)==0])
{
  return (u + (i*i))%size;
  }
}}
void insert_linearprobing(int element){
int index=HashFunction1(element);
if(arr[index]==0){
  arr[index]=element;
  return;
}
index=LinearProbing(index);
arr[index]=element;

}

void insert_quadraticProbing(int element){
int index=HashFunction1(element);
if(arr[index]==0){
  arr[index]=element;
  return;
}
index=QuadraticProbing(index);
arr[index]=element;

}

void insert_DoubleHashing(int element){
int index=HashFunction1(element);
if(arr[index]==0){
  arr[index]=element;
  return;
}
index=DoubleHashing(index,HashFunction2(element));
arr[index]=element;

}
int search_linear(int element){
  int index=HashFunction1(element);
if(element!=arr[index])
 {
  index=LinearProbing(index);
  if(element==arr[index]){
    cout<<"element found"<<endl;
    return index;
  }
  else{
    cout<<"element not found"<<endl;
return -1;    
  }
 }cout<<"element found"<<endl; return index; }
 
int search_quadratic(int element){
  int index=HashFunction1(element);
if(element!=arr[index])
 {
  index=QuadraticProbing(index);
  if(element==arr[index]){
    cout<<"element found"<<endl;
  }
  else{
    cout<<"element not found"<<endl;
  }
 } cout<<"element found"<<endl; return index;}




int search_Double(int element){
  int index=HashFunction1(element);
if(element!=arr[index])
 {
  index=DoubleHashing(index,HashFunction2(element));
  if(element==arr[index]){
    cout<<"element found"<<endl;
  }
  else{
    cout<<"element not found"<<endl;
  }
 } cout<<"element found"<<endl; return index;}
 void delete_linear(int element){
int index=search_linear(element);
if(index==-1){
  cout<<"Deleted"<<endl;
return;
}
arr[index]=0;


}
void display(){
  for(int i=0;i<size;i++){
if(arr[i]!=0){
  cout<<arr[i];
}
cout<<" ";
  }
}
};
int main() {
    HashTable linearHashTable(7);

    // Insert elements using linear probing
    linearHashTable.insert_linearprobing(10);
    linearHashTable.insert_linearprobing(20);
    linearHashTable.insert_linearprobing(30);
    linearHashTable.insert_linearprobing(40);
    linearHashTable.insert_linearprobing(50);

    // Display the hash table
    cout << "Hash Table with Linear Probing: ";
    linearHashTable.display();
    cout << endl;

    // Search for an element using linear probing
    int searchElement = 30;
    int searchIndex = linearHashTable.search_linear(searchElement);
    if (searchIndex != -1) {
        cout << "Element " << searchElement << " found at index " << searchIndex << endl;
    }

    // Delete an element using linear probing
    int deleteElement = 20;
    linearHashTable.delete_linear(deleteElement);

    // Display the hash table after deletion
    cout << "Hash Table after Deletion: ";
    linearHashTable.display();
    cout << endl;

    return 0;
}
