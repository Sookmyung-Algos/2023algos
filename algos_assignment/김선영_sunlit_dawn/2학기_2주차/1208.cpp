#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int N, S;
int arr[41];
map<int, int> total;
long long cnt;

void left(int s, int sum) {
	if (s == N / 2) {
		total[sum]++;
		return;
	}
	left(s + 1, sum);
	left(s + 1, sum + arr[s]);
}

void right(int s, int sum) {
	if (s == N) {
		cnt += total[S-sum];
		return;
	}
	right(s + 1, sum);
	right(s + 1, sum + arr[s]);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	left(0, 0);
	right(N / 2, 0);
	
	if (S == 0) cout << cnt - 1;
	else cout << cnt;
}
