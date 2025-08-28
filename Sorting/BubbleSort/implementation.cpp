#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> testCases = {
        {4, 1, 5, 2, 3},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {-5, -1, -3, 2, 0},
        {7, 7, 7, 7}};

    for (auto arr : testCases)
    {
        bubbleSort(arr);
        printArray(arr);
    }

    return 0;
}