#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 100001
#define INF 987654321

ll a, b, n;
int dp[100003];
vector<int> prime;
map<ll, int> mm;
vector<ll> divisor;

void init() {
    for (int i=2; i<MAX; i++) {
        if (dp[i])
            continue;
        for (int j=2*i; j<MAX; j+=i) {
            dp[j] = 1;
        }
    }
    
    for (int i=2; i<MAX; i++) {
        if (!dp[i])
            prime.push_back(i);
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    
    init();
    for (int t=1; t <= T; t++) {
        cin>>a>>b>>n;
        divisor.clear();
        mm.clear();
        
        while (n > 1){
            bool check = false;
            
            for (auto p:prime) {
                if (n % p == 0){
                    n /= p;
                    mm[p] = 1;
                    check = true;
                    break;
                }
            }
            if (!check) break;
        }
        
        if (n != 1)
            mm[n] = 1;
        
        for (auto it=mm.begin(); it!=mm.end(); it++){
            divisor.push_back((*it).first);
        }
        
        int size = divisor.size();
        ll result = 0;
        for (int i=0; i< (1<<size); i++){
            if (!i) continue;
            
            int cnt = 0;
            ll div = 1;
            
            for (int j=0; j<size; j++){
                if (i & (1<<j)){
                    div *= divisor[j];
                    cnt++;
                }
            }
            
            ll lo = (a + div - 1)/div*div;
            ll hi = b/div*div;
            if (lo > hi) continue;
            ll flag = (hi - lo)/div + 1;
            result += cnt%2 ? flag : -flag;
        }
        cout<<"Case #"<<t<<": "<<b-a+1-result<<"\n";
    }
}
