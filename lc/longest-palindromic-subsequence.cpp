#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int dp[1010][1010];
    string str;
    int n;

    int palin(int l, int r) {
        if (r < l) return 0;
        if (r == l) return 1;

        if (dp[l][r] != -1)
            return dp[l][r];

        int r_new;
        for(int i=r; i>=l; i--) {
            if (str[i] == str[l]) {
                r_new = i;
                break;
            }
        }

        int one, two;

        one = palin(l+1, r);

        if (l != r_new) {
            two = palin(l+1, r_new-1) + 2;
        }
        else two = 1;

        dp[l][r] = (one > two) ? one : two;
        return dp[l][r];
    }

    string get_ans(int l, int r) {
        if (r < l) return "";
        if (r == l) return string(1, str[l]);

        string ret = "";

        if (dp[l][r] != dp[l+1][r]) {
            int new_r;
            for(int i=r; i>=l; i--) {
                if (str[l] == str[i]) {
                    new_r = i;
                    break;
                }
            }

            if (l == new_r) return string(1, str[l]);

            ret = str[l] + get_ans(l+1, new_r-1) + str[l];
        }
        else ret = get_ans(l+1, r);

        return ret;
    }

    string longestPalindrome(string s) {
        str = s;
        n = s.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dp[i][j] = -1;
            }
        }


        palin(0, n-1);
        string ans = get_ans(0, n-1);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    string a = "babad";
    cout << "String is " << a << endl;
    Solution solution;

    cout << "Calling solution ::: " << solution.longestPalindrome(a) << endl;

    return 0;
}