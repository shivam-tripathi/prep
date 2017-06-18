#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	getline(cin, s);

	while(t--) {
	    getline(cin, s);
	    int end = s.size()-1;
	    for(int i=0; i<s.size(); i++) {
	        while(s[end] == ' ' && end >= 0) {
	            end--;
	        }
	        while (s[i] == ' ' && i < s.size()) {
	            i++;
	        }
	        if (end < i)
	            break;

	        swap(s[i], s[end]);
	        end--;
	    }
	    cout << s << endl;
	}
	return 0;
}

// Imagine this like regular C string reverse, with front and end indexes being swapped till end >= start
// Just skip spaces