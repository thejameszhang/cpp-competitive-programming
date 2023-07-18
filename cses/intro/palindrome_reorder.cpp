#include <bits/stdc++.h>
using namespace std;

int main() {
    string word;
    cin >> word;
    int n = word.size();
    // Make a frequency mapping.
    map<char, string> m;
    for (auto c : word) {
        if (m.count(c)) {
            m[c] += c;
        } else {
            m[c] = c;
        }
    }
    string first = "", last = "", odd = "";
    // If n is odd, then we can have one letter of odd occurrence.
    for (auto c : m) {
        if (c.second.length() % 2 == 1 && odd != "") {
            cout << "NO SOLUTION" << endl;
            return 0;
        } else if (c.second.length() % 2 == 1) {
            odd = c.second;
        } else {
            first = c.second.substr(0, floor(c.second.length() / 2)) + first;
            last += c.second.substr(0, floor(c.second.length() / 2));
        }
    }
    cout << last + odd + first;
    return 0;
}