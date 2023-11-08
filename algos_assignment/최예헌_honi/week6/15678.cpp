#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 100002
#define INF 987654321

int n, d;
ll arr[MAX], dp[MAX];
deque<pair<ll,ll>> q;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>d;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    for (int i=0; i<n; i++){
        dp[i] = arr[i];
        while (!q.empty() && q.front().first < i-d)
            q.pop_front();
        if (!q.empty())
            dp[i] = max(dp[i], q.front().second + arr[i]);
        while (!q.empty() && q.back().second < dp[i])
            q.pop_back();
        q.push_back({i, dp[i]});
    }
    cout<<*max_element(dp, dp+n);
}
