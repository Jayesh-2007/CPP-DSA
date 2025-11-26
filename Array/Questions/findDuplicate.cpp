#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// "Given an array, return true if it contains duplicates, else false."

bool isDuplicateExist(vector<int> &arr)
{
    unordered_set<int> s;

    for (int num : arr)
    {
        if (s.count(num))
        {
            return true; // duplicate found
        }
        s.insert(num);
    }
    return false; // duplicate not found
}

int main()
{
    // Test Case 1
    vector<int> a1 = {1, 2, 3, 4, 5};
    cout << "Test 1: " << (isDuplicateExist(a1) ? "Duplicates exist" : "No duplicates") << endl;

    // Test Case 2
    vector<int> a2 = {1, 2, 3, 1};
    cout << "Test 2: " << (isDuplicateExist(a2) ? "Duplicates exist" : "No duplicates") << endl;

    // Test Case 3
    vector<int> a3 = {7, 7, 7, 7};
    cout << "Test 3: " << (isDuplicateExist(a3) ? "Duplicates exist" : "No duplicates") << endl;

    // Test Case 4
    vector<int> a4 = {10, 20, 30, 40, 50, 40};
    cout << "Test 4: " << (isDuplicateExist(a4) ? "Duplicates exist" : "No duplicates") << endl;

    // Test Case 5
    vector<int> a5 = {};
    cout << "Test 5: " << (isDuplicateExist(a5) ? "Duplicates exist" : "No duplicates") << endl;

    return 0;
}