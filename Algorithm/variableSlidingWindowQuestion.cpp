// Longest Subarray With Sum ≤ S (Variable Window)
// nums = [2,1,3,2,4], S = 6 → longest is: [2,1,3] length = 3

#include <iostream>
#include <vector>
using namespace std;

int longestSubarraySumAtmostS(vector<int> &nums, int S)
{
    int left = 0, sum = 0, ans = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        while (sum > S)
        {
            sum -= nums[left];
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main()
{
    vector<int> t1 = {2, 1, 3, 2, 4};
    cout << "Test 1: [2,1,3,2,4], S=6 -> "
         << longestSubarraySumAtmostS(t1, 6) << endl; // expected 3

    vector<int> t2 = {1, 2, 1, 1, 3};
    cout << "Test 2: [1,2,1,1,3], S=4 -> "
         << longestSubarraySumAtmostS(t2, 4) << endl; // expected 3

    vector<int> t3 = {5, 5, 5, 5};
    cout << "Test 3: [5,5,5,5], S=5 -> "
         << longestSubarraySumAtmostS(t3, 5) << endl; // expected 1

    vector<int> t4 = {1, 1, 1, 1, 1};
    cout << "Test 4: [1,1,1,1,1], S=3 -> "
         << longestSubarraySumAtmostS(t4, 3) << endl; // expected 3

    vector<int> t5 = {};
    cout << "Test 5: empty array -> "
         << longestSubarraySumAtmostS(t5, 10) << endl; // expected 0
    return 0;
}
