#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Station {
    int distance;
    int price;
};

bool compare(Station a, Station b) {
    return a.distance < b.distance;
}

int main() {
    int N, G, B, D;
    cin >> N >> G >> B >> D;

    vector<Station> stations(N);
    for (int i = 0; i < N; i++) {
        cin >> stations[i].distance >> stations[i].price;
    }

    stations.push_back({0, 0}); // 출발지를 추가

    sort(stations.begin(), stations.end(), compare);

    long long totalCost = 1;
    int currentPos = 0;
    int tank = G;

    for (int i = 0; i < N + 1; i++) {
        int distance = stations[i].distance - currentPos;
        if (distance > tank) {
            cout << -1 << endl;
            return 0;
        }

        totalCost += (long long)distance * stations[i].price;
        tank -= distance;
        tank -= 1;
        tank += G;
        currentPos = stations[i].distance;
    }


    cout << totalCost << endl;

    return 0;
}
