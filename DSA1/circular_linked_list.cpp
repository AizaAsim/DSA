#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;

  Node()
  {
    data = 0;
    next = nullptr;
  }
};
class linkedlist
{
  Node *head = nullptr;
  Node *tail = nullptr;
  Node *temp;

public:
  void insert(int d1)
  {
    Node *newnode = new Node;
    newnode->data = d1;
    if (head == nullptr)
    {
      head = tail = newnode;
      tail = newnode;
    }
    else
    {
      tail->next = newnode;
      tail = newnode;
    }
    tail->next = head;
  }void display() {
    temp = head;
    do {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != head);
}

  void insert_at_beginning(int d1)
  {
    Node *newnode = new Node;
    newnode->data = d1;
    if (head == nullptr)
    {
      head = tail = newnode;
      // tail=newnode;
      newnode->next = head; // connecting the node with itself bcoz its a circular ll
    }
    else
    {
      newnode->next = head;
      head = newnode;
      tail->next = head;
    }
  }
  void insert_at_end(int d1)
  {

    Node *newnode = new Node;
    newnode->data = d1;
    if (head == nullptr)
    {
      head = tail = newnode;

      newnode->next = head;
    }
    else
    {
      tail->next = newnode;

      tail = newnode;
      tail->next = head;
    }
  }int length() {
    int counter = 0;
    Node *temp = head; 

    do {
        temp = temp->next;
        counter++;
    } while (temp != head);

    return counter;
}

  void insert_at_position(int position, int d1)
  {
    int i = 1;
    temp = head;
    Node *newnode = new Node;
    newnode->data = d1;
    if (position > length() || position < 0)
    {
      cout << "Invalid position" << endl;
    }
    else
    {
      if (position == 0)
      {

        newnode->next = head;
        head = newnode;
        tail->next = head;
      }
      else if (position == length())
      {
        newnode->next = head;
        tail->next = newnode;
      }
      else
      {

        while (i < position)
        {
          temp = temp->next;
          i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
      }
    }
  }

  void delete_at_beginning()
  {
    if (head == nullptr)
    {
      cout << "The list is empty" << endl;
      return;
    }
    temp = head;
    if (head == tail)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {

      head = head->next;

      tail->next = head;
    }
    delete temp;
  }
  void delete_at_end(){
    if (head == nullptr)
    {
      cout << "The list is empty" << endl;
      return;
    }
    if (head == tail)
    {temp=head;
      head = nullptr;
      tail = nullptr;
      delete temp;
    }
    else{
    Node *ptr;
    ptr=tail;
    temp=head;
    while(temp->next!=tail){
      temp=temp->next;
    }
    temp->next=head;
    tail=temp;
    delete ptr;
  }}
  void delete_at_position(int position){
   Node*prev; 
    int i = 0;
    temp = head;
    
    if (position >= length() || position < 0) {
        cout << "Invalid position" << endl;
    } else {
        if (position == 0) { 
            if (head == tail) { 
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                tail->next = head;
                delete temp;
            }
        } else {
            while (i < position) {
                prev = temp;
                temp = temp->next;
                i++;
            }
            prev->next = temp->next;
            if (temp == tail) {
                tail = prev; 
            }
            delete temp;
        }
    }
  }

};

int main()
{
  linkedlist l1;
  l1.insert(6);
  l1.insert(5);
  l1.insert(4);
  l1.insert(3);
  l1.insert(2);
  l1.insert(1);
  l1.insert(0);
  l1.display();
  int choice=1;
  int option;
  while(choice){
    cout<<"Enter the desired function"<<endl<<"1:Inserting at head"<<endl<<"2:Inserting at tail"<<endl<<"3:Inserting at a specified position"<<endl<<"4:Delete from head"<<endl<<"5:Delete from tail"<<endl<<"6:Delete at a specific position"<<endl;  cin>>option;
    switch(option){
      case 1:l1.insert_at_beginning(99);
      l1.display();
      break;
      case 2:l1.insert_at_end(88);
      l1.display();
      break;
      case 3:
      l1.insert_at_position(3,66);
      l1.display();
      break;
  case 4:l1.delete_at_beginning();
      l1.display();
      break;
      case 5:l1.delete_at_end();
      l1.display();
      break;
      case 6:
      l1.delete_at_position(5);
      l1.display();
      break;
     
default:cout<<"Enter the correct choice"<<endl;

    }
    cout<<"Do you want to continue (0/1)"<<endl;
    cin>>choice;
  }

}