#include<iostream>
using namespace std;
class Node{public:
  int data;
Node *prev;
Node * next;
Node():data(0),prev(nullptr),next(nullptr){
  
}
};
class Doubly_LL{Node *head;
Node*temp;
public:
void insert(int d1)
  {
    Node *newnode = new Node;
    newnode->data = d1;
    if (head == nullptr)
    {
      newnode->prev=nullptr;
      newnode->next = nullptr;
      head=temp=newnode;

    }
    else
    {
      newnode->prev=temp;
      temp->next=newnode;
      newnode->next = nullptr; 
      temp=newnode;

    }
    
  }
 void display() {
    temp = head;
    if (head == nullptr) {
        cout << "The list is empty" << endl;
    } else {
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
}

void insert_at_beginning(int d1){ Node *newnode = new Node;
    newnode->data = d1;
if(head==nullptr)
{newnode->prev=nullptr;
      newnode->next = nullptr;
      head=temp=newnode;

}
else{
  head->prev=newnode;
  newnode->next=head;
  newnode->prev=nullptr;
  head=newnode;

}
}
void insert_at_end(int d1){
Node *newnode = new Node;
    newnode->data = d1;
if(head==nullptr)
{newnode->prev=nullptr;
      newnode->next = nullptr;
      head=temp=newnode;
}
else{
  while(temp->next!=nullptr){
  
  temp=temp->next;
  }
  temp->next=newnode;
  newnode->prev=temp;
  newnode->next=nullptr;
}
}
int length(){
  int counter=0;
  while(temp!=nullptr){
    counter++;
  temp=temp->next;
  }
  return counter;
}
void insert_at_specific(int pos, int d1) {
    int i = 1;
    temp = head;
    if (pos <= length() && pos >= 0) {
        if (pos == 0) {
            insert_at_beginning(d1);
        } else if (pos == length()) {
            insert_at_end(d1);
        } else {
            Node* newnode = new Node;
            newnode->data = d1;
            while (i < pos) {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
        }
    } else {
        cout << "Invalid position entered" << endl;
    }
}

bool empty(){
  if(head==nullptr){
    
    return true;
  }
  return false;
  
}
void delete_at_beginning(){
if(empty()){
cout<<"The linked list is empty"<<endl;
return;
}
else{
  temp=head;
  head=head->next;
  if (head != nullptr){
  head->prev=nullptr;}
  delete temp;
}
}void delete_at_tail() {
    if (empty()) {
        cout << "The linked list is empty" << endl;
        return;
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }
}

};int main() {
    Doubly_LL doublyLinkedList;
    int choice, value, position;
    bool exitFlag = false;

    while (!exitFlag) {
        cout << "Doubly Linked List Menu" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at specific position" << endl;
        cout << "4. Delete at the beginning" << endl;
        cout << "5. Delete at the end" << endl;
        cout << "6. Display the list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to insert at the beginning: ";
                cin >> value;
                doublyLinkedList.insert_at_beginning(value);
                doublyLinkedList.display();
                break;

            case 2:
                cout << "Enter a value to insert at the end: ";
                cin >> value;
                doublyLinkedList.insert_at_end(value);
                break;

            case 3:
                cout << "Enter the position to insert at: ";
                cin >> position;
                cout << "Enter a value to insert: ";
                cin >> value;
                doublyLinkedList.insert_at_specific(position, value);
                break;

            case 4:
                doublyLinkedList.delete_at_beginning();
                break;

            case 5:
                doublyLinkedList.delete_at_tail();
                break;

            case 6:
                cout << "Doubly Linked List: ";
                doublyLinkedList.display();
                cout << endl;
                break;

            case 7:
                cout << "Exiting the program." << endl;
                exitFlag = true;  // Set the flag to exit the loop
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
