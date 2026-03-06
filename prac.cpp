#include <bits/stdc++.h>
using namespace std;

class mov_avg
{

public:

    int *arr;
    int size;
    int count;
    int windsize;
    double sum;
    int topindx = -1;

    mov_avg(int N = 0)
    {
       
        size = 100;
        arr = new int[size];
        count = 0;
        windsize = N;
        sum = 0.0;
    }

    float next(int val)
    {
        if (count == windsize)
        {
            sum = sum - arr[topindx];
            topindx=(topindx+1)%size;
            count--;
        }

        sum += val;
        count++;
        arr[count]=val;
        return sum / count;
    }
};

int main()
{
    mov_avg obj(3);
    cout<<obj.next(1)<<endl;;
    cout<<obj.next(10)<<endl;;
    cout<<obj.next(3)<<endl;;
    cout<<obj.next(5)<<endl;;

    return 0;
}