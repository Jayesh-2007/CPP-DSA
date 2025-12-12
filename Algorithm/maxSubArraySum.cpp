// Maximum Sum Subarray of Size K
#include <iostream>
#include <vector>
using namespace std;

int maxSumk(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n < k)
        return -1; // cannot form window

    int ans = 0, sum = 0;

    // first window
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    ans = sum;

    // sliding window
    for (int i = k; i < n; i++)
    {
        sum += nums[i] - nums[i - k];
        ans = max(ans, sum);
    }

    return ans;
}

int main()
{
    // Test Case 1
    vector<int> v1 = {2, 3, 1, 5, 6};
    cout << maxSumk(v1, 3) << endl; // Expected: 12

    // Test Case 2
    vector<int> v2 = {1, 1, 1, 1, 1};
    cout << maxSumk(v2, 2) << endl; // Expected: 2

    // Test Case 3
    vector<int> v3 = {5, -1, 3, 4};
    cout << maxSumk(v3, 2) << endl; // Expected: 7

    // Test Case 4
    vector<int> v4 = {10};
    cout << maxSumk(v4, 1) << endl; // Expected: 10

    // Test Case 5
    vector<int> v5 = {1};
    cout << maxSumk(v5, 2) << endl; // Expected: -1 (window not possible)
    return 0;
}