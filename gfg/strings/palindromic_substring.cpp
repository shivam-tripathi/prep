#include <bits/stdc++.h>
using namespace std;

char str[1000+10];
short dp[1000+10][1000+10];
int n;


// The basic idea is to consider the end points - what is the answer between index i and j.
// This is similar to the method we used in the balloon burst problem - split and compute the
// dp solution for each index range.

// Complexity - n^2. I don't know why this runs in the time limit and LCS solution does not.
// Tips on bottom up, should you ever run the risk of doing so:
//      Compute the result for each substring size one by one - first all of size 1, size 2 ... size n
//      The answer for size n is the result
// In the table, the lower half is useless, need not be filled. For example, (2,1) is not needed as there is no string
// which starts from 2 and ends at 3 (some what similar to matric chain multiplication table bottom up).
// (2,3) -> (3,4) -> (4,5) ... and then the size 3, 4, ... n
// dp[i][j] = {if s[i] == s[j] then 2+dp[i-1][j-1] else dp[i][j] = max(dp[i-1][j], dp[i][j-1])} // All precomputed.




int solve(int s, int e) {
    if (s >= n || e < 0 || e < s) {
        return 0;
    }

    if (dp[s][e] == -1) {
        if (str[s] == str[e]) {
            if (s!=e)
                dp[s][e] = 2+solve(s+1, e-1);
            else dp[s][e] = 1;
        }
        else {
            dp[s][e] = max(solve(s+1, e), solve(s, e-1));
        }
    }

    return dp[s][e];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while(t--) {
        memset(dp, -1, sizeof dp);
        cin >> str;
        n = strlen(str);
        // cout << str << " " << n << endl;
        cout << solve(0, n-1) << endl;
    }
    return 0;
}

/*
This approach uses the fact that if we reverse the string, and compute LCS we will get the answer.
Slow, it is of n^2 complexity, will not cut it.

#include <bits/stdc++.h>
using namespace std;

#define J(j) (size-1-(j))

short dp[1000+10][1000+10];
short _dp[1000+10][1000+10];
char s[1000+10];
int size;

int next_match(int index, int a) {
    for(int i=index; i>=0; i--) {
        if (s[i] == s[a])
            return i;
    }
    return -1;
}


int solve(int a, int b) {
    if(a >= size || b < 0)
        return 0;

    if (a==b)
        return 1;
    if (a>b)
        return 0;

    if(dp[a][b] == -1) {
        int next = next_match(b, a);
        if (next != -1)
            dp[a][b] = max(solve(a+1, b), 2+solve(a+1, next-1));
        else
            dp[a][b] = solve(a+1, b);
    }

    return dp[a][b];
}

int _next_index(int l, int i) {
    for(int j=l; j>=0; j--) {
        if(s[j] == s[i])
            return j;
    }
    return -1;
}


// This still has to be optimised to restrict j from making anymore than i iterations
int _solve() {
   for(int i=size-1; i>=0; i--) {
       for(int j=0; j<size; j++) {

            _dp[i][j] = _dp[i+1][j];

            int next = _next_index(j, i);

            if (next != -1)
                _dp[i][j] = max(_dp[i][j], (short)(_dp[i+1][next-1]+1));

            // cout << i << " " << j << " | " << _dp[i][j] << endl;

       }
   }
  return _dp[0][size-1];
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        size = strlen(s);
        for(int i=0; i<size+10; i++) {
            for(int j=0; j<size+10; j++) {
               // dp[i][j] = -1;
                _dp[i][j] = 0;
            }
        }
        cout << _solve() << endl;

    }
}
*/