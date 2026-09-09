#include <iostream>
using namespace std;
#define max  10

char queue[max] ;
int i=-1,j=-1;

void enqueuer()
{
    if (j == max - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }
    char ch;
    cout << "Enter character:";
    cin >> ch;
    if (i == -1) i = 0;
    j++;
    queue[j] = ch ;
}
void dequeuer()
{
    if (i == -1 || i > j)
    {
        cout << "Queue Underflow\n";
        return;
    }
    i++;
    if (i > j)
    {
        i = -1;
        j = -1;
    }
}
void display()
{
    if (i == -1 || i > j)
    {
        cout << "Queue is Empty\n";
        return;
    }
    for(int k = i; k <= j; k++ )
    {
        cout << queue[k]<< " ";
    }
    cout << endl;
}
int main()
{
    int choice = 0;

    do
    {
        cout << "\n----- QUEUE MENU -----\n";
        cout << "1. Enqueuer\n";
        cout << "2. Dqueuer\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            enqueuer();
            break;

        case 2:
            dequeuer();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Program Ended.\n";
            break;      

        default:
            cout << "Invalid Choice!\n";
            break;
        }

    } while (choice != 4);

    return 0;
}
