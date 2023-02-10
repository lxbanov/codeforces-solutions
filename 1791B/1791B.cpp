#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
#ifndef ONLINE_JUDGE
    std::freopen("input.txt", "r+", stdin);
    std::freopen("output.txt", "w+", stdout);
#endif

    int t;
    std::cin >> t;

    const static std::map<char, std::pair<int, int> >
            directions = {{'U', {1, 0}},
                          {'D', {-1, 0}},
                          {'L', {0, -1}},
                          {'R', {0, 1}}};

    while (t--) {
        int n;
        std::cin >> n;

        std::pair<int, int> p = {0, 0};
        bool hit = false;
        while (n--) {
            char s;
            std::cin >> s;
            auto d = directions.at(s);
            p = {p.first + d.first, p.second + d.second};
            if (p.first == 1 && p.second == 1) {
                hit = true;
            }
        }
        std::cout << (hit ? "YES" : "NO") << '\n';
    }


}