#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] >= curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void printArray(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

int main () {
    vector<vector<int>> testCases = {
        {4, 1, 5, 2, 3},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {-5, -1, -3, 2, 0},
        {7, 7, 7, 7}
    };

    for(auto& arr : testCases) {
        insertionSort(arr);
        printArray(arr);
    }
    return 0;
}