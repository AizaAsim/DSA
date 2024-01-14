/*Implement a singly linked list class with the following functions:
a) Insert a node at head
b) Insert a node at tail/end/back
c) Insert a node at any position
d) Delete a node by value
e) Delete head
f) Delete tail
g) Delete a node at any position.*/
#include<iostream>
using namespace std;
class node
{public:
  int data;
node*next;

};
class LinkedList
{public:
  node *head=nullptr;node*temp;


  void create()
  {

  int choice = 1; temp = head;
  while (choice) {
    node* newnode = new node;
    cout << "Enter the value" << endl;
    cin >> newnode->data;
    newnode->next=nullptr;
    if (head == nullptr) {
      head = temp = newnode;
    }
    else {
      temp->next = newnode;
      temp = newnode;
    }
    cout << "Do you want to add more to the linked list (0/1)" << endl;
    cin >> choice;
  }


  }

void insert_at_head()
{ node *newnode=new node;
cout<<"Enter the value"<<endl;
cin>>newnode->data;
newnode->next=head;
head=newnode;
}
void insert_at_end(){
  node *newnode=new node;
cout<<"Enter the value"<<endl;
cin>>newnode->data;
temp=head;
while(temp->next!=nullptr)
{
  temp =temp->next;
}
temp->next=newnode;
newnode->next=nullptr;
}
int length()
{ int counter = 0;
  node* current = head; // Use a separate pointer to traverse the list
  while (current != nullptr)
  {
    current = current->next;
    counter++;
  }
  return counter;}
void Specific_position(int position)
{temp=head;
  int i=1;
node *newnode=new node;
cout<<"Enter the value"<<endl;
cin>>newnode->data;
if(position<length()){
while(i<position-1){
temp=temp->next;
  
  i++;}
  newnode->next=temp->next;
  temp->next=newnode;

}

else{
cout<<"Invalid Position"<<endl;
}
}
void delete_at_start()
{temp=head;
head=head->next;
delete temp;

}
void delete_at_end()
{temp=head;
  node *prevnode;
  while(temp->next!=nullptr)
  {
    prevnode=temp;
    temp=temp->next;
  }

prevnode->next=nullptr;
delete temp;
}
void delete_at_specific(int position)
{node * nextnode;
int i=1;
temp=head;
if(position<length()){
while(i<position-1){
temp=temp->next;
  
  i++;}

}
else{
cout<<"Invalid Position"<<endl;
}

nextnode=temp->next;
temp->next=nextnode->next;
delete nextnode;
}
void display()
{temp=head;
  while(temp!=nullptr)
  {cout<<temp->data<<endl;
    temp=temp->next;
  }
}
void delete_by_value(int d)
{temp=head;
 node* prevnode = nullptr;
 if (temp != nullptr && temp->data == d) {
    head = temp->next;
    delete temp;
    return;
  }
  while(temp!=nullptr)
{
if(temp->data==d){
prevnode->next = temp->next;
      delete temp;
      return;
}
prevnode=temp;
temp=temp->next;
}

}
~LinkedList() {
  while (head) {
    temp = head;
    head = head->next;
    delete temp;
  }}
};
int main()
{
  LinkedList l1;
  l1.create();
  l1.display();
  int choice=1;
  int option;
  while(choice){
    cout<<"Enter the desired function"<<endl<<"1:Inserting at head"<<endl<<"2:Inserting at tail"<<endl<<"3:Inserting at a specified position"<<endl<<"4:Delete from head"<<endl<<"5:Delete from tail"<<endl<<"6:Delete at a specific position"<<endl<<"7:Delete By Value"<<endl;
    cin>>option;
    switch(option){
      case 1:l1.insert_at_head();
      l1.display();
      break;
      case 2:l1.insert_at_end();
      l1.display();
      break;
      case 3:
      l1.Specific_position(3);
      l1.display();
      break;
  case 4:l1.delete_at_start();
      l1.display();
      break;
      case 5:l1.delete_at_end();
      l1.display();
      break;
      case 6:
      l1.delete_at_specific(5);
      l1.display();
      break;
      case 7:l1.delete_by_value(5);
      l1.display();
default:cout<<"Enter the correct choice"<<endl;

    }
    cout<<"Do you want to continue (0/1)"<<endl;
    cin>>choice;
  }
}