#include <iostream>
#include <algorithm>
#include <limits>
#include <map>
#include <vector>

constexpr auto MAX = std::numeric_limits<std::int32_t>::max();
constexpr auto MIN = std::numeric_limits<std::int32_t>::min();

inline std::int64_t csa(std::int64_t len) {
    // Count Sub-Arrays
    if (len == 0) {
        return 0;
    }
    return (len * (len - 1)) >> 1;
}

int main() {
#ifndef ONLINE_JUDGE
    std::freopen("input.txt", "r+", stdin);
    std::freopen("output.txt", "w+", stdout);
#endif

    std::int32_t n;
    std::cin >> n;

    std::int32_t x_l{MAX}, x_r{MIN}, y_l{MAX}, y_r{MIN};
    std::map<std::int32_t, std::int32_t> pos[2]{{},
                                                {}};

    std::vector<std::int32_t> p(n), q(n);
    std::int64_t answer = 0;


    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        pos[0][p[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
        pos[1][q[i]] = i;
    }


    // Cases with MEX = 1
    answer += csa(std::min(pos[0][1], pos[1][1]) + 1);
    answer += csa(n - std::max(pos[0][1], pos[1][1]));
    answer += csa(std::max(pos[0][1], pos[1][1]) - std::min(pos[0][1], pos[1][1]));

    // Cases with MEX > 1
    for (int i = 1; i < n; ++i) {
        x_l = std::min(x_l, pos[0][i]);
        y_l = std::min(y_l, pos[1][i]);
        x_r = std::max(x_r, pos[0][i]);
        y_r = std::max(y_r, pos[1][i]);

        std::int64_t p_x = pos[0][i + 1], p_y = pos[1][i + 1];
        std::int64_t rl = std::min(x_l, y_l), lr = std::max(x_r, y_r);
        std::int64_t ll = 0, rr = n - 1;


        if ((rl <= p_x && p_x <= lr) || (rl <= p_y && p_y <= lr)) {
            continue;
        }

        if (p_x <= std::min(x_l, y_l)) {
            ll = std::max(ll, p_x + 1);
        }

        if (p_y <= std::min(x_l, y_l)) {
            ll = std::max(ll, p_y + 1);
        }

        if (p_x >= std::max(x_r, y_r)) {
            rr = std::min(rr, p_x - 1);
        }

        if (p_y >= std::max(x_r, y_r)) {
            rr = std::min(rr, p_y - 1);
        }

        if (ll > rl || rr < lr) {
            continue;
        }

        answer += (rl - ll + 1) * (rr - lr + 1);
    }

    std::cout << 1 /* [0, n) is always a solution */ + answer << '\n';
    return 0;

}