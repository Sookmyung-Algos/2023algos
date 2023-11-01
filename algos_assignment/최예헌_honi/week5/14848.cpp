#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 10002
#define INF 987654321

ll arr[22];
ll n, m, sum;

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        cin>>arr[i];
    }
    
    for (int i=1; i< (1<<m); i++) {
        ll lcm = 1;
        ll cnt = -1;
        
        for (int j=0; j<m; j++) {
            if ((1<<j) & i) {
                cnt *= -1;
                lcm = lcm*arr[j] / gcd(lcm, arr[j]);
            }
        }
        sum += cnt * (n/lcm);
    }
    cout<<n-sum;
}

