#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    // brute force approach T.C: O(n^2)
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] + arr[j] == target)
    //         {
    //             cout << "Target found on index: ";
    //             cout << "(" << i << "," << j << ")" << endl;
    //             return 0;
    //         }
    //     }
    // }
    // cout << "Target not found!" << endl;

    // optimized approach: Double Pointer approach T.C = O(log(n))
    // apply on sorting array

    int st = 0, end = n - 1;
    while (st < end)
    {
        int ps = arr[st] + arr[end];
        if (ps < target)
        {
            st++;
        }
        else if (ps > target)
        {
            end--;
        }
        else
        {
            cout << "Target found on index: ";
            cout << "(" << st << "," << end << ")" << endl;
            return 0;
        }
    }
    cout << "Target not found!" << endl;

    return 0;
}
