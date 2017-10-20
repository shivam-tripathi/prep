#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        bool dp[n+10][n+10];
        memset(dp, false, sizeof dp);

        int begin = 1;
        int end = 1;

        for(int i=1; i<=n; i++) {
            dp[i][i] = true;
        }

        for(int i=1; i<n; i++) {
            if (s[i-1] == s[i]) {
                dp[i][i+1] = true;
                begin = i;
                end = i+1;
            }
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if ((i+1 <= j-1) && dp[i+1][j-1] && s[i-1] == s[j-1]) {
                    dp[i][j] == true;

                    if ((j-i) > (end-begin)) {
                        begin = i;
                        end = j;
                    }
                }
            }
        }

        string ans = "";
        for(int i=begin-1; i<end; i++) {
            ans += s[i];
        }

        return ans;
    }
};


int main(int argc, char const *argv[])
{
    string a = "aaaa";
    Solution solution;
    cout << solution.longestPalindrome(a) << endl;
    return 0;
}