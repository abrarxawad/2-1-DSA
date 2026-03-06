#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int d)
    {
        val = d;
        next = NULL;
    }
};

class Linkedlist
{
public:
    Node *head;
    int size;

    Linkedlist()
    {
        head = NULL;
        size = 0;
    }
    void push(int x)
    {
        Node *element = new Node(x);

        element->next = head;
        head = element;
        size++;
    }

    int pop(){
        if(head==NULL){
            return -1;
        }

        int value= head->val;
        Node *temp=head;
        head=head->next;
        delete temp;
        size--;

        return value;
    }

    int top(){
        if(head==NULL){
            return -1;
        }
        return head->val;
    }

    bool isempty(){
        return (size==0);
    }
};

int main()
{   
    Linkedlist st;

    st.push(5);
    st.push(6);
    st.push(7);

    cout<<st.pop()<<endl;;
    cout<<st.top()<<endl;

    return 0;
}