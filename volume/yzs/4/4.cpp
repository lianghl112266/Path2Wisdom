#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];

        int i = 0, j = arr.size() - 1, cnt = 0;
        while (i <= j) {
            int x = abs(arr[i]), y = abs(arr[j]);
            cnt += 1;
            if (x == y) {
                while(i <= j && abs(arr[i]) == x) i++;
                while(i <= j && abs(arr[j]) == y) j--;
                if (i == j && abs(arr[i]) == x) break;
            } else if (x > y) i++;
            else j--;
        }

        cout << cnt << '\n';
    }
}