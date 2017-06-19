#include <bits/stdc++.h>
using namespace std;

struct _charr{
    int occurence;
    int count;
} charr[26];


int main() {
	int t;
	cin >> t;
	while(t--) {
	    for(int i=0; i<26; i++) {
	        charr[i].occurence = INT_MAX;
	        charr[i].count = 0;
	    }
	    int temp;
	    string s;
	    cin >> temp >> s;
	    for(int i=0; i<s.size(); i++) {
	        short index = s[i] - 'a';
	       // cout << index << endl;
	        charr[index].occurence = min(charr[index].occurence, i);
	        charr[index].count += 1;
	    }
	    int ans=-1, min = INT_MAX;
	    for(int i=0; i<26; i++) {
	        if (charr[i].occurence == -1 || charr[i].count != 1) continue;
	        if(min > charr[i].occurence) {
	            min = charr[i].occurence;
	            ans = i;
	        }
	    }
	    if (ans < 0)
	        cout << ans << endl;
	    else
	        cout << (char)(ans+'a') << endl;
	}
	return 0;
}