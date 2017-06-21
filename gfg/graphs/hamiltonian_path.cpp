#include <bits/stdc++.h>
using namespace std;

const int size = 10+10;

int m, n;
bool visited[size];
vector<int> adj[size];

bool solve(int src, int count) {
    visited[src] = true;
    count--;
    if (count == 0) return true;

    vector<int> :: iterator it;
    for(it=adj[src].begin(); it!=adj[src].end(); it++) {
        if (!visited[*it] && solve(*it, count))
            return true;
    }

    visited[src] = false;
    return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    cin >> n >> m;
	    for(int i=0; i<n; i++) {
	        adj[i].clear();
	    }

	    for(int i=0; i<m; i++) {
	        int a, b;
	        cin >> a >> b;
	        adj[a-1].push_back(b-1);
	        adj[b-1].push_back(a-1);
	    }

	    int i;
	    for(i=0; i<n; i++) {
	        memset(visited, false, sizeof (visited));
	        if(solve(i, n)) {
	            break;
	        }
	    }
	    cout << ((i>=n) ? 0 : 1) << endl;
	}
	return 0;
}

// Path and cycle differ. In a cycle, you can start from anywhere and get the hamiltonian path.
// In path, you will have to check all nodes.