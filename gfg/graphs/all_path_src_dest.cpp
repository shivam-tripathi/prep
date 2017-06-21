#include <bits/stdc++.h>
using namespace std;

const int size = 10+10;

int m, n;
bool visited[size];
vector<int> adj[size];

int paths;
int s, d;

void solve(int src) {
    if (src == d) {
        paths++;
        return;
    }

    visited[src] = true;

    vector<int> :: iterator it;
    for(it=adj[src].begin(); it!=adj[src].end(); it++) {
        if (!visited[*it])
             solve(*it);
    }

    visited[src] = false;
    return;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    cin >> n >> m; // V and E
	    for(int i=0; i<n; i++) {
	        adj[i].clear();
	    }

	    for(int i=0; i<m; i++) {
	        int a, b;
	        cin >> a >> b;
	        adj[a].push_back(b);
	    }
	    cin >> s >> d;
	    paths = 0;
	    solve(s);

	    cout << paths << endl;
	}
	return 0;
}


// All paths. Easy peasy. Global paths is incremented every time we encounter the destination. At the end of processing a
// src, reset it to visited::false, as it may be used in next path.

// Pay attention to numbering of nodes (0, ...] or [0, ...]. Also, if it's directed or undirected.