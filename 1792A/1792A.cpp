#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    #ifndef ONLINE_JUDGE
        std::freopen("input.txt", "r+", stdin);
        std::freopen("output.txt", "w+", stdout);
    #endif

    int t, n;
    std::cin >> t;

    while (t--) {        
        std::cin >> n;
        std::vector<int> h(n);
        for (auto &x : h) {
            std::cin >> x;
        }

        std::cout << n - (std::count(h.begin(), h.end(), 1)) / 2 << '\n';
    }
    
    
    return 0;
}