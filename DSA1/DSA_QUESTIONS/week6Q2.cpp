
#include<iostream>
using namespace std;
template <typename T>
class node
{public:
  T data;
node*next;

};
template <typename T>
class LinkedList
{public:
  node<T> *head=nullptr;node<T>*temp;
  node<T>*tail=nullptr;


    void create() {
        int choice = 1;
        temp = head;
        while (choice) {
            node<T>* newnode = new node<T>;
            cout << "Enter the value" << endl;
            cin >> newnode->data;
            newnode->next = nullptr;
            if (head == nullptr) {
                head = temp = newnode;
                tail = newnode;
            } else {
                temp->next = newnode;
                temp = newnode;
                tail = temp;
            }
            cout << "Do you want to add more to the linked list (0/1)" << endl;
            cin >> choice;
        }
    }


void insert_at_head()
{
   node<T>* newnode = new node<T>;
cout<<"Enter the value"<<endl;
cin>>newnode->data;
if(head==nullptr){
  head=newnode;
  tail=newnode;
}
else{
newnode->next=head;
head=newnode;}
} 
void insert_at_end(T value) {
        node<T>* newnode = new node<T>;
        newnode->data = value;
        newnode->next = nullptr;
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
int length()
{ int counter = 0;
  node<T>* current = head; 
  while (current != nullptr)
  {
    current = current->next;
    counter++;
  }
  return counter;}
void Specific_position(int position)
{temp=head;
  int i=1;
node <T>*newnode=new node<T>;
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
{
  if(head==nullptr){cout<<"The list is empty"<<endl;}else{temp=head;
head=head->next;
delete temp;}

}
void delete_at_end()
{temp=head;
  node<T> *prevnode;
  while(temp->next!=nullptr)
  {
    prevnode=temp;
    temp=temp->next;
  }

prevnode->next=nullptr;
delete temp;
}
void delete_at_specific(int position)
{node<T> * nextnode;
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
 node<T>* prevnode = nullptr;
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
bool isempty(){
  if(head==nullptr){
    return true;
  }
  return false;
}
~LinkedList() {
  while (head) {
    temp = head;
    head = head->next;
    delete temp;
  }}
};

template <typename T>
class Queue {
    LinkedList<T> list;

public:
    void enqueue(T x) {
        list.insert_at_end(x);
        cout << x << " enqueued!" << endl;
    }

    void dequeue() {
        list.delete_at_start();
    }

    void display() {
        list.display();
    }

    bool isempty() {
        return list.isempty();
    }
};

int main() {
    int choice, var1, var2, var3;
    float var4;
    double var5;
    char var6;
    string var7;

    Queue<int> intQueue;
    Queue<float> floatQueue;
    Queue<double> doubleQueue;
    Queue<char> charQueue;
    Queue<string> stringQueue;

    do {cout<<endl<<endl<<endl<<endl;
        cout << "\n------------ Menu ------------\n";
        cout << "1.  Enqueue Integer\n";
        cout << "2.  Dequeue Integer\n";
        cout << "3.  Display Integer Queue\n";
        cout << "4.  Enqueue Float\n";
        cout << "5.  Dequeue Float\n";
        cout << "6.  Display Float Queue\n";
        cout << "7.  Enqueue Double\n";
        cout << "8.  Dequeue Double\n";
        cout << "9.  Display Double Queue\n";
        cout << "10. Enqueue Character\n";
        cout << "11. Dequeue Character\n";
        cout << "12. Display Character Queue\n";
        cout << "13. Enqueue String\n";
        cout << "14. Dequeue String\n";
        cout << "15. Display String Queue\n";
        cout << "16. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
cout<<endl<<endl<<endl<<endl;
        switch (choice) {
            case 1:
                cout << "Enter an integer to enqueue: ";
                cin >> var1;
                intQueue.enqueue(var1);
                break;
            case 2:
                intQueue.dequeue();
                break;
            case 3:
                cout << "Integer Queue:\n";
                intQueue.display();
                break;
            case 4:
                cout << "Enter a float to enqueue: ";
                cin >> var4;
                floatQueue.enqueue(var4);
                break;
            case 5:
                floatQueue.dequeue();
                break;
            case 6:
                cout << "Float Queue:\n";
                floatQueue.display();
                break;
            case 7:
                cout << "Enter a double to enqueue: ";
                cin >> var5;
                doubleQueue.enqueue(var5);
                break;
            case 8:
                doubleQueue.dequeue();
                break;
            case 9:
                cout << "Double Queue:\n";
                doubleQueue.display();
                break;
            case 10:
                cout << "Enter a character to enqueue: ";
                cin >> var6;
                charQueue.enqueue(var6);
                break;
            case 11:
                charQueue.dequeue();
                break;
            case 12:
                cout << "Character Queue:\n";
                charQueue.display();
                break;
            case 13:
                cout << "Enter a string to enqueue: ";
                cin >> var7;
                stringQueue.enqueue(var7);
                break;
            case 14:
                stringQueue.dequeue();
                break;
            case 15:
                cout << "String Queue:\n";
                stringQueue.display();
                break;
            case 16:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 16);

    return 0;
}
