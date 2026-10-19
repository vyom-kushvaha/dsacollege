
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* tail = NULL;

void insertBeg(int x) {
    Node* p = new Node{x, NULL};

    if (tail == NULL) {
        tail = p;
        p->next = p;
    } else {
        p->next = tail->next;
        tail->next = p;
    }
}

void insertEnd(int x) {
    insertBeg(x);
    tail = tail->next;
}

void insertAfter(int key, int x) {
    if (tail == NULL) return;

    Node* t = tail->next;

    do {
        if (t->data == key) {
            Node* p = new Node{x, t->next};
            t->next = p;

            if (t == tail)
                tail = p;

            return;
        }
        t = t->next;
    } while (t != tail->next);

    cout << "Node not found\n";
}

void deleteBeg() {
    if (tail == NULL) return;

    Node* head = tail->next;

    if (head == tail) {
        delete tail;
        tail = NULL;
    } else {
        tail->next = head->next;
        delete head;
    }
}

void deleteEnd() {
    if (tail == NULL) return;

    if (tail->next == tail) {
        delete tail;
        tail = NULL;
        return;
    }

    Node* t = tail->next;

    while (t->next != tail)
        t = t->next;

    t->next = tail->next;
    delete tail;
    tail = t;
}

void deleteAfter(int key) {
    if (tail == NULL) return;

    Node* t = tail->next;

    do {
        if (t->data == key) {
            Node* p = t->next;

            if (p == t) {
                delete p;
                tail = NULL;
            } else {
                t->next = p->next;

                if (p == tail)
                    tail = t;

                delete p;
            }
            return;
        }
        t = t->next;
    } while (t != tail->next);

    cout << "Node not found\n";
}

void display() {
    if (tail == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* t = tail->next;

    do {
        cout << t->data << " -> ";
        t = t->next;
    } while (t != tail->next);

    cout << "(back to first node)\n";
}

int main() {
    int ch, x, key;

    do {
        cout << "\n1.Insert Beginning  2.Insert End";
        cout << "\n3.Insert After      4.Delete First";
        cout << "\n5.Delete Last       6.Delete After";
        cout << "\n7.Display           8.Exit";
        cout << "\nChoice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> x;
                insertBeg(x);
                break;
            case 2:
                cin >> x;
                insertEnd(x);
                break;
            case 3:
                cin >> key >> x;
                insertAfter(key, x);
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                cin >> key;
                deleteAfter(key);
                break;
            case 7:
                display();
                break;
        }
    } while (ch != 8);

    return 0;
}
