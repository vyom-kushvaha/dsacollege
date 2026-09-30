#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeginning(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert after a given node
void insertAfter(int given, int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != given) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found!" << endl;
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display all nodes
void display() {
    Node* temp = head;

    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    int choice, value, given;

    do {
        cout << "\n--- Singly Linked List ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After Given Node" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                cout << "Enter node after which to insert: ";
                cin >> given;

                cout << "Enter value: ";
                cin >> value;

                insertAfter(given, value);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}
