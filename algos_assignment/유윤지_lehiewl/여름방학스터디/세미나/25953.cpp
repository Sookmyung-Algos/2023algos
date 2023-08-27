#include <iostream>
using namespace std;

int N, T, M, S, E;
int dist[1001][10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> T >> M >> S >> E;
	for (int i = 0; i < N; i++) dist[0][i] = 1000000007;
	dist[0][S] = 0;
	for(int t = 0; t < T; t++) {
		for (int i = 0; i < N; i++) dist[t + 1][i] = dist[t][i];
		for (int i = 0; i < M; i++) {
			int x, y, w; cin >> x >> y >> w;
			dist[t + 1][y] = min(dist[t + 1][y], dist[t][x] + w);
			dist[t + 1][x] = min(dist[t + 1][x], dist[t][y] + w);
		}
	}

	if (dist[T][E] < 1000000007) cout << dist[T][E];
	else cout << -1;
}
