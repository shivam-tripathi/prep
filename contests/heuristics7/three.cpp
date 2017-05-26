#include <bits/stdc++.h>
using namespace std;

int arr[100000+100];

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	int temp;
	int ptr=0;
	for(int i=0; i<t; i++) {
		cin >> temp;
		if (temp != 0)
			arr[ptr++] = temp;
	}
	for (int i=0; i<t; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}