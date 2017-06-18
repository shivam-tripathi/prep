#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	getline(cin, s);

	while(t--) {

        getline(cin, s);

	    if (s[0] != ' ')
	        cout << s[0];
	    for(int i=1; i<s.size(); i++) {
	        if (s[i-1] == ' ' && s[i] != ' ') {
	            cout << s[i];
	        }
	    }
	    cout << endl;
	}
}

// After every integer using cin - which stops at the first non integer input - we need to flush the input.
// For this we use an extra getline command, which takes in extra \n character