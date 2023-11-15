#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxXORSubarray(vector<long long>& arr, int n) {
    long long maxXOR = 0;
    long long currXOR = 0;

    for (int i = 63; i >= 0; --i) {
        // 현재 maxXOR에 비트 i를 set하고 만들어진 XOR을 저장
        maxXOR <<= 1;
        long long prefixXOR = currXOR | (1LL << i);

        // 가장 높은 비트부터 현재 maxXOR에 해당 비트를 set하고,
        // 그 결과가 수열의 부분 수열 중 하나와 XOR 연산했을 때 나온 값이 최대가 되도록 선택
        for (long long num : arr) {
            if ((num & prefixXOR) == prefixXOR) {
                currXOR = prefixXOR;
                maxXOR |= 1LL;
                break;
            }
        }
    }

    return maxXOR;
}

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = maxXORSubarray(arr, n);
    cout << result << endl;

    return 0;
}
