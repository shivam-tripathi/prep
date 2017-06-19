#include <bits/stdc++.h>
using namespace std;

string str;

void strrev(int s, int e) {
    while(s < e) {
        swap(str[s], str[e]);
        s += 1;
        e -= 1;
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    cin >> str;
	    int s = 0, e = 0;
	    while(e < str.size()) {
	        if (str[e] == '.') {
	            if (e > s) {
	                strrev(s, e-1);
	            }
	            s = e = e+1;
	        }
	        else e++;
	    }
	    strrev(s, e-1);
	    strrev(0, str.size()-1);
	    cout << str << endl;
	}
	return 0;
}

// Reverse individual words, and then reverse the whole string.
// Always try to check the last word, which might not be processed due to lack of regular ending signal.