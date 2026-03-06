//count and print duplicate elements of the array

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[2 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int freq[2 * n] = {0};

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (freq[arr[i]] > 1)
        {
            cout << arr[i] << endl;
            cout << freq[arr[i]]<<" times occurs" << endl;
            freq[arr[i]] = 1;
        }
    }

    return 0;
}