#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = nullptr;
    }
};

class linkedlist {
    bool flag = false;
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *temp;
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    Node *tail1 = nullptr;
    Node *tail2 = nullptr;

public:

    void insert(int d1) {
        Node *newnode = new Node;
        newnode->data = d1;

        if (head == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }

        tail->next = head;
    }

    void split() {
        Node *temp = head;
        head1 = head;
        int mid = length() / 2;

        for (int i = 0; i < mid; i++) {
            tail1 = temp;
            temp = temp->next;
        }

        tail1->next = head1;
        head2 = temp;
        tail2 = tail;

        flag = true;
    }

    void display() {cout<<endl<<endl<<"=================================================================================="<<endl<<endl;
        temp = head;
        if (flag == true) {
            temp = head1;
          cout << endl <<endl<<endl<< "*************************************First half**********************************" << endl;
        }

        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout<<head->data;

        if (flag == true) {
            temp = head2;
            cout << endl<< endl<<"***********************************Second half***********************************" << endl;

            do {
                cout << temp->data << "->";
                temp = temp->next;
            } while (temp != head);
            cout<<head2->data;
        }
cout<<endl<<"=================================================================================="<<endl;
        cout << endl;
    }

    void insert_at_beginning() {
        int d1;
        cout << "Enter the value to insert at the beginning: ";
        cin >> d1;

        Node *newnode = new Node;
        newnode->data = d1;

        if (head == nullptr) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
    }

    void insert_at_end() {
        int d1;
        cout << "Enter the value to insert at the end: ";
        cin >> d1;

        Node *newnode = new Node;
        newnode->data = d1;

        if (head == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }

    void insert_at_position() {
        int d1, position;
        cout << "Enter the value to insert: ";
        cin >> d1;
        cout << "Enter the position to insert at: ";
        cin >> position;

        int i = 1;
        temp = head;
        Node *newnode = new Node;
        newnode->data = d1;

        if (position > length() || position < 0) {
            cout << "Invalid position" << endl;
        } else {
            if (position == 0) {
                newnode->next = head;
                head = newnode;
                tail->next = head;
            } else if (position == length()) {
                newnode->next = head;
                tail->next = newnode;
            } else {
                while (i < position) {
                    temp = temp->next;
                    i++;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
    }

    void delete_at_beginning() {
        if (head == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }

        temp = head;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            tail->next = head;
        }

        delete temp;
    }

    void delete_at_end() {
        if (head == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }

        if (head == tail) {
            temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        } else {
            Node *ptr;
            ptr = tail;
            temp = head;

            while (temp->next != tail) {
                temp = temp->next;
            }

            temp->next = head;
            tail = temp;

            delete ptr;
        }
    }

    void delete_at_position() {
        int position;
        cout << "Enter the position to delete from: ";
        cin >> position;

        Node *prev;
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
    int length() {
    int counter = 0;
    Node *temp = head; 

    do {
        temp = temp->next;
        counter++;
    } while (temp != head);

    return counter;
}
};

int main() {
    linkedlist l1;

    l1.insert(6);
    l1.insert(5);
    l1.insert(4);
    l1.insert(3);
    l1.insert(2);
    l1.insert(0);
    l1.insert(1);

    cout << "Initial Circular Linked List:" << endl;
    l1.display();

    int choice = 1;
    int option;

    while (choice) {
        cout << "Enter the desired function:" << endl
             << "1: Insert at head" << endl
             << "2: Insert at tail" << endl
             << "3: Insert at a specified position" << endl
             << "4: Delete from head" << endl
             << "5: Delete from tail" << endl
             << "6: Delete at a specific position" << endl
             << "7: Split the circular linked list into two halves" << endl
             << "0: Exit" << endl;
cout<<endl<<endl<<"Your Choice:";
        cin >> option;
cout<<endl<<endl<<"=================================================================================="<<endl<<endl<<endl;
        switch (option) {
            case 1:
                l1.insert_at_beginning();
                l1.display();
                break;
            case 2:
                l1.insert_at_end();
                l1.display();
                break;
            case 3:
                l1.insert_at_position();
                l1.display();
                break;
            case 4:
                l1.delete_at_beginning();
                l1.display();
                break;
            case 5:
                l1.delete_at_end();
                l1.display();
                break;
            case 6:
                l1.delete_at_position();
                l1.display();
                break;
            case 7:
                cout << "SPLITTING THE CIRCULAR LINKED LIST INTO TWO HALVES" << endl << endl << endl;
                l1.split();
                l1.display();
                break;
            case 0:
                choice = 0;
                break;
            default:
                cout << "Enter the correct choice" << endl;
        }

        cout << "Do you want to continue? (0/1)" << endl;
        cin >> choice;
    }

    return 0;
}
