#include <iostream>
#include <vector>

using namespace std;

// 이항 계수를 구하는 함수
long long binomial(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n - k) {
        k = n - k;
    }
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result = result * (n - i) / (i + 1);
    }
    return result;
}

// S(N, k)를 구하는 함수
long long calculate_S(int N, int k) {
    long long result = 0;
    for (int i = k; i <= N; i++) {
        result += binomial(N, i);
    }
    return result;
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int case_number = 1; case_number <= test_cases; case_number++) {
        int N, k;
        cin >> N >> k;
        long long result = calculate_S(N, k);
        cout << "Case " << case_number << ": " << result << endl;
    }

    return 0;
}
