#include <bits/stdc++.h>

using namespace std;

void solve() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (i * 100 + j * 10 + k + j * 100 + k * 10 + k == 532)
                    cout << i << ' ' << j << ' ' << k << '\n';
            }
        }
    }
}


int main() { solve(); }