#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<int> input;
vector<int> l, r;

void dfs(int begin, int end, int sum, vector<int> &ve) {
    if (sum > c) return;
    if (begin == end) {
        if (sum != 0LL) ve.push_back(sum);
        return;
    }
    dfs(begin + 1, end, sum, ve);
    dfs(begin + 1, end, sum + input[begin], ve);
}

int main() {
    cin >> n >> c;
    input.resize(n);
    for (auto &i : input) {
        cin >> i;
    }

    dfs(0, n / 2, 0, l);
    dfs(n / 2, n, 0, r);

    int ans = l.size() + r.size() + 1;
    sort(r.begin(), r.end());
    for (auto &i : l) {
        ans += upper_bound(r.begin(), r.end(), (c - i)) - r.begin();
    }

    cout << ans << "\n";
}
