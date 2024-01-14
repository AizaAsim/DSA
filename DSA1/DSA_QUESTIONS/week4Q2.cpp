#include<iostream>
using namespace std;
/*Create two doubly link lists, say L and M . List L should contain all even elements from 2 to
10 and list M should contain all odd elements from 1 to 9. Create a new list N by
concatenating list L and M.*/

class Node {
public:
  int data;
  Node* next;
  Node* prev;
  Node() {
    data = 0;
    next = nullptr;
    prev = nullptr;
  }
};

class double_ll {
  Node *head, *temp1;
public:
  double_ll() {
    head = nullptr;
    temp1 = nullptr;
  }

  void insert(int val) {
    Node* newnode = new Node;
    newnode->data = val;

    if (head == nullptr) {
      head = temp1 = newnode;
    }
    else {
      newnode->prev = temp1;
      temp1->next = newnode;
      temp1 = newnode;
    }
  }

  void insert_at_head(int val) {
    Node* newnode = new Node;
    newnode->data = val;

    if (head == nullptr) {
      head = temp1 = newnode;
    }
    else {
      newnode->prev = nullptr; // Set prev to nullptr for the new head
      newnode->next = head;
      head->prev = newnode;
      head = newnode;
    }
  }

  void insert_at_pos(int x, int val) {
    Node* newnode = new Node;
    newnode->data = val;

    Node* temp = head;

    if (head == nullptr) {
      head = temp1 = newnode;
    }
    else {
      if (x == 1) {
        newnode->prev = nullptr; // Set prev to nullptr for the new head
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
      }
      else {
        int i = 1;
        temp = head;
        while (i < x - 1) {
          temp = temp->next;
          i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        if (temp->next != nullptr) {
          temp->next->prev = newnode;
        }
        temp->next = newnode;
      }
    }
  }void delete_at_start() {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
    }
    else {
        Node* del = head;
        if (head->next != nullptr) {
            head->next->prev = nullptr;
            head = head->next;
        }
        else {
            head = nullptr;
        }
        delete del;
    }
}


  void delete_at_end(){
  if(head==nullptr){
      cout<<"The list is empty"<<endl;

    }
    else{ Node * del;
    Node *temp=head;
    while(temp->next!=nullptr)
{
  temp=temp->next;
}  
del=temp;

temp->prev->next=nullptr;

delete temp;
  
  
    }

  }
  void delete_at_pos(int x){
if(head==nullptr){
      cout<<"The list is empty"<<endl;

    }
    else{
   if(x==1){
      delete_at_start();
    }
  else{Node*del;
Node*temp=head;
    int i=1;
    while(i<x-1){
      temp=temp->next;
    }
del=temp;
temp->prev->next=temp->next;
temp->next->prev=temp->prev ;
delete del;
  }

    }
  }
  void display()
{
  Node*temp;
   temp=head;
  while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
  }
}
Node* gethead(){
  return head;
}


};
int main() {
    double_ll my_list;

    // Insert elements
    my_list.insert(10);
    my_list.insert(20);
    my_list.insert(30);

    // Display the original list
    cout << "Original List:" << endl;
    my_list.display();

    // Delete at start
    my_list.delete_at_start();
    cout << "List after deleting at start:" << endl;
    my_list.display();

    // Delete at end
    my_list.delete_at_end();
    cout << "List after deleting at end:" << endl;
    my_list.display();

    // Insert more elements
    my_list.insert(40);
    my_list.insert(50);

    // Display the modified list
    cout << "List after re-inserting elements:" << endl;
    my_list.display();

    // Delete at position
    my_list.delete_at_pos(2);
    cout << "List after deleting at position 2:" << endl;
    my_list.display();

    return 0;
}
