#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int p[n];
	bool sold[n];
	vector<pii> c1, c2, c3;

	for (int i=0; i<n; i++) {
		cin >> p[i];
		sold[i] = false;
	}

	int temp;
	
	for (int i=0; i<n; i++) {
		cin >> temp;
		if (temp == 1) c1.push_back(pii(p[i], i));
		else if (temp == 2) c2.push_back(pii(p[i], i));
		else if (temp == 3) c3.push_back(pii(p[i], i));
	}

	for (int i = 0; i<n; ++i) {
		cin >> temp;
		if (temp == 1) c1.push_back(pii(p[i], i));
		else if (temp == 2) c2.push_back(pii(p[i], i));
		else if (temp == 3) c3.push_back(pii(p[i], i));
	}

	sort(c1.begin(),c1.end());
	sort(c2.begin(),c2.end());
	sort(c3.begin(),c3.end());


	int s1 = c1.size(), s2 = c2.size(), s3 = c3.size();

	int m, p1 = 0, p2 = 0, p3 = 0, index;
	cin >> m;

	for (int i=0; i<m; i++) {
		if (i != 0)
			cout << " ";

		cin >> temp; 
		if (temp == 1) { 
			while(p1 < s1 && sold[c1[p1].second]) {
				p1++;
			}

			if (p1 < s1) {

				cout << c1[p1].first;
				index = c1[p1].second;
				sold[index] = true;
			}
			else  cout << "-1"; 
		}
		if (temp == 2) {
			while(p2 < s2 && sold[c2[p2].second]) {
				p2++;
			}
			if (p2 < s2) {
				cout << c2[p2].first;
				index = c2[p2].second;
				sold[index] = true;
			}
			else cout << "-1";
		} 
		if (temp == 3) {

			while(p3 < s3 && sold[c3[p3].second]) {
				p3++;
			}
			if (p3 < s3) {
				cout << c3[p3].first;
				index = c3[p3].second;
				sold[index] = true;
			}
			else  cout << "-1"; 
		}
	}

	cout << endl;

	return 0;
}