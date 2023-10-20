#include <bits/stdc++.h>

using namespace std;
int N, S;
vector<int> arr; // 주어진 배열
map<int, int> cnt;
long long ans = 0; // 경우의 수

void left_dfs(int sum, int current, int end){
    if(current == end){
        cnt[sum] += 1;
        return ;
    }
    left_dfs(sum, current+1, end);
    left_dfs(sum + arr[current], current+1, end);
}

void right_dfs(int sum, int current, int end){
    if( current == end ){
        // cnt[K-sum] > 0 일 때, left_subarray에서 선택했을 때 값이 존재
        if( cnt[S-sum] > 0 )
            ans += cnt[S-sum];
        // right 에서만 선택할 때
        else if( sum == S )
            ans += 1;
        return ;
    }
    right_dfs(sum, current+1, end);
    right_dfs(sum + arr[current], current+1, end);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;
    arr.resize(N);

    for(int i=0; i<N; i++)
        cin >> arr[i];

    left_dfs(0, 0, N/2);
    right_dfs(0, N/2, N);

    // 공집합을 선택할 경우 하나 포함
    if(S == 0) ans -= 1;
    cout << ans ;

    return 0;
}
