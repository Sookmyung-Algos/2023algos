#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int ans = 0;
int N, K;
int omr[22], sol[22];

void back(int step) {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(omr[i] == sol[i]) cnt++;
    }
    ans = max (ans, cnt);
    if(step == K) return;
    for(int i = 0; i < N; i++) {
        int tmp = omr[i];
        for(int j = i + 1; j < N; j++) {
            omr[j - 1] = omr[j];
        }
        omr[N - 1] = 0;
        back(step + 1);
        for (int j = N - 1; j > i; j--)
            omr[j] = omr[j - 1];
        omr[i] = tmp;
        tmp = omr[N - 1];
        for(int j = N; j > i; j--)
            omr[j] = omr[j - 1];
        omr[i] = 0;
        back(step + 1);
        for(int j = i; j < N - 1; j ++)
            omr[j] = omr[j + 1];
        omr[N - 1] = tmp;
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> omr[i];
    for(int i = 0; i < N; i++) cin >> sol[i];
    back(0);
    cout << ans << "\n";
    return 0;
}
