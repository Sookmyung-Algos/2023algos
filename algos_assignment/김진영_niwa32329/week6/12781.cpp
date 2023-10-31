#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
	int a = (x1 * y2) + (x2 * y3) + (x3 * y1) - (x2 * y1) - (x3 * y2) - (x1 * y3);
	if (a > 0) {
		return 1;
	}
	else if (a == 0) {
		return 0;
	}
	else if (a < 0) {
		return -1;
	}
}

int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int a = CCW(x1, y1, x2, y2, x3, y3);
	int b = CCW(x1, y1, x2, y2, x4, y4);

	if (a * b < 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}
