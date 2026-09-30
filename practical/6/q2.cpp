#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Delete first node
void deleteFirst() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;

    cout << "First node deleted." << endl;
}

// Delete last node
void deleteLast() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // If there is only one node
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    cout << "Last node deleted." << endl;
}

// Delete node after a given node
void deleteAfter(int given) {
    Node* temp = head;

    while (temp != NULL && temp->data != given) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Node not found or no node after it!" << endl;
        return;
    }

    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;

    cout << "Node deleted." << endl;
}

// Display all nodes
void display() {
    Node* temp = head;

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Singly Linked List ---" << endl;
        cout << "1. Delete First Node" << endl;
        cout << "2. Delete Last Node" << endl;
        cout << "3. Delete Node After Given Node" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                deleteFirst();
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                int given;
                cout << "Enter node after which to delete: ";
                cin >> given;
                deleteAfter(given);
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
