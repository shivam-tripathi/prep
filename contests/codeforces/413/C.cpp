#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int bs_lower_bound(vector<pii> &a, int n, int x) {

	int l = 0, h = n, mid;
	while(l < h) {
		mid = (l+h)/2;
		if (x <= a[mid].first) {
			h = mid;
		} else {
			l = mid+1;
		}
	}

	// cout << "lower bound of " << x << " is " << a[l].first << " " << a[l-1].first << endl;

	if (a[l].first >= x)
		l--;
	else if (a[l].first <= x)
		l++;

	return l;
}

// int lower_bound_bs(std::vector<pii> a, int x) {
// 	int l = 0, h = a.size()-1;
// 	while(l <= h) {
// 		int mid = (l+h)/2;
// 		if (a[mid] > x) {
// 			h = mid-1;
// 		}
// 		else {
// 			l = mid;
// 		}
// 	}
// 	if (a[mid] )
// }

void print (vector <pii> &a, string msg) {
	cout << msg << endl;
	for (int i=0; i<a.size(); i++) {
		cout << a[i].first << " " << a[i].second << endl;
	}
	cout << endl;
}


int main(int argc, char const *argv[]) {
	int n, c, d;
	cin >> n >> c >> d;
	vector <pii> carr;
	vector <pii> darr;

	int x, y;
	char z;
	int maxbD = 0, maxbC = 0;
	for (int i=0; i<n; i++) {
		cin >> x >> y >> z;
		if (z == 'D') {
			if (y <= d) {
				darr.push_back(pii(y, x));
				if (y > maxbD) maxbD = x;
			}
		}
		else if (z == 'C') {
			if (y <= c) {
				carr.push_back(pii(y, x));
				if (y > maxbC) maxbC = x;
			}
		}
	}

	if (darr.size() == 0 && carr.size() == 0) {
		cout << 0 << endl;
		return 0;
	}

	sort(darr.begin(), darr.end());
	sort(carr.begin(), carr.end());


	int s1 = darr.size(), s2 = carr.size();

	int maxval = 0;
	if (darr.size() != 0 && carr.size() != 0) {
		maxval = maxbC + maxbD;
	}
	
	// print (darr, "Darr");
	// print (carr, "Carr");
	// cout << "Max val = " << maxval << endl;

	vector<pii> diamond;
	vector<pii> coins;

	int temp;
	if (darr.size() != 0)
		temp = darr[0].second;

	for(int i=0; i<darr.size(); i++) {
		int cost = darr[i].first;

		// cout << "Maxval : " << maxval << endl;

		if (i+1 < darr.size() && darr[i].first == darr[i+1].first) {
			int index = i;
			temp = max(temp, darr[i].second);
			int val = 0;
			i++;
			while (i<darr.size()) {
				val = temp + darr[i].second;
				if ((2*cost <= d) && val > maxval) {
					maxval = val;
				}

				temp = max(temp, darr[i].second);
				
				// Iterate till the last element with the same cost
				if (darr[i+1].first == cost) {
					i++;
				} else {
					break;
				} 
			}

			for (int j=index; j<=i; j++) {
				diamond.push_back(pii(cost, temp));
			}

		} else {
			temp = max(temp, darr[i].second);
			diamond.push_back(pii(darr[i].first, temp));
		}
	}

	// print (diamond, "Diamonds");

	if (carr.size() != 0)
		temp = carr[0].second;
	
	for(int i=0; i<carr.size(); i++) {
		int cost = carr[i].first;
		// cout << "Maxval : " << maxval << endl;
		if (i+1 < carr.size() && carr[i].first == carr[i+1].first) {
			temp = carr[i].second;
			int index = i;
			int val = 0;
			i++;
			while (i<carr.size()) {
				val = temp + carr[i].second;
				if ((2*cost <= c) && val > maxval) {
					maxval = val;
				}

				temp = max(temp, carr[i].second);
				
				// Iterate till the last element with the same cost
				if (carr[i+1].first == cost) {
					i++;
				} else {
					break;
				} 
			}

			for(int j=index; j<=i; j++) {
				coins.push_back(pii(carr[i].first, temp));
			}
			// coins.push_back(pii(cost, temp));
		} 
		else {
			temp = max(temp, darr[i].second);
			coins.push_back(pii(carr[i].first, temp));
		}
	}


	// print (coins, "Coins");
	// cout << "Maxval :: " << maxval << endl;


	for(int i=darr.size()-1; i>=0; i--) {
		int cost = darr[i].first;
		int index = bs_lower_bound(darr, darr.size(), d-cost);


		if(0 > index || index >= diamond.size())
			continue;

		
		if (cost <= darr[index].first) 
			break;
		
		// cout << "D : " << cost << " " << darr[i].second << " " << index << " -> " << diamond[index].first << " " << diamond[index].second << " " << endl;

		if (cost + darr[index].first <= d) {
			// cout << darr[i].first << " " << darr[i].second << " " << index << " : " << diamond[index].first << " " << diamond[index].second << endl;
  			maxval = max(maxval, darr[i].second + diamond[index].second);
		}
	}

	// cout << "Maxval :: " << maxval << endl;

	for(int i=carr.size()-1; i>=0; i--) {
		// cout << "Check" << endl;
		int cost = carr[i].first;
		int index = bs_lower_bound(carr, carr.size(), c - cost);

		if(0 > index || index >= carr.size())
			continue;

		if (cost <= carr[index].first) 
			break;

		if (cost + carr[index].first <= c) {
			// cout << darr[i].first << " " << darr[i].second << " " << index << " : " << diamond[index].first << " " << diamond[index].second << endl;
			maxval = max(maxval, carr[i].second + coins[index].second);
		}
	}

	cout << maxval << endl;
}