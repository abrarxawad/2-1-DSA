/*given an array...keep the elements which occur once or twice.
 if more then keep the fast and last occurrence
 and remove rest of the elements ..solve in c++
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[2 * n] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int freq[2 * n] = {0};
    int first[2 * n];
    int last[2 * n];
    for (int i = 0; i < n; i++)
    {
        first[i] = -1;
        last[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;

        if (first[arr[i]] == -1)
        {
            first[arr[i]] = i;
        }
        last[arr[i]] = i;
    }
    int result[2 * n];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] <= 2)
        {
            result[k++] = arr[i];
        }
        else if (first[arr[i]] == i || last[arr[i]] == i)
        {
            result[k++] = arr[i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}