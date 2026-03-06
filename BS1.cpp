#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, pos;
    cin >> n >> pos;
    int arr[2 * n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        
        if (arr[mid] <= pos)
        {
            ans = arr[mid] ;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
