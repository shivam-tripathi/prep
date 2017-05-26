#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	double n, k;
	cin >> n >> k;
	double sum = 0;
	for(int i=0; i<n; i++) {
		double temp;
		cin >> temp;
		sum += temp;
	}

	if (sum > n*(k-0.5)) {
		cout << 0 << endl;
	}
	else {
		double val = (k-0.5)*n - sum;
		val *= 2;

		cout << ceil(val) << endl;
	}
	return 0;
}