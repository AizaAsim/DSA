#include<iostream>
using namespace std;
/*struct node{
  int data;
  node * next;
};
struct node*temp,*newnode,*head;
void display()
{temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data;
    temp=temp->next;
  }
}

int main(){
head=NULL;
int choice;
while(choice)
{
newnode=(struct node*)malloc(sizeof(struct node));
cout<<"Enter the value"<<endl;
cin>>newnode->data;
if(head==NULL)
{
  head=temp=newnode;//head se node connect hogaya hai and temp me bhi newnode ka adress agaya hai so that newnodes could be manipulated and connected

}
else{
  temp->next=newnode;
  temp=newnode;
}
cout<<"Enter the choice"<<endl;
cin>>choice;


}
display();
}
struct node
{
  int data;
  node *next;
};
node *temp;
void display()
{
while(temp!=NULL)
{
  
  cout<<temp->data;
  temp=temp->next;
}  
}
int main()
{
  node *head,*newnode;
  head=NULL;
  int choice;
  while(choice)
  {
     newnode=(struct node*)malloc(sizeof(struct node));
  cout<<"Enter the value"<<endl;
  cin>>newnode->data;
  if(head==NULL)
  {
   head= temp=newnode;
  }
else{
temp->next=newnode;
temp=newnode;


}
cout<<"choice"<<endl;
cin>>choice;
  }
display();
}



struct node {
int data;
node * next;
};
node * newnode,*temp,*head;
void create()
{
  newnode=(struct node*)malloc(sizeof(struct node));
  cout<<"Enter the value"<<endl;
  cin>>newnode->data;

}
void display()
{temp=head;
  while(temp!=NULL)
  {
cout<<temp->data;
temp=temp->next;
  }
}
void insert_at_head(){
create();
newnode->next=head;
head=newnode;
}
void insert_at_end()
{
  create();
  temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }

  temp->next=newnode;
}
int length()
{int counter=0;
temp=head;
  while(temp!=NULL)
  {temp=temp->next;
counter++;
  }
return counter;

}
void enter_at_point()
{create();
int i=1,position;
cout<<"Enter the position you want to insert at"<<endl;
cin>>position;
if(position<length()){
while(i<position)
{
temp=temp->next;  
i++;
}
newnode->next=temp->next;
temp->next=newnode;

}
else{cout<<"Invalid position"<<endl;}
}
int main(){head=NULL;int choice;
while(choice)
{
create();
 if(head==NULL)
 {
  head=temp=newnode;
 } 
 else{
  temp->next=newnode;
  temp=newnode;

 }
 cout<<"Choice"<<endl;
 cin>>choice;

}
display();
insert_at_head();
display();
insert_at_end();
display();
enter_at_point();
display();

}
*/#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *newnode, *temp, *head;

void create() {
    newnode = new node;
    cout << "Enter the value" << endl;
    cin >> newnode->data;
    newnode->next = nullptr;
}

void display(node* start) {
    temp = start;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int length() {
    int counter = 0;
    temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        counter++;
    }
    return counter;
}
void insert_at_head() {
    create();
    newnode->next = head;
    head = newnode;
}

void insert_at_end() {
    create();
    if (head == nullptr) {
        head = newnode;
    }
    else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void enter_at_point() {
    create();
    int i = 1, position;
    cout << "Enter the position you want to insert at" << endl;
    cin >> position;
    if (position < 1 || position > length() + 1) {
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 1) {
        newnode->next = head;
        head = newnode;
    }
    else {
        temp = head;
        while (i < position - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}


int main() {
    head = nullptr;
    int choice;
    while (true) {
        cout << "1. Insert at head\n2. Insert at end\n3. Insert at a specific position\n4. Display\n0. Exit" << endl;
        cin >> choice;
        if (choice == 0) {
            break;
        }
        switch (choice) {
            case 1:
                insert_at_head();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                enter_at_point();
                break;
            case 4:
                display(head);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}







