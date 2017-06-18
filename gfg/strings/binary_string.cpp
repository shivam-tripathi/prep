#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int size;
	    cin >> size;
	    string s;
	    cin >> s;
	    int count = 0;
	    for(int i=0; i<s.size(); i++) {
	        if (s[i] == '1')
	            count++;
	    }
	    cout << (count * (count-1)) / 2 << endl;
	}
}

// Useless question, learnt derivation of AP sum