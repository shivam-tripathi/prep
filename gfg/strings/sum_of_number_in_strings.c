#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char str[(int)(1e5) + 10];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
	   memset(str, '\0', sizeof str);
	   scanf("%s", str);
	   int start = 0;
	   long long count = 0;
	   int size = strlen(str);
	   str[size] = 'a';
	   str[size+1] = '\0';
	   for (int i=0; i< size+1; i++) {
	        if (!isdigit(str[i])) {
	            if (i-1 >= start) {
	                str[i] = '\0';
	                long long temp = atoi(str+start);
	                count += temp;
	            }
	            start = i+1;
	        }
	   }
	   printf("%lld\n", count);
	}
	return 0;
}

// Edge case = the last number will not be added. To overcome this, add a dummy invalid character at the end.
// Plan is simple :
// 		At any position, either the character is a digit or it is not.
//
// 		If it is not, then there is a chance that it may be the end of a number.
// 		This is possible only when the index of start is less than present index-1 i.e. the actual end of the number.
// 		If it is so, then simply make the present index value NULL and convert using atoi function to get the number
// 			and add it.
// 		Move the start to the next index.

// 		If it is a digit, simply move on.