#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		bool ans = true;
		string s;
		cin >> s;
		for(int i=0; i<n; i++) {
			if (s[i] == '.')
				continue;
			if (s[i] == 'T' && ans) {
				ans = false;
				break;
			}
			if (s[i] == 'H' && !ans) {
				ans = false;
				break;
			}
			if (s[i] == 'H' && ans) {
				ans = false;
			}
			if (s[i] == 'T' && !ans) {
				ans = true;
			}
		}

		if (ans) {
			cout << "Valid" << endl;
		}
		else {
			cout << "Invalid" << endl;
		}
	}
	return 0;
}