#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int kadane() {
	int cursum = v[0];
	int maxsum = v[0];
	for(int i=0; i<v.size(); i++) {
		cursum = max(cursum+v[i], v[i]);
		maxsum = max(maxsum, cursum);
	}
	return maxsum;
}

int main(int argc, char const *argv[])
{
	int size;
	cin >> size; 
	for(int i=0; i<size; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (auto i : v) cout << i << " ";
	cout << endl;

	cout << kadane() << endl;
	return 0;
}
