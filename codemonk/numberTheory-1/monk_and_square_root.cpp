#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int ans = -1;
        for(int i=0; i<=m; i++) {
            if ((1L*i*i)%m == n) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
}