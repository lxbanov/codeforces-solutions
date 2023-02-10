#include <iostream>
#include <algorithm>

int main() {
#ifndef ONLINE_JUDGE
    std::freopen("input.txt", "r+", stdin);
    std::freopen("output.txt", "w+", stdout);
#endif

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int l = 0;
        while ((l << 1) < n && s[l] != s[n - l - 1]) {
            ++l;
        }
       std::cout << (n - 2 * l) << "\n";
    }
}