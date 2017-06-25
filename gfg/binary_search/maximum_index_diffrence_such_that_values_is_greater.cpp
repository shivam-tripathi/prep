#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int size;
vector<pii> arr(1000+10);

int solve(int temp, int index) {

    vector<pii> :: iterator it = lower_bound(arr.begin(), arr.end(), pii(temp, INT_MAX));

    if (it == arr.begin()) {cout << temp << " -----> " << it->first << endl; return -1;}

    it--;
    cout << temp << '>' << (it->first) << " " << index << " - " << (it->second) << endl;

    if (temp > (it->first))
        return index - (it->second);
    return -1;
}

int _solve(int temp, int index) {
    // cout << "Solving " << temp << endl;

    if (arr[size-1].first > temp) {
        // cout << "_____-1______" << temp << endl;
        return (-1);
    }

    if (arr[0].first < temp) {
        return (index-0);
    }

    int high = size-1, low = 0, mid;
    while(high>low) {

        mid = (high+low)/2;
        // cout << "High " << high << " mid " << mid << " low " << low << endl;

        if (arr[mid].first >= temp) {
            low = mid+1;
        }
        else if (arr[mid].first < temp) {
            high = mid;
        }
        // if (high == mid) break;
    }

    // cout << "NEXT SMALL " << arr[high].first << " " << arr[low].first << endl;
    return (index - arr[high].second);

    // if (high == low) {
    //     cout << "NEXT SMALL " << arr[high].first << endl;
    //     return (index - arr[high].second);
    // }
    // else {
    //     cout << "NEXT SMALL " << arr[high].first << endl;
    //     return (index - arr[high].second);
    // }
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
	   int n;
	   size = 0;
	   scanf("%d", &n);
	   //cout << n << t << endl;
	   int temp, range = 0;
	   for(int i=0; i<n; i++) {
          scanf("%d", &temp);

	      if (size == 0) {
	          arr[size++] = pii(temp, i);
	          continue;
	      }

	   //   for(int i=0; i<size; i++) {
	   //       cout << arr[i].first << " | ";
	   //   }
	   //   cout << endl;

	      int ff = _solve(temp, i);
	   //   cout << "New range " << range << " " << ff << endl;
	      range = max(range, ff);

	      if (arr[size-1].first > temp) {
	          arr[size++] = pii(temp, i);
	      }

	      if (t) arr.clear();
	   }
	   cout << range << endl;
	}
	return 0;
}

//  It really made me confident in binary search problems. I don't need to memorize shit - I can write everything from scratch
// It basically requires you to maintain a array of the smallest values occurred till this index.
// On encoutering a value, we see if a smaller value already existed before this. If yes, fuck it. If no, add the value + index pair.
// Also, for each value check the most optimum value existing less (smallest index with value smaller than this index) in the list.
// You need binary search for this (I can write binary search now with no errors).
// Move till the end, print the answer.