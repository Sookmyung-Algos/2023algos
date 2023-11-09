#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

long long minimumCost(int N, int G, int B, int D, vector<pair<int, int>>& stations) {
    sort(stations.begin(), stations.end());

    deque<pair<int, long long>> monoQueue;
    monoQueue.push_back({0, 0});

    long long cost = 0;
    int fuel = B;
    int pos = 0;

    for (int i = 0; i < N; i++) {
        int nextDistance = (i + 1 < N) ? stations[i + 1].first : D;
        int distance = stations[i].first;
        int price = stations[i].second;

        if (nextDistance - distance > G) {
            return -1;
        }

        fuel -= (distance - pos);

        while (!monoQueue.empty() && monoQueue.front().first < distance) {
            monoQueue.pop_front();
        }

        int requiredFuel = nextDistance - distance;

        while (fuel < requiredFuel) {
            fuel += 1;
            cost += monoQueue.front().second;
        }

        fuel -= requiredFuel;
        pos = distance;
        monoQueue.push_back({distance, price});
    }

    return cost;
}

int main() {
    int N, G, B, D;
    cin >> N >> G >> B >> D;
    vector<pair<int, int>> stations(N);

    for (int i = 0; i < N; i++) {
        cin >> stations[i].first >> stations[i].second;
    }

    long long result = minimumCost(N, G, B, D, stations);
    cout << result << endl;

    return 0;
}
