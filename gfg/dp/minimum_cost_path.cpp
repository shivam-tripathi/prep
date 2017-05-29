#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unsigned short val[1000][1000];
unsigned short dp[1000][1000];

void solve(int i=0, int j=0) {

}

int main(int argc, char const *argv[])
{
	while(true) {
		int r, c;
		cin >> r;
		if (r == 0) break;
		cin >> c;

		for (int i=1; i<=r; i++) {
			for (int j=1; j<=c; j++) {
				cin >> val[i][j];
			}
		}

		int temp1, temp2;

		for(int i=r; i>0; i--) {
			for(int j=c; j>0; j--) {
				temp1 = temp2 = -99999;
				if (i == r && j == c) 
					dp[i][j] = val[i][j];
				else if (i == r) 
					dp[i][j] = dp[i][j+1] + val[i][j];
				else if (j == c) 
					dp[i][j] = dp[i+1][j] + val[i][j];
				else {
					temp1 = dp[i][j+1];
					temp2 = dp[i+1][j];
 					dp[i][j] = min(temp1, temp2) + val[i][j];
				}
 				// cout << "(" << i << ", " << j << ") " << temp1 << " " << temp2 << " -> " << dp[i][j] << endl;
			}
		}

		cout << dp[1][1] << endl;

	}
	return 0;
}