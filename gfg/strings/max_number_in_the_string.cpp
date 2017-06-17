#include <bits/stdc++.h>
using namespace std;

char str[100+10];

int main() {
	int t;
	cin >> t;
	while(t--) {
	    memset(str, '\0', sizeof str);
	    scanf("%s", str);
	    int size = strlen(str);
	    str[size] = 'a';
	    str[size+1] = '\0';
	    int start = 0;
	    int max_elem = -1;
	    for(int i=0; i<size+1; i++) {
	        if(!isdigit(str[i])) {
	            if (start <= i-1) {
	                str[i] = '\0';
	                int temp = atoi(str+start);
	                max_elem = max(temp, max_elem);
	            }
	            start = i+1;
	        }
	    }
	    if(max_elem != -1)
	        cout << max_elem << endl;
	}
	return 0;
}

// Edge case = the last number will not be added. To overcome this, add a dummy invalid character at the end.
// Plan is simple :
// 		At any position, either the character is a digit or it is not.

// 		If it is not, then there is a chance that it may be the end of a number.
// 		This is possible only when the index of start is less than present index-1 i.e. the actual end of the number.
// 		If it is so, then simply make the present index value NULL and convert using atoi function to get the number
// 			and compare it with the max_elem.
// 		Move the start to the next index.

// 		If it is a digit, simply move on.