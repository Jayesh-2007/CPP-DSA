#include <iostream>
#include <vector>
using namespace std;

// Given a sorted array, return all unique pairs that sum to target
vector<vector<int>> solution(const vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    int left = 0;
    int right = (int)nums.size() - 1;

    while (left < right)
    {
        long long sum = (long long)nums[left] + (long long)nums[right];

        if (sum == target)
        {
            ans.push_back({nums[left], nums[right]});

            // skip duplicates from the left
            int curL = nums[left];
            while (left < right && nums[left] == curL)
                left++;

            // skip duplicates from the right
            int curR = nums[right];
            while (left < right && nums[right] == curR)
                right--;
        }
        else if (sum > target)
        {
            right--;
        }
        else
        { // sum < target
            left++;
        }
    }

    return ans;
}

void printPairs(const vector<vector<int>> &pairs)
{
    if (pairs.empty())
    {
        cout << "No pairs found\n";
        return;
    }
    for (const auto &p : pairs)
    {
        cout << "(" << p[0] << ", " << p[1] << ") ";
    }
    cout << "\n";
}

int main()
{
    // Note: inputs must be sorted for the two-pointer strategy to work.
    vector<int> t1 = {1, 2, 2, 3, 4, 4, 5};
    cout << "Test 1: nums = {1,2,2,3,4,4,5}, target = 6 -> ";
    printPairs(solution(t1, 6)); // expected: (1,5) (2,4)

    vector<int> t2 = {1, 1, 1, 1};
    cout << "Test 2: nums = {1,1,1,1}, target = 2 -> ";
    printPairs(solution(t2, 2)); // expected: (1,1)

    vector<int> t3 = {-3, -1, 0, 1, 2, 3, 3};
    cout << "Test 3: nums = {-3,-1,0,1,2,3,3}, target = 0 -> ";
    printPairs(solution(t3, 0)); // expected: (-3,3) (-1,1)

    vector<int> t4 = {2, 3, 4, 5};
    cout << "Test 4: nums = {2,3,4,5}, target = 10 -> ";
    printPairs(solution(t4, 10)); // expected: No pairs

    vector<int> t5 = {}; // empty
    cout << "Test 5: empty array, target = 0 -> ";
    printPairs(solution(t5, 0)); // expected: No pairs

    return 0;
}
