#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll base = 1000000000+9;
const int max_size = 3 * (10e5) + 100;
int n;
int ans;


int main(int argc, char const *argv[]){
	int n;
	scanf("%d", &n);
	
	ll st[n];
	st[0] = 1;
	for(int i=1; i<n; i++) {
		st[i] = (2*st[i-1]) % base;
	}

	int arr[n];
	for (int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr+n);

	ll ans = 0;

	for(int i=0; i<n; i++) {
		ll val = ((1LL * st[i]) - (1LL * st[n-i-1]) + base) % base;
		ans += (val  * 1LL * arr[i]) % base, ans %= base;

	}

	printf("%lld\n", ans);
	return 0;
}