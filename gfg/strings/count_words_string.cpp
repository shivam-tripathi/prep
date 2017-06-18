#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	while(t--) {
	    getline(cin, s);
	    int count = 0;
	    bool flag = true;
	    for(int i=0; i<s.size(); i++) {

	    	if (s[i] == ' ') {
	    		flag = true;
	    		continue;
	    	}

	    	if (s[i] == '\\' && i+1 < s.size() && (s[i+1] == 'n' || s[i+1] == 't')) {
	    		i++;
	    		flag = true;
	    		continue;
	    	}

	        if (flag && i<s.size()) {
	            count ++;
	            flag = false;
	        }
	    }

	    cout << count << endl;
	}
	return 0;
}

// Solutions are simple. Try to deal with one logic at a time.
// Keep the answer simple. If it needs one loop, use one loop