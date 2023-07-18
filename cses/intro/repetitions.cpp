#include <bits/stdc++.h>
using namespace std;

int main() {
    string sequence;
    cin >> sequence;
    int l = 0, r = 0, res = 0, length = sequence.size();
    while (r < length) {
        if (sequence[l] == sequence[r]) {
            res = max(res, r - l + 1);
        } else {
            l = r;
        }
        r++;
    }
    cout << res;
    return 0;
}
