#include <bits/stdc++.h>
using namespace std;

int m, n;
string g[55];

void dfs(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n)
        return;

    if (g[i][j] == 'X') {
        g[i][j] = 'O';
    }
    else return;

    dfs(i, j+1);
    dfs(i, j-1);
    dfs(i-1, j);
    dfs(i+1, j);
}

int main() {
	short t;
	cin >> t;
	while(t--) {
	    cin >> m >> n;

	    for (int i=0; i<m; i++) {
	        cin >> g[i];
	    }

	    int count = 0;

	    for (int i=0; i<m; i++) {
	        for(int j=0; j<n; j++) {
	            if(g[i][j] == 'O')
	                continue;
	            else {
	                dfs(i, j);
	                count++;
	            }
	        }
	    }
	    cout << count << endl;
	}
	return 0;
}