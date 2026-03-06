#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void Display()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void InsertFirst(int value)
    {
        Node *temp = head;
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void CondDelete()
    {
        Node *curr = head;

        while (head != nullptr && head->data % 2 != 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        if (head == nullptr)
        {
            return;
        }
        while (curr->next != nullptr)
        {

            if (curr->next->data % 2 != 0)
            {
                Node *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
};

int main()
{
    LinkedList list;
    int value, choice;

    cout << "Menu" << endl;
    cout << "1. Display" << endl;
    cout << "2. Insert at First" << endl;
    cout << "3. Conditional Delete" << endl;
    cout << "4. Exit" << endl;

    while (true)
    {

        cout << "Enter Choice : " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            list.Display();
            break;
        case 2:
            cout << "Enter Value" << endl;
            cin >> value;
            list.InsertFirst(value);
            break;

        case 3:
            list.CondDelete();
            break;

        case 4:
            cout << "Program Terminated" << endl;
            return 0;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
    return 0;
}