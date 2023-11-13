#include <bits/stdc++.h>
using namespace std;

using Int = int;
using Long = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    Int n;
    Long m;
    cin >> n >> m;

    vector<Int> ve(n);
    for (auto &i : ve) {
        cin >> i;
    }

    Long ans = 0;
    for (Int bit = 1;bit < (1 << n);++bit) {
        Int count = 0;
        Long value = 1L;

        for (Int p = 0;p < n;++p) {
            if (bit & (1 << p)) {
                count++;
                value *= ve[p];
            }
        }

        if (count % 2) {
            ans += m / value;
        } else {
            ans -= m / value;
        }
    }

    cout << ans << "\n";
}
