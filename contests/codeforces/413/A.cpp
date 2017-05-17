#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int _k = n - (d/t)*k;
	if (_k <= k)
		cout << "NO" << endl;
	else 
		cout << "YES" << endl;
	return 0;
}