#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int &dividend, int divisor) {
        int ans = 1;
        while(divisor <= (dividend >> 1)) {
            divisor += divisor;
            ans += ans;
        }
        dividend -= divisor;
        return ans;
    }

    int _solve(int &dividend, int divisor) {
        int ans = 1;
        while(divisor >= (dividend >> 1)) {
            divisor <<= 1;
            ans <<= 1;
        }
        divisor = (~divisor) + 1;
        dividend += divisor;
        return ans;
    }

    int divide(int dividend, int divisor) {
        int ans = 0;
        bool flag = false;

        if (divisor == INT_MIN)
            // return (dividend > 0) ? -1 : ((dividend == INT_MIN) ? 1 : 0);
            return (dividend == INT_MIN) ? 1 : 0;

        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            }

            if (divisor > 0) {
                divisor = (~divisor) + 1;
                flag = true;
            }

            while(dividend <= divisor) {
                ans += _solve(dividend, divisor);
            }
            if (flag)
                return (~ans) + 1;
            return ans;
        }

        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            flag = true;
        }

        if (divisor < 0)
            divisor = (~divisor) + 1;
        if (dividend < 0)
            dividend = (~dividend) + 1;

        while(dividend >= divisor && divisor != 0) {
            ans += solve(dividend, divisor);
        }

        if (flag)
            return (~ans) + 1;
        return ans;
    }
};

int main() {
    Solution sol;
    cout << INT_MAX << " " << INT_MIN << endl;
    while(true) {
        int a, b;
        cin >> a >> b;
        cout << sol.divide(a, b) << endl;
    }
}


// -1010369383
// -2147483648