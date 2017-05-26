#include <bits/stdc++.h>
using namespace std;

const int base = 1000000007;
typedef long long ll;

ll dp[110][2];
int n, k, d;

ll solve (ll sum, bool includes) {
	if (sum < 0) 
		return 0;	

	if (dp[sum][includes] != -1) {
		return dp[sum][includes];
	}

	if (sum == 0) {
		ll ans = (includes) ? 1 : 0;
		dp[sum][includes] = ans;
		return ans;
	}

	ll ans = 0;
	bool includes_temp = false;

	for (int i=1; i<=k; i++) {
		if (i >= d) 
			includes_temp = true;

		int temp = solve(sum-i, (includes || includes_temp));

		ans += (temp + base)%base;
		ans %= base;
	}
	dp[sum][includes] = ans;
	return ans;
}

int main(int argc, char const *argv[])
{
	cin >> n >> k >> d;

	memset(dp, -1, sizeof dp);

	cout << solve(n, (d == 1)) << endl;

	return 0;
}