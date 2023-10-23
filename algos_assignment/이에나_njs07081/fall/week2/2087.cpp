#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int n;
unsigned sum;
vector<pair<int, int>> a;
ull sumFromStart[41] = { 0 };
ull msg = 0;


bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

inline void  setMsgAtBit(int bitNo) {
	msg |= (1LL << bitNo);
}
inline void eraseMsgAtBit(int bitNo) {
	msg &= ~(1LL << bitNo);
}

void calcSumFromStart() {
	for (int i = 1; i < n; ++i)
		sumFromStart[i] = sumFromStart[i-1] - a[i-1].second;
	return;
}

bool promising(int start, unsigned nowSum) {
	ull maxSum = nowSum + sumFromStart[start];

	if (maxSum >= sum) 
		return true;
	else 
		return false;
}

bool decrypt(int start, unsigned nowSum) {
	//base case 
	if (sum < nowSum)
		return false;
	if (sum == nowSum) {
		//set msg[start + 1] ~ msg[n] to 0
		for (int i = start + 1; i < n; ++i)
			eraseMsgAtBit(a[i].second);
		return true;
	}

	if (!promising(start, nowSum))
		return false;

	//recursive call
	if (decrypt(start + 1, nowSum + a[start].first)) {
		setMsgAtBit(a[start].second);
		return true;
	}
	else if (decrypt(start + 1, nowSum)) {
		eraseMsgAtBit(a[start].second);
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		a.push_back(make_pair(value, i));

		sumFromStart[0] += a[i].first;
	}
	cin >> sum;
	
	sort(a.begin(),a.end(), compare);
	calcSumFromStart();
	decrypt(0, 0);

	for (int i = 0; i < n; ++i){
		if(msg & (1LL << i)) cout << "1";
		else cout << "0";
	}
	return 0;
}
