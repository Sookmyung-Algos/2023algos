#include <iostream>

#define mod 10007
using namespace std;

int nCk[53][53];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    for(int n=0; n <= 52; n++){
        nCk[n][0] = 1; nCk[n][n] = 1;
        for(int k = 1; k < n; k++){
            nCk[n][k] = nCk[n-1][k-1] + nCk[n-1][k];
            nCk[n][k] %= mod;
            nCk[n][n-k] = nCk[n][k];
        }
    }
    int anw = 0;
    for(int i=4; i<=N; i+=4){
        if( (i/4) % 2 == 1){
            anw += nCk[13][i/4] * nCk[52-i][N-i];
        }
        else{
            anw -= nCk[13][i/4] * nCk[52-i][N-i];
        }
        anw %= 10007;
    }
    if(anw < 0) anw += mod;
    cout<<anw<<endl;
}
