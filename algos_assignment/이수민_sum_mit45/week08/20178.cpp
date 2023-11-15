#include <iostream>
#include <vector>

using namespace std;

vector<int> findSwitches(int n, vector<vector<int>>& connections) {
    vector<int> switchesToTurnOn;

    for (int light = 0; light < n; ++light) {
        vector<int> possibleSwitches;
        for (int i = 0; i < n; ++i) {
            if (connections[i][light] == 1) {
                possibleSwitches.push_back(i + 1);
            }
        }

        // Check if there is an odd number of switches connected to the light
        if (possibleSwitches.size() % 2 == 1) {
            switchesToTurnOn.push_back(possibleSwitches[0]);
        }
    }

    return switchesToTurnOn;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> connections(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> connections[i][j];
        }
    }

    vector<int> switchesToTurnOn = findSwitches(n, connections);

    if (switchesToTurnOn.empty()) {
        cout << -1 << endl;
    } else {
        for (int i : switchesToTurnOn) {
            cout << i << endl;
        }
    }

    return 0;
}
