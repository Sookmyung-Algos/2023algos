ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	FAST;
	int tt; cin >> tt;
	for (int tc = 1; tc <= tt; tc++) {
		ll a, b, n;
		cin >> a >> b >> n;
		ll ans = b - a + 1;

		ll temp = n;
		vector<ll> comp; //n의 소인수
		for (ll i = 2; i * i <= n; i++) {
			if (temp % i == 0) {
				comp.push_back(i);
				while (temp % i == 0) temp /= i;
			}
		}
		if (temp != 1) comp.push_back(temp);
...
