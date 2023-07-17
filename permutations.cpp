#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // Base case.
    if (n > 1 && n < 4) {.
        cout << "NO SOLUTION";
        return 0;
    }
    // Traverse odds first, and then evens.
    for (int j = 2; j <= n; j += 2) {
        cout << j << " ";
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i;
        if (i != n && i != n - 1) {
            cout << " ";
        }
    }
    return 0;
}
