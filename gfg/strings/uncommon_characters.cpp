#include <bits/stdc++.h>
using namespace std;

const int size = (int)(500000);

int main() {
	short a_set[size];
	short b_set[size];
	string a, b;
	int t;
	cin >> t;
	while(t--) {
	    memset(a_set, false, sizeof a_set);
	    memset(b_set, false, sizeof b_set);
	    cin >> a >> b;
	    for(int i=0; i<a.size(); i++) {
	        a_set[a[i]] = 1;
	    }

	    for(int i=0; i<b.size(); i++) {
	        if (a_set[b[i]] != 0) {
	            a_set[b[i]] = -1;
	            continue;
	        }
	        b_set[b[i]] = 1;
	    }

	    for(int i=0; i<size; i++) {
	        if (a_set[i] > 0)
	            cout << (char)i;
	        if (b_set[i] > 0)
	            cout << (char)i;
	    }
	    cout << endl;
	}
	return 0;
}