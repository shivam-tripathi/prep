#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	string temp, s;
	getline(cin, temp);

	while(t--) {
	    getline(cin, s);
	    int size;
	    cin >> size;
	    getline(cin, temp);

	    char *str = new char[size*3];
	    int i, j;
	    for(i=0, j=0; i<s.size(); i++) {
	        if (s[i] != ' ') {
	            str[j++] = s[i];
	        }
	        else {
	            str[j++] = '%';
	            str[j++] = '2';
	            str[j++] = '0';
	        }
	    }
	    str[j] = '\0';
	    cout << str << endl;
	}
	return 0;
}

// Process character by character.
// If encounter a space, insert "%20".
// Maximum length of URLified string would be 3 times original string, assuming all characters are spaces.
// Insert '\0' character at the end.