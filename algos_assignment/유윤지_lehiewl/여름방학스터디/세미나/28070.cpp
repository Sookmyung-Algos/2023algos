#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 100001
#define INF 1e9
using namespace std;

int N;
int DP[MAX], Sum[MAX];
string A, B;
int Max = -1;
int Answer;

int parsing(string S) {
    int Year = stoi(S.substr(0, 4));
    int Month = stoi(S.substr(5));
    return ((Year - 2000) * 12 + Month);
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        DP[parsing(A)]++;
        DP[parsing(B) + 1]--;
    }
}

void settings() {
    for (int i = 1; i < MAX; i++) {
        Sum[i] = Sum[i - 1] + DP[i];
    }
    for (int i = 0; i < MAX; i++) {
        if (Max < Sum[i]) {
            Max = Sum[i];
            Answer = i;
        }
    }
}

void find_Answer() {
    if (Answer % 12 == 0) {
        cout << (Answer / 12) + 1999 << "-12";
    }
    else {
        cout << (Answer / 12) + 2000 << "-";
        if (Answer % 12 < 10) {
            cout << "0";
        }
        cout << Answer % 12 << "\n";
    }
}

int main() {
    cin.tie(0); 
    cout.tie(0); 
    ios::sync_with_stdio(false);
    input();
    settings();
    find_Answer();

    return 0;
}
