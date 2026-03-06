#include <bits/stdc++.h>
using namespace std;

class arr_queue
{

public:
    int *arr;
    int start, end;
    int cursize, maxsize;

    arr_queue(){
        arr = new int[10];
        start=-1;
        end=-1;
        cursize=0;
        maxsize=10;
    }

    void push(int x){
        if(cursize==maxsize){
            cout<<"queue full"<<endl;
            exit(1);
        }
        if(end==-1){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%maxsize;
        }
        arr[end]=x;
        cursize++;
    }
    int pop(){
        if(start==-1){
            cout<<"queue is empty"<<endl;
            exit(1);
        }
        int popped=arr[start];

        if(cursize==1){
            start =-1;
            end=-1;
        }else{
            start=(start+1)%maxsize;
        }
        cursize--;
        return popped;
    }

    int front(){
        return arr[start];
    }

    bool isEmpty(){
        return (cursize==0);
    }
};

int main()
{

    return 0;
}
