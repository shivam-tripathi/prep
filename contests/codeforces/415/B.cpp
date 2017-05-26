#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	int n, f;
	cin >> n >> f;
	ll val=0, ans=0;

	vector<ll> fval;

	for(int i=0; i<n; i++) {
		ll k, l;
		cin >> k >> l;

		if (l > k) {
			ans += k;
			l = l-k;
			val = (l > k) ? k : l;
			fval.push_back(val);
		}
		else {
			ans += l;
			fval.push_back(0);
		}	
	}

	sort(fval.begin(), fval.end());

	int p = 0;
	while(p < f) {
		ans += fval[n-1-p];
		p++;
	}

	cout << ans << endl;

	return 0;
}