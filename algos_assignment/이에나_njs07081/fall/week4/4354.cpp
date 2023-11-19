#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string s;
    while(1){
        cin >> s;
        if(s==".") break;

        int N = s.length();
        int lps[N];
        memset(lps,0,sizeof(lps));

        int j = 0;
        for(int i=1; i<N; i++){
            while(j>0 && s[i]!=s[j]){
                j = lps[j-1];
            }
            if(s[i]==s[j]){
                j++;
                lps[i] = j;
            }
        }

        int repeatLength = N - lps[N-1];
        if(N % repeatLength == 0){
            cout << N / repeatLength << '\n';
        }
        else{
            cout << 1 << '\n';
        }
    }

    return 0;
}
