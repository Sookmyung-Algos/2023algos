#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int x, y;
    cin >> x >> y;
    
    int result = 0;
    
    if (N == 1) {
        result = 0;
    } else if (x == 1 && y == 1 || x == 1 && y == N || x == N && y == 1 || x == N && y == N) {
        result = 2;
    } else if (x == 1 || x == N || y == 1 || y == N) {
        result = 3;
    } else {
        result = 4;
    }
    
    cout << result;
    
    return 0;
}
