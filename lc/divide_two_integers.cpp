#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long solve(int &dividend, int divisor) {
        int ans = 1;
        while((divisor+divisor) <= dividend) {
            divisor += divisor;
            ans += ans;
        }
        dividend -= divisor;
        return ans;
    }

    int _solve(int &dividend, int divisor) {
        int ans = 1;
        while(divisor >= (dividend >> 1)) {
            divisor += divisor;
            ans += ans;
        }
        dividend += divisor;
        return ans;
    }

    int divide(int dividend, int divisor) {
        long long ans = 0;

        bool flag = false;
        if ((dividend < 0 && divisor > 0) && (dividend > 0 && divisor < 0)) {
            flag = true;
        }

        if (divisor  == INT_MIN)
            return -1;

        if (dividend == INT_MIN) {
            if (divisor == -1)
                return 0;
            if (divisor > 0)
                divisor = (~divisor) + 1;
            while(dividend <= divisor && divisor != 0) {
                ans += _solve(dividend, divisor);
            }
            return ans;
        }

        if (divisor < 0 && divisor > INT_MIN)
            divisor = (~divisor) + 1;

        if (dividend < 0 && dividend > INT_MIN)
            dividend = (~dividend) + 1;

        // cout << dividend <<  " " << INT_MIN << " " << divisor <<  " " <<  (INT_MIN >> 1) << endl;

        while(dividend >= divisor && divisor != 0) {
            ans += solve(dividend, divisor);
            // cout << "Dividend " << dividend << " ans " << ans << endl;
        }

        if (flag)
            return (~ans) + 1;

        return ans;
    }
};


int main() {
    Solution sol;
    cout << "Ans = :" <<  sol.divide(2147483647, 3) << endl;
}