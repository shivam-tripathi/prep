#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string a, b;
	    bool flag = false;
	    cin >> a >> b;
	    if (a.size() < b.size()) {
	        cout << "not found" << endl;
	        continue;
	    }
	    for(int i=0; i<a.size(); i++) {
	        if(a[i] == b[0]) {
	            int j = 0, k = i;
	            while(j < b.size() && k < a.size()) {
	                if (a[k] != b[j])
	                   break;
	                k++;
	                j++;
	            }
	            if (j == b.size()) {
	                flag = true;
	                break;
	            }
	        }
	    }
	    if (flag) {
	        cout << "found" << endl;
	    }
	    else {
	        cout << "not found" << endl;
	    }
	}
}

// Naive solution : O(m * (n-m+1)) = O(n*m) solution, for O(n) solution see KMP version of the above problem as part2
// Similar to what you implemented in compiler lab, just be cautious about index increments