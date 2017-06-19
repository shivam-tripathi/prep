#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

vector<ull> fact;
vector<string> fact_string;

void to_str(ull num, string &str) {
    while(num) {
        str += (char)((num%10) + '0');
        num /= 10;
    }
    int s = 0, e = str.size()-1;
    while(s < e) {
        swap(str[s++], str[e--]);
    }
}

void fact_func(int k, string &str) {
    int carry = 0;
    for(int i=str.size()-1; i>=0; i--) {
        int ans = str[i] - '0';
        ans *= k;
        ans += carry;
        str[i] = (char)(ans%10 + '0');
        carry = ans/10;
    }
    string temp = "";
    to_str(carry, temp);
    str = temp+str;
}

int main() {
	fact.push_back(1);
	unsigned long long res = 1;
	int i;

	for(i=1; i<=20; i++) {
	    fact.push_back(fact[i-1]*i);
	}

	string temp = "";
    to_str(fact[20], temp);

    for(int i=21; i<=1000; i++) {
        fact_func(i, temp);
        fact_string.push_back(temp);
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n <= 20)
            cout << fact[n] << endl;
        else if (n > 20)
            cout << fact_string[n-21] << endl;
    }
}

// Remember to add the remaining carry to the solution
// Multiply the digit with the multiplicant and add carry, %10 is the new digit and /10 is the new carry.
// You can do this in reverse manner, and keep adding new characters to the solution as they increase.
// Return answer as reverse of the value.

// You need a convert to string function to convert the carry to string.
