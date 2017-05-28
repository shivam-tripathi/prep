#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    n--;
	    int temp;
	    cin >> temp;
	    ll max_prod = temp, cur_max_prod = temp, cur_min_prod = temp;
	    while(n--) {
	        cin >> temp;
	        if (temp == 0) {
	            cur_max_prod = 1;
	            cur_min_prod = 1;
	        }
	        else {
	            ll temp_cur_max_prod = cur_max_prod;
	            cur_max_prod = max(max(cur_max_prod*temp, (ll)temp), max(cur_min_prod*temp, 1LL));
	            cur_min_prod = min(min(temp_cur_max_prod*temp, (ll)temp), cur_min_prod*temp);
	        }
	        max_prod= max(cur_max_prod, max_prod);
	    }
	    cout << max_prod << endl;
	}
	return 0;
}