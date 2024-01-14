#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void push(char val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void createWord() {
        if (!head) {
            cout << "The list is empty." << endl;
            return;
        }

        // Traverse the linked list and collect characters in a new linked list
        LinkedList result;
        Node* current = head;
        while (current) {
            result.push(current->data);
            current = current->next;
        }

        // Reverse the order of characters in the new linked list
        LinkedList reversedResult;
        current = result.head;
        while (current) {
            reversedResult.push(current->data);
            current = current->next;
        }

        // Display the result
        reversedResult.display();
    }
};

int main() {
    LinkedList list;
    list.push('C');
    list.push('S');
    list.push('A');
    list.push('R');
    list.push('B');
    list.push('B');
    list.push('E');
    list.createWord();

    return 0;
}
