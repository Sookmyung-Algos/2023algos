#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 100001
using namespace std;
int mov[3] = { 2,1,-1 };
int dp[MAX];

void bfs(int start, int end) {
	queue<int> q;
	q.push(start);
	dp[start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == end) {
			cout << dp[end];
			break;
		}
		for (int i = 0; i < 3; i++) {
			int next,time;
			if (i == 0) {
				next = cur * 2;
				time = 0;
			}
			else {
				next = cur + mov[i];
				time = 1;
			}
			if (next >= 0 && next < MAX &&dp[next] > dp[cur] + time) {
				q.push(next);
				dp[next] = dp[cur] + time;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	fill_n(dp, MAX, 987654321);
	bfs(n, k);
	return 0;
}
