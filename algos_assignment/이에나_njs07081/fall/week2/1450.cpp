#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
typedef long long ll;
vector <ll>  v;
void dfs(int start, int end, vector <ll>& part, ll sum) {
	if (start > end) {
		part.push_back(sum); 
		return ; 
	}
	else {
		dfs(start + 1, end, part, sum); 
		dfs(start + 1, end, part, sum + v[start]); 
	}
}
int main() {
	int n, c; cin >> n >> c;	
	v.resize(n, 0); 
	for (int i = 0; i < n; i++)cin >> v[i];
	vector <ll> part1;
	vector <ll> part2;
	dfs(0, n / 2 - 1, part1, 0); 
	dfs(n / 2, n - 1, part2, 0); 
	sort(part2.begin(), part2.end()); 
	int cnt = 0; 
	for (int i = 0; i < part1.size(); i++) {
		ll x = c - part1[i]; 
		cnt += upper_bound(part2.begin(), part2.end(), x) - part2.begin(); 
	}
	cout << cnt; 
}
