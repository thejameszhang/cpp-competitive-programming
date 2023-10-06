#include <iostream>
using namespace std;

int main() {
    long long n, prev = 0, curr = 0, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        if (prev > curr) {
            res += (prev - curr);
        } else {
            prev = curr;
        }
    }
    cout << res;
    return 0;
}