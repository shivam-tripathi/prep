#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		bool ans = true;
		if (n%2 == 0) 
			ans = false;
		int iter = 1;
		int mid = n/2 + 1;
		bool rev = false;
		for (int i=0; i<n; i++) {
			int temp;
			scanf ("%d", &temp);
			// cout << ans << " [";
			if (ans) {
				// cout << iter << " ,";
				if (temp != iter){
					ans = false;
				}
				if (iter >= mid)
					rev = true;
				if (rev)
					iter--;
				else 
					iter++;
			}
			// cout << temp << "] " << ans << endl;
		}
		if (ans) 
			cout << "yes" << endl;
		else 
			cout << "no" << endl;
	}
	return 0;
}