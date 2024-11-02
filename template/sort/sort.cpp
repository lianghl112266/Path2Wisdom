#include <bits/stdc++.h>

using namespace std;


class Sort {
    public:
    void InsertSort(vector<int> &a) {
        int n = a.size();
        for(int i = 1; i < n; i++) {
            if (a[i-1] > a[i]) {
                int x = a[i], j;
                for(j = i-1; j >= 0 && a[j] > x; j--) a[j+1] = a[j];
                a[j+1] = x;
            }
        }
    }

    void InsertBisectSort(vector<int> &a) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            if (a[i-1] > a[i]) {
                int x = a[i];
                int left = 0, right = i - 1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (a[mid] >= a[left]) right = mid - 1;
                    else left = mid + 1;
                }
                for(int k = i-1; k >= left; k--) a[k+1] = a[k];
                a[left] = x;
            }
        }
    }

    void ShellSort(vector<int> &a) {
        int n = a.size();
        for(int d = n/2; d >= 1; d /= 2) {
            for(int i = d; i < n; i++) {
                if (a[i] < a[i-d]) {
                    int x = a[i], j;
                    for(j = i - d; j >= 0 && a[j] > x; j -= d) a[j+d] = a[j];
                    a[j+d] = x;
                }
            }
        }
    }

    void BubbleSort(vector<int> &a) {
        int n = a.size();
        for(int i = 0; i < n-1; i++) {
            bool f = false;
            for(int j = n-1; j > i; j--) {
                if (a[j] < a[j-1]) {
                    swap(a[j], a[j-1]);
                    f = true;
                }
            }
            if (!f) break;
        }
    }

    void QuickSort(vector<int> &a, int i, int j) {
        if (i >= j) return;
        int ii = i, jj = j, x = a[i];
        while (ii < jj) {
            while (ii < jj && a[jj] >= x) jj--;
            a[ii] = a[jj];
            while (ii < jj && a[ii] <= x) ii++;
            a[jj] = a[ii];
        }
        a[ii] = x;
        int mid = ii;
        QuickSort(a, i, mid-1);
        QuickSort(a, mid+1, j);
    }

    void SelectSort(vector<int> &a) {
        int n = a.size();
        for(int i = 0; i < n - 1; i++) {
            int mi = i;
            for(int j = i+1; j < n; j++) if (a[j] < a[mi]) mi = j;
            swap(a[mi], a[i]);
        }
    }


    void HeapSort(vector<int> &a) {
        int n = a.size() - 1;
        function<void(int, int)> fix = [&](int k, int n) -> void {
            int i = 2 * k;
            if (i + 1 <= n && a[i+1] > a[i]) i = i+1;
            if (i <= n && a[i] > a[k]) {
                swap(a[k], a[i]);
                fix(i, n);
            }
        };

        for(int i = n/2; i >= 1; i--) fix(i, n);

        for(int i = 0; i < n-1; i++) {
            swap(a[1], a[n-i]);
            fix(1, n-1-i);
        }
    }


    void MergeSort(vector<int> &a, int i, int j) {
        if (j - i <= 1) return;
        int mid = (i + j) / 2;
        MergeSort(a, i, mid);
        MergeSort(a, mid, j);
        vector<int> b(a);
        int ii = i, jj = mid, k = i; 
        while(ii < mid || jj < j) {
            int x = ii < mid ? b[ii] : INT_MAX;
            int y = jj < j ? b[jj] : INT_MAX;
            if (x < y) a[k++] = b[ii++];
            else a[k++] = b[jj++];
        }
    }
};

signed main() {
    auto sort = new Sort();
    vector<int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    //sort->InsertSort(a);
    //sort->InsertBisectSort(a);
    //sort->ShellSort(a);
    //sort->BubbleSort(a);
    //sort->QuickSort(a, 0, a.size() - 1);
    //sort->SelectSort(a);
    // a = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // sort->HeapSort(a);
    sort->MergeSort(a, 0, a.size());
    for(auto x: a) cout << x << ' ';
}