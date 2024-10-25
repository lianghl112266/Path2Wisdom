#include <bits/stdc++.h>

using namespace std;


int partition(vector<int> &arr, int i, int j) {
    int x = arr[i];
    while(i < j) {
        while(i < j && x <= arr[j]) j--;
        arr[i] = arr[j];
        while(i < j && x >= arr[i]) i++;
        arr[j] = arr[i];
    }
    arr[i] = x;
    return i;
}


void quickSort(vector<int> &arr, int i, int j) {
    if (i >= j) return;
    int mid = partition(arr, i, j);
    if (mid == arr.size()/2) return;
    quickSort(arr, i, mid - 1);
    quickSort(arr, mid + 1, j);
}



int main() {
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];

    quickSort(arr, 0, arr.size() - 1);
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}