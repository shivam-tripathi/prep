#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin >> t;
	while(t--) {
        ll n;
	    cin >> n;
	    int a[n];
        int neg=0, pos=0, zero=0, min_neg=INT_MAX, min_pos=INT_MAX;
	    ll ans = 1;
	    for(ll i=0; i<n; i++) {
	       scanf("%d", &a[i]);
	        if (a[i] < 0) {
	            min_neg = min(min_neg, abs(a[i]));
	            neg++;
	        }
	        else if (a[i] > 0) {
	        	min_pos = min(min_pos, a[i]);
	            pos++;
	        }
	        else {	        	
	        	zero++;
	        } 

	        ans *= (a[i] == 0) ? 1 : a[i];
	    }
	    
	    ll maxans, minans;
	    min_neg *= -1;

        if (neg % 2 == 0) {
            maxans = ans;
            minans = neg!=0 ? ans/(min_neg) : ((zero != 0) ? 0 : min_pos);
        }
        else if (neg % 2 != 0) {
            maxans = ans/min_neg;
            minans = ans;
        }

        // Check if maxans can be zero
        if (pos == 0 && (neg <= 1) && zero != 0) {
	       maxans = 0;
	    }

        printf("%lld %lld \n", maxans, minans);
	}
	return 0;
}