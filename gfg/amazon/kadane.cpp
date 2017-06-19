#include <iostream>
#include <climits>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int max_end, max_ans=INT_MIN;
	    cin >> max_end;
	    max_ans = max_end;
	    int temp;
	    for(int i=1; i<n; i++) {
	        cin >> temp;
	        max_end = max(temp, max_end+temp);
	        max_ans = max(max_ans, max_end);
	    }
	    cout << max_ans << endl;
	}
	return 0;
}

// At any index, either you start a new list or extend the previous list. Ans would be of the maximum
// of the all such list ends