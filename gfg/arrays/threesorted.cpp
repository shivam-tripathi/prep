#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int two_size_first;
	int two_size_mid;
	int one_size;
	int end_index;
	vector<int> arr;

	Solution(int size) {
		end_index = two_size_mid = two_size_first = one_size = -1;
		int temp;
		for(int i=0; i<size; i++) {
			cin >> temp;
			arr.push_back(temp);
		}	
	}

	void solve() {
		if (arr.size() < 3)
			return;

		one_size = arr[0];
		two_size_first = min(arr[0], arr[1]);
		two_size_mid = max(arr[0], arr[1]);

		for(int i=2; i<arr.size(); i++) {
			if(arr[i] > two_size_mid) {
				end_index = i;
				return;
			}
			else if (two_size_first < arr[i] && arr[i] < two_size_mid) {
				two_size_mid = arr[i];
			}
			else if (one_size > arr[i]) {
				one_size = arr[i];
			}
			else {
				two_size_first = one_size;
				two_size_mid = arr[i];
			}
		}
	}

	void result() {
		if (end_index != -1) {
			cout << two_size_first << " " << two_size_mid << " " << arr[end_index] << endl; 
		}
		else {
			cout << "No such sequence found" << endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	int size;
	cout << "Enter size" << endl;
	cin >> size;
	cout << "Enter "  << size << " array elements" << endl;
	Solution solution(size);

	solution.solve();
	solution.result();
	return 0;
}