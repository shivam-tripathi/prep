#include <bits/stdc++.h>
using namespace std;

int open[1000+10];
int closing[1000+10];

int main() {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
	    memset(open, 0, sizeof open);
	    memset(closing, 0, sizeof closing);
	    string s;
	    cin >> s;
	    // Padding of one index in the beginning and end => 0 and size+1
        // open[0] = 0;
        // closing[s.size()] = 0;

        for(int i=1; i<s.size()+2; i++) {
            if (s[i-1] == '(')
                open[i] = open[i-1]+1;
            else
                open[i] = open[i-1];
        }

        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == ')')
                closing[i] = closing[i+1] + 1;
            else
                closing[i] = closing[i+1];
        }

        bool flag = false;
        for(int i=1; i<s.size()+1; i++) {
            // cout << "Position " << i << " | Open : " << open[i] << " Close : " << closing[i] << endl;
            if (open[i] == closing[i]) {
                // cout << "Ans : ";
                cout << i << endl;
                flag = true;
            }
        }
        if (!flag) cout << -1 << endl;
	}
	return 0;
}