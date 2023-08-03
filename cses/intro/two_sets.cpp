#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, sum;
    cin >> n;
    // If the total sum is odd, not possible.
    if ((sum = n * (n + 1) / 2) % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        return 0;
    }
    // Determine the first vector.
    long long target = sum / 2;
    vector<int> vec;
    for (int i = n; i > -1; i--) {
        if (target > i) {
            target -= i;
            vec.push_back(i);
        } else {
            vec.push_back(target);
            break;
        }
    }
    // Now print out the information.
    long long length = vec.size();
    cout << length << endl;
    for (int i = length - 1; i > -1; i--) {
        if (i == 0) {
            cout << vec[i] << endl;
        } else {
            cout << vec[i] << " ";
        }
    }
    cout << n - length << endl;
    for (int i = 1; i < n; i++) {
        if (find(vec.begin(), vec.end(), i) == vec.end()) {
            cout << i << " ";
        }
    }
    return 0; 
}
