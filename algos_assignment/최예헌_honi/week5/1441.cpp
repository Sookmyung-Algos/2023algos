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

int n, l, r;
int arr[20];

ll gcd(ll a, ll b){
    if (b)
        return gcd(b, a%b);
    else
        return a;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>l>>r;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    ll result = 0;
    for (ll k=1; k<(1<<n); k++){
        ll tmp = 1, flag = 1, cnt = 0;
        
        for (int i=0; i<n; i++){
            if ((1<<i) & k){
                tmp = tmp*arr[i]/gcd(arr[i], tmp);
                cnt++;
                if (tmp > r){
                    flag = 0;
                    break;
                }
            }
        }
        
        if (!flag) continue;
        if (cnt & 1)
            result += r/tmp - (l-1)/tmp;
        else
            result -= r/tmp - (l-1)/tmp;
    }
    cout<<result;
}
