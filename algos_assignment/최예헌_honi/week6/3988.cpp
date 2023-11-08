#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 1000002
#define INF 987654321

int n, k;
int arr[MAX];
deque<int> q;
int result = INF;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>k;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    sort(arr, arr+n);
    
    k = n-k;
    for (int i=0, j=1; i+k<=n; i++){
        if (!q.empty() && q.front() <= i)
            q.pop_front();
        
        for (; j<i+k; j++){
            while (!q.empty() && arr[j]-arr[j-1] <= arr[q.back()] - arr[q.back()-1])
                q.pop_back();
            q.push_back(j);
        }
        
        int frontM = arr[q.front()] - arr[q.front()-1];
        int backM = arr[i+k-1] - arr[i];
        result = min(result, frontM + backM);
    }
    cout<<result;
}
