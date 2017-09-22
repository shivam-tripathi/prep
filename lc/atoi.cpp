#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int begin = 0;
        bool neg = false;
        if (s[0] == '-') {
            begin = 1;
            neg = true;
        }

        if(s[0] == '+') {
            begin = 1;
        }

        int n = s.size();

        bool overflow = false;

        if(s[begin] < '0' || s[begin] > '9') return 0;

        int ans = 0;
        int temp = 0;
        for(int i=begin; i<n; i++) {
            if (s[i] < '0' || s[i] > '9') return (neg) ? -ans : ans;

            int tail = s[i] - '0';
            temp = 10*temp + tail;
            cout << "Tail " << tail << " temp " << temp << " back calc " << (temp-tail)/10 << " prev " << ans << endl;
            if ((temp/10) != ans) {
                cout << "Overflow " << endl;
                overflow = true;
                break;
            }
            ans = temp;
        }

        if (overflow) {
            if (neg) return INT_MIN;
            else return INT_MAX;
        }

        return (neg) ? -ans : ans;
    }
};

int main(int argc, char const *argv[]) {

    // string arr[]  = { "adasd",
    //     "-12121", "12552323552323235523",
    //     "2322", "1244a34", "-12552323552323235523",
    //     "2147483647", "-2147483648", "2147483648",
    //     "-adad", "-1213a33"
    // };

    string arr[] = {"2147483648", "2147483649", "1"};

    vector<string> _arr(arr, arr + sizeof(arr) / sizeof(std::string));
    Solution solution;

    for (int i = 0; i < _arr.size(); ++i) {
        cout << "\nSolving " << _arr[i] << endl;
        cout << solution.myAtoi(_arr[i]) << " "  << atoi(_arr[i].c_str()) << endl;
    }

    return 0;
}