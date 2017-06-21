#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100+10];
bool visited[100+10];
int n;

void dfs(int src) {
    for(int i = 0; i != adj[src].size(); i++) {
        if(!visited[adj[src][i]]) {
            visited[adj[src][i]] = true;
            dfs(adj[src][i]);
        }
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    cin >> n;

	    for(int i=0; i<=n; i++) {
	        adj[i].clear();
	    }

	    bool e;

	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            cin >> e;
	            if (e) {
	                adj[i].push_back(j);
	            }
	        }
	    }
	   // print();
	    for(int i=0; i<n; i++) {
	        memset(visited, false, sizeof visited);
	        dfs(i);
	        for(int j=0; j<n; j++) {
	            cout <<  visited[j] << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}