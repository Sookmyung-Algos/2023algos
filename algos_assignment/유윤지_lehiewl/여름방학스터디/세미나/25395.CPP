#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
int x[MAX], h[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, s;
	cin >> n >> s;

	for (int i = 1; i <= n; i++)
		cin >> x[i];

	for (int i = 1; i <= n; i++)
		cin >> h[i];

	int low = s, high = s;
	int l = x[low] - h[s], r = x[high] + h[s];
	int min_ = 1e9, max_ = 0;
	while (1) {
		for (int i = low - 1; i >= 1; i--) {
			if (x[i] >= l) {
				min_ = min(min_, x[i] - h[i]);
				max_ = max(max_, x[i] + h[i]);
				low = i;
			}
			else {
				break;
			}
		}

		for (int i = high + 1; i <= n; i++) {
			if (x[i] <= r) {
				min_ = min(min_, x[i] - h[i]);
				max_ = max(max_, x[i] + h[i]);
				high = i;
			}
			else {
				break;
			}
		}

		if (l == min_ && r == max_)
			break;

		  l = min_;
		  r = max_;
	}

	for (int i = low; i <= high; i++)
		cout << i << ' ';
	  cout << '\n';
	  return 0;
}
