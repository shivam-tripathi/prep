#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = (1e6)+10;
const ll mod = (1e9)+7;

unordered_set<string> uset;

int main() {
	int t;
	cin >> t;
	ll arr[size];
	arr[0] = 1;
	for (int i=1; i<size; i++) {
	    arr[i] = (arr[i-1]*2L + mod)%mod;
	}

	while (t--) {
	    string s;
	    int k;
	    uset.clear();
	    cin >> s >> k;
	    if (s.size() % k != 0) {
	        cout << -1 << endl;
	        continue;
	    }
	    for(int i=0; i<s.size(); i += k) {
	        string temp = s.substr(i, k);
	        if(uset.find(temp) != uset.end()) continue;
	        uset.insert(temp);
	    }
	    ll ans = 0;
	    unordered_set<string> :: iterator it;
	    for(it = uset.begin(); it != uset.end(); it++) {
	        for(int i=0; i<k; i++) {
	            if((*it)[k-1-i] != '0') {
	                ans = (ans + arr[i] + mod)%mod;
	            }
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}

// Converting to decimal from binary - move j from 0 to end. If (size-j) is one, then add arr[j]
// where arr stores the value of j power of 2.
// Use unordered_set to hash the values of the strings