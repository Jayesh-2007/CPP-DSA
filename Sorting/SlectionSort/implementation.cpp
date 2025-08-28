#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selectionSort(vector<int>& arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        int smallest = i;
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        swap(arr[i], arr[smallest]);
    }

}

void printArray(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    vector<int> arr = {4, 1, 5, 2, 3};
    selectionSort(arr);
    printArray(arr);
    return 0;
}