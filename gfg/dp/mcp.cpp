#include <bits/stdc++.h>
using namespace std;

const int size = 1000;

short tc[size][size];
short cost[size][size];
int R, C;
  
int minCost(int m, int n)
{
     int i, j;
 
     // Instead of following line, we can use int tc[m+1][n+1] or 
     // dynamically allocate memoery to save space. The following line is
     // used to keep te program simple and make it working on all compilers.
 
     tc[0][0] = cost[0][0];
 
     /* Initialize first column of total cost(tc) array */
     for (i = 1; i <= m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];
 
     /* Initialize first row of tc array */
     for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];
 
     /* Construct rest of the tc array */
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i-1][j], 
                           tc[i][j-1]) + cost[i][j];
 
     return tc[m][n];
}
 
 
/* Driver program to test above functions */
int main()
{
  while(true) {
    cin >> R;
    if (!R) break;
    cin >> C;
    for (int i=0; i<R; i++) {
      for(int j=0; j<C; j++) {
        cin >> cost[i][j];
      }
    }
    printf("%d\n", minCost(R-1, C-1));
  }
   return 0;
}