#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
int tree[MAX * 4 + 1];

int minIndex(int x, int y) {
	if (a[x] == a[y]) return x < y ? x : y; // 같은 경우 더 작은 인덱스를 리턴
	return a[x] < a[y] ? x : y;
}

int init(int start, int end, int node){ 
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;
	return tree[node] = minIndex(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int index){ 
	if (index < start || index > end || start == end) return tree[node];

	int mid = (start + end) / 2;
	return tree[node] = minIndex(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;

	init(0, n - 1, 1); // 세그먼트 트리 생성

	while (m--){
		int q, index, value;
		cin >> q;
		if (q == 1)
		{ // 수정하는 경우
			cin >> index >> value;
			index--;
			a[index] = value;
			update(0, n - 1, 1, index);
		}
		if (q == 2)
		{ // 트리의 1번 노드가 최소값의 인덱스
			cout << tree[1] + 1 << '\n';
		}
	}
}
