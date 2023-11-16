#include <iostream>
#include <vector>
using namespace std;

long long findMaxXORSubsequence(vector<long long>& A, int N) {
    long long maxXOR = 0;
    long long currentXOR = 0;
    vector<long long> dp(N);

    for (int i = 0; i < N; i++) {
        currentXOR ^= A[i];

        if (currentXOR > maxXOR) {
            maxXOR = currentXOR;
        }

        dp[i] = maxXOR;

        for (int j = i - 1; j >= 0; j--) {
            currentXOR ^= A[j]; 
            if (currentXOR > maxXOR) {
                maxXOR = currentXOR;
            }
            dp[j] = maxXOR;
        }
        currentXOR = 0; 
    }

    return maxXOR;
}

int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long result = findMaxXORSubsequence(A, N);
    cout << result << endl;

    return 0;
}
