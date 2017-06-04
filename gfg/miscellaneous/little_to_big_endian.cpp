#include <bits/stdc++.h>
using namespace std;

int main() 
{
   unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)    
       printf("Little endian %s", c);
   else
       printf("Big endian %s", c);

   int x = 0x01234567;

   cout << x << " " << sizeof(char) << " " << sizeof(short) << " " << sizeof(int) << " " << sizeof(long) << " " << sizeof(long long) << endl;

   for (int i=0; i<sizeof(int); i++) {
   		printf("%.2x \n", *((char*)(&x) + i));
   }

   char *temp = new char;

   for(int i=0; i<sizeof(int); i++) {
   		if (i>(sizeof(int)-1-i)) 
   			break;
   		char *a = (char*)&x+i;
   		char *b = (char*)&x+(sizeof(int)-1-i);
   		memcpy(temp, a, sizeof(char));
   		memcpy(a, b, sizeof(char));
   		memcpy(b, temp, sizeof(char));
   }

	cout << endl;

   for (int i=0; i<sizeof(int); i++) {
   		printf("%.2x \n", *((char*)(&x) + i));
   }

   return 0;
}