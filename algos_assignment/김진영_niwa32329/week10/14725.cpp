#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

set<string> s;

int main() {

	int N, K, t;
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> K;
		string tmp = "";
		string str = "";
		for (int j = 0; j < K; j++)
		{
			cin >> tmp;
			str += "*"+tmp;
			s.insert(str);
		}
	}
	
	for (auto value : s) {
		int cnt = count(value.begin(), value.end(), '*');
		int pos = value.find_last_of("*");
		string tmp = value.substr(pos+1);
		for (int i = 0; i < cnt - 1; i++) cout << "--";
		cout << tmp << '\n';
	}
}
