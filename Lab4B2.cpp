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

    void insertLast(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void CondInsert()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data % 2 != 0)
            {
                Node *newNode = new Node(200);
                newNode->next = temp->next;
                temp->next = newNode;

                temp=newNode->next;
            }
            else
            {
                temp = temp->next;
            }
        }
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
};

int main()
{
    LinkedList list;
    int choice, value;

    cout << "Menu" << endl;
    cout << "1. Display" << endl;
    cout << "2. Insert at last" << endl;
    cout << "3. Conditional Insert" << endl;
    cout << "4. Exit" << endl;

    while (true)
    {

        cout << "Enter a Choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.Display();
            break;

        case 2:
            cout << "Enter Value: ";
            cin >> value;
            list.insertLast(value);
            break;

        case 3:
            list.CondInsert();
            break;

        case 4:
            cout << "Program Terminated" << endl;
            return 0;

        default:
            cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}