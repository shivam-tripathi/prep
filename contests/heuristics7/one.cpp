#include <bits/stdc++.h>
using namespace std;

vector<int> arr[1000+10];
int v;
int e;
int score[1000+10];
bool visited[1000+10];

void bfs() {
	queue<int> q;
	q.push(0);

	for(int i=1; i<v; i++) {
		score[i] = -1;
	}

	while(!q.empty()) {
		int src = q.front(); 
		// cout << src << " - " << endl; 
		for(int i=0; i<arr[src].size(); i++) {
			if (!visited[arr[src][i]]) {
				q.push(arr[src][i]);
				score[arr[src][i]] = score[src]+1;
				visited[arr[src][i]] = true;
			}
		}
		q.pop();
	}
}


int main(int argc, char const *argv[])
{
	cin >> v >> e;
	int a, b;
	for (int i=0; i<e; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	bfs();
	for(int i=1; i<v; i++) {
		cout << score[i] << endl;
	}
	return 0;
}