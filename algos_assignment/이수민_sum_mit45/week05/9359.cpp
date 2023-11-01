#include<cstdio>
#include<vector>
 
using namespace std;
typedef long long lld;
typedef vector<lld> VLL;
typedef vector<bool> VB;
 
VLL factors;
lld ans;
lld A, B, N;
 
lld IE_function(lld facts, int e, int index){
    lld ret = 0;
    if(e%2==1){ // minus
        for(int i = index+1 ; i < factors.size() ; i++) 
            ret += IE_function(facts * factors[i], e+1, i); // lld next_factor = factors[i];
        ret -= (B/facts - (A-1)/facts);
    }else if(e%2==0){ // plus
        for(int i = index+1 ; i < factors.size() ; i++) 
            ret += IE_function(facts * factors[i], e+1, i); // lld next_factor = factors[i];
        ret += (B/facts - (A-1)/facts);
    }
    return ret;
} // inclusionexclusion
 
int main(){
    int n;
    int c = 1;
    VB is_not_prime = VB(88888, false);
    VLL prime = VLL(0);
 
    for(int i = 2 ; i < 33333 ; i++){
        int num = i+i;
        if(!is_not_prime[i]) prime.push_back(i);
 
        while(!is_not_prime[num] && num < 33333){
            is_not_prime[num] = true;
            num += i;
        }
    }
 
    for(scanf("%d", &n) ; n-- ; ){
        factors = VLL(0);
        scanf("%lld%lld%lld",&A,&B,&N);
        ans = B-A+1;
 
        if(N==1){
            printf("Case #%d: %lld\n",c++ , ans);
            continue;
        } // except case N==1 
 
        for(auto iter = prime.begin() ; iter != prime.end() ; iter++){
            lld p = *iter;
            if( (N%p) == 0 ){
                factors.push_back(p);
                while(N%p==0) N/=p;
            }
            if(N==1) break;
        }
        if(N!=1) factors.push_back(N);
        // factorization in prime factors
 
        for(int i = 0 ; i < factors.size() ; i++){
            lld fac = factors[i];
            ans += IE_function(fac, 1, i);
        }
        // inclusionexclusion
 
        printf("Case #%d: %lld\n",c++, ans);
    }
    return 0;
}
