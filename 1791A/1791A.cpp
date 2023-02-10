#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    #ifndef ONLINE_JUDGE
        std::freopen("input.txt", "r+", stdin);
        std::freopen("output.txt", "w+", stdout);
    #endif

    int n;
    std::cin >> n;
    const static std::string codeforces = "codeforces";
    while (n--) {
        char c;
        std::cin >> c;
        if (std::find(codeforces.begin(), codeforces.end(), c) != codeforces.end()) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}