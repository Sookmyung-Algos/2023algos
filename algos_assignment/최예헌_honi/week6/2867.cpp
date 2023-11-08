#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define MAX 300003
#define INF 987654321

int n;
vector <pll> arr;
vector <int> lmin, lmax, rmin, rmax;
vector<ll> vec;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    lmin.resize(1+n); lmax.resize(1+n);
    rmin.resize(1+n); rmax.resize(1+n);
    vec.resize(1+n);
    
    for (int i=1; i<=n; i++)
        cin>>vec[i];
    
    arr.clear();
    for (int i=1; i<=n; i++){
        while (!arr.empty() && arr.back().first <= vec[i])
            arr.pop_back();
        lmax[i] = arr.empty() ? 0 : arr.back().second;
        arr.push_back({vec[i], i});
    }
    
    arr.clear();
    for(int i=n; i>0; i--){
        while(!arr.empty() && arr.back().first < vec[i]) arr.pop_back();
        rmax[i] = arr.empty() ? n+1 : arr.back().second;
        arr.push_back({vec[i], i});
    }

    arr.clear();
    for(int i=1; i<=n; i++){
        while (!arr.empty() && arr.back().first >= vec[i])
            arr.pop_back();
        lmin[i] = arr.empty() ? 0 : arr.back().second;
        arr.push_back({vec[i], i});
    }
    
    arr.clear();
    for(int i=n; i>0; i--){
        while (!arr.empty() && arr.back().first > vec[i]) arr.pop_back();
        rmin[i] = arr.empty() ? n+1 : arr.back().second;
        arr.push_back({vec[i], i});
    }

    ll result = 0;
    for(int i=1; i<=n; i++){
        ll cnt = ll(rmin[i] - i) * (i - lmin[i]);
        result -= vec[i] * cnt;
        cnt = (ll)(rmax[i] - i) * (i - lmax[i]);
        result += vec[i] * cnt;
    }
    cout << result;
}
