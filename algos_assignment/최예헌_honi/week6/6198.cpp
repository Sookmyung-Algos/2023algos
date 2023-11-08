#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 10002
#define INF 987654321

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    stack<int> s;
    vector<int> arr;
    int n, h;
    ll result = 0;
    
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>h;
        arr.push_back(h);
    }
    
    for (int i=0; i<n; i++) {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        result += (ll) s.size();
        s.push(arr[i]);
    }
    cout<<result;
}
