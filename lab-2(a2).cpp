/*
The problem asks you to implement a MovingAverage class that:

Uses a sliding window of size N

Adds numbers using next(val)

If window exceeds size N → remove oldest value

Return the average of current window elements
*/

#include<bits/stdc++.h>
using namespace std;

class mov_avg{
public:
    int *arr;
    int front, rear;
    int count;
    int windsize;
    double sum;
    mov_avg(int N){
        windsize=N;
        arr= new int[N];
        front=0;
        rear=-1;
        count =0;
        sum=0;
    }
    double next(int val){
        if(count==windsize){
            sum-=arr[front];
            front=(front+1)% windsize;
            count--;
        }
        rear=(rear+1)%windsize;
        arr[rear]=val;
        sum+=val;
        count++;
        return sum/count;
    }
};

int main()
{ 
    mov_avg obj(3);
    
    cout<<obj.next(1)<<endl;
    cout<<obj.next(10)<<endl;
    cout<<obj.next(3)<<endl;
    cout<<obj.next(5)<<endl;

    return 0;

}