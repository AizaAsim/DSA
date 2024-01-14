
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
  node* current = head; 
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
void reverse()
{
  node *prevnode,*nextnode,*currentnode;
  prevnode=nullptr;
  nextnode=currentnode=head;
  while(nextnode!=nullptr){
    nextnode=nextnode->next;
    currentnode->next=prevnode;
    prevnode=currentnode;
    currentnode=nextnode;
  }
  head=prevnode;
}
void sort()
{
    if (!head || !head->next) {
        return;
    }

    node* n1 = new node;
    bool swapped;

    do {
        swapped = false;
        temp = head;

        while (temp->next != nullptr) {
            if (temp->data > temp->next->data) {
                n1->data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = n1->data;
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);

    delete n1;


}
void duplicate()
{
    if (!head || !head->next) {
        cout << "List is empty or has only one element. No duplicates can exist." << endl;
        return;
    }
  
    node* current = head;

    while (current != nullptr) {
        node* ptr = current->next;

        while (ptr != nullptr) {
            if (current->data == ptr->data) {
                cout << "Duplicate found: " << current->data << endl;
            }
            ptr = ptr->next;
        }

        current = current->next;
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
  cout<<"List:"<<endl;
l1.display();
  bool choice=true;
  int option;
  while(choice)
 { cout<<"Enter the option you want"<<endl;
cout<<"1:Reverse a list"<<endl<<"2:Sort the list"<<endl<<"3:Find a duplicate"<<endl;
cin>>option;
switch(option)
{
  case 1:l1.reverse();
  l1.display(); 
  break;
   case 2:l1.sort();
  l1.display(); 
  break;
   case 3:l1.duplicate();
  break;
  default:cout<<"Enter a valid option"<<endl;

}
cout<<"Do you want to continue (0/1)"<<endl;
cin>>choice;
}

}