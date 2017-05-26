#include <bits/stdc++.h>
using namespace std;

bool arr[5][5];

int main(int argc, char const *argv[])
{
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			arr[i][j] = true;
		}
	}

	for (int i=1; i<4; i++) {
		for (int j=1; j<4; j++) {
			int temp;
			cin >> temp;
			if (temp % 2  == 0)
				continue;
			arr[i][j] = !arr[i][j];
			arr[i][j+1] = !arr[i][j+1];
			arr[i+1][j] = !arr[i+1][j];
			arr[i-1][j] = !arr[i-1][j];
			arr[i][j-1] = !arr[i][j-1];
		}
	}
	int count = 0;

	for (int i=1; i<4; i++) {
		for (int j=1; j<4; j++) {
			if (arr[i][j] == true)
				count++;
		}
	}

	cout << count << endl;
	return 0;
}