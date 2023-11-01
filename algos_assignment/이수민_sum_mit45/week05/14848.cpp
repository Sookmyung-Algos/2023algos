#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[17], n, m, sum;
ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b % a, a);
}
int main(){
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < m; i++) scanf("%lld", &a[i]);
    // 비트마스킹으로 모든 조합.
    for(int i = 1; i < (1 << m); i++){
        ll lcm = 1;
        ll cnt = -1;
        for(int j = 0; j < m; j++){
            if((1 << j) & i){
                cnt *= -1; 
                lcm = lcm * a[j] / gcd(lcm, a[j]);
            }
        }
        sum += cnt * (n / lcm);
    }
    printf("%lld", n - sum);
    return 0;
}
