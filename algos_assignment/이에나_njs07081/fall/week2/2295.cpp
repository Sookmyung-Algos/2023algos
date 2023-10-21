#include <bits/stdc++.h>
using namespace std;
 
int arr[1000];
int n;
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            v.push_back(arr[i] + arr[j]);
        }
    }
    sort(v.begin(), v.end());
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n; j++) {
            int k = arr[i] - arr[j];
            int st = 0, ed = v.size() - 1;
            while (st <= ed) {
                int mid = (st + ed) / 2;
                if (v[mid] == k) {
                    cout << arr[i];
                    return 0;
                } else if (v[mid] < k) {
                    st = mid + 1;
                } else {
                    ed = mid - 1;
                }
            }
        }
    }
}
