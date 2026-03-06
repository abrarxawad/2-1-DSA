//insert total count of occurrence immediately after the last occurrence

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
            for (int j = n - 1; j >= i + 1; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[i + 1] = freq[arr[i]];
            freq[arr[i]] = 1;
            n++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}