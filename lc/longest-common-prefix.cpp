#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans = str[0];
        int till = ans.size();

        int n = str.size();
        for(int i=1; i<n; i++) {
            int j = 0;
            while(j < till && j < str[i].size()) {
                if (ans[j] == str[i][j]) {
                    j++;
                }
                else break;
            }
            till = j;
        }
        return ans.substr(0, till);
    }
};

int main() {
    Solution solution;
    string _str[] = {"Hello", "Hell", "Helloooo", "He"};
    vector<string> str(_str, end(_str));
    cout << solution.longestCommonPrefix(str) << endl;
}