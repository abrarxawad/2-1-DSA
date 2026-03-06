

#include <bits/stdc++.h>
using namespace std;

class stackk
{
public:
    int *arr;
    int capacity;
    int topindx;

    stackk(int size = 1000)
    {
        capacity = size;
        arr = new int[size];
        topindx = -1;
    }
    ~stackk()
    {
        delete[] arr;
    }
    int push(int x)
    {
        if (topindx >= capacity - 1)
        {
            cout << "Stack overflow" << endl;
            return -1;
        }
        return arr[topindx++] = x;
    }

    bool isEmpty()
    {
        return topindx == -1;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return arr[--topindx];
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[topindx];
    }
};

int main()
{
    stackk st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.pop();

    cout << st.top() << endl;
    st.pop();
    cout<<st.top()<<endl;
    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

class arr_stack
{

public:
    int *arr;
    int cap;
    int topindx;

    arr_stack(int size = 100)
    {
        cap = size;
        arr = new int[cap];
        topindx = -1;
    }

    int push(int x)
    {
        if (topindx >= cap - 1)
        {
            cout << "Invalid" << endl;
            return -1;
        }
        return arr[topindx++] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Invalid" << endl;
            return -1;
        }
        return arr[topindx--];
    }

    int top()
    {
        return arr[topindx];
    }

    bool isEmpty()
    {
        return topindx == -1;
    }
};

int main()
{

    arr_stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.pop();
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.top() << endl;
}
    */