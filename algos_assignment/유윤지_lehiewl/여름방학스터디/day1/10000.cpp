#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<char, int>> points;
    for (int i = 0; i < N; ++i) {
        int c, r;
        cin >> c >> r;
        points.push_back(make_pair('L', c - r));
        points.push_back(make_pair('R', c + r));
    }

    sort(points.begin(), points.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {
        return (p1.second > p2.second) || (p1.second == p2.second && p1.first > p2.first);
    });

    vector<pair<char, int>> stack;
    int area = 1;
    for (const pair<char, int>& curr : points) {
        if (curr.first == 'L') {
            stack.push_back(curr);
            continue;
        }
        int cum_width = 0;
        while (!stack.empty()) {
            pair<char, int> prev = stack.back();
            stack.pop_back();
            if (prev.first == 'C') {
                cum_width += prev.second;
            }
            else if (prev.first == 'L') {
                int width = curr.second - prev.second;
                if (width == cum_width) {
                    area += 2;
                } else {
                    area += 1;
                }
                stack.push_back(make_pair('C', width));
                break;
            }
        }
    }

    cout << area << endl;

    return 0;
}
