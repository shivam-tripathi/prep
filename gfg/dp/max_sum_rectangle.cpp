#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int r, c;
	vector<int> *arr;
	vector<int> temp;
	int ans;

	Solution() {
		cin >> r >> c;
		arr = new vector<int>[r];
		int temp;
		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++) {
				cin >> temp;
				arr[i].push_back(temp);
			}
		}
	}

	void kadane(int c1, int c2) {
		temp.clear();
		for(int i=0; i<r; i++) {
			int sum = 0;
			for(int j=c1; j<c2; j++) {
				sum += arr[i][j];
			}
			temp.push_back(sum);
		}

		if (temp.size() == 0) 
			return;

		int max_sum_pres=temp[0], sol=temp[0];

		for(int i=1; i<temp.size(); i++) {
			max_sum_pres = max(max_sum_pres+temp[i], temp[i]);
			sol = max(max_sum_pres, sol);
		}
		ans = max(ans, sol);
	}

	int solution() {
		for(int i=0; i<c; i++) {
			for(int j=0; j<c; j++) {
				kadane(i, j);
			}
		}
		return ans;
	}
};

int main(int argc, char const *argv[])
{
	Solution solve;
	cout << endl;
	cout << solve.solution() << endl;;
	return 0;
}

/*
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/