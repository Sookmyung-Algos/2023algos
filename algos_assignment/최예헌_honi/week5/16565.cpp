#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MOD 10007
#define INF 987654321

int dp[53][53];

void init(){
    for (int i=0; i<53; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        
        for (int k=1; k<i; k++) {
            dp[i][k] = dp[i-1][k-1] + dp[i-1][k];
            dp[i][k] %= MOD;
            dp[i][i-k] = dp[i][k];
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    int result = 0;
    
    init();
    cin>>n;
    
    for (int i=4; i<=n; i+=4) {
        if ((i/4) % 2 == 1) {
            result += dp[13][i/4] * dp[52-i][n-i];
        }
        else {
            result -= dp[13][i/4] * dp[52-i][n-i];
        }
        result %= MOD;
    }
    if (result < 0)
        result += MOD;
    cout<<result;
}

