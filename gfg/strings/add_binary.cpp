/*
Addition algorithm:
    1. Assume next carry for all operations zero initially. Add with no regard to previous carry, modify for next carry.
    2. Modify the response considering prev carry, and make changes to next carry.
    3. Continue till smaller array is consumed.
    4. If larger array is not consumed (>= 0) and prev carry exists, add with no regard to prev carry method, making prev carry the operand.
    5. In the end, if prev_carry remains with both arrays consumed, add it too.
*/

// Alternate : Pad the smaller array (not necessay).

/*
Better method:
    Sum using formula in electronics : a XOR b XOR c where c is carry
    The new carry is : (a AND b) OR ( b AND c ) OR ( c AND a )
*/

#include <bits/stdc++.h>
using namespace std;

string a, b;

void add(vector<char> &sum) {

    int bsize = b.size()-1;
    int asize = a.size()-1;

    bool carry = false;
    bool prev_carry = false;

    char temp;

    while(bsize>=0) {
        temp = (a[asize] - b[bsize] == 0) ? '0' : '1';

        // Addition with no regard to previous carry, deciding temp and the next carry
        carry = false;
        if(a[asize] == '1' && b[bsize] == '1') carry = true;

        // Modifying considering previous carry and setting the next carry
        if (temp == '0' && prev_carry) { temp = '1';}
        else if (temp == '1' && prev_carry) {temp =  '0'; carry = true;}

        // Storing the result and moving to the next interation
        sum.push_back(temp);
        asize--;
        bsize--;
        cout << "1. Adding " << a[asize+1] << " + " << b[bsize+1] << " + " << prev_carry << " = " << temp << " " << carry << endl;
        prev_carry = carry;
    }

    if (prev_carry) sum.push_back('1');
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    cin >> a >> b;
	    cout << "Check " << a << b << endl;
	    int diff = a.size() - b.size();

        if(diff > 0) {
            vector<char> v(diff, '0');
            b = string(v.begin(), v.end()) + b;
        } else {
            vector<char> v(-diff, '0');
            a = string(v.begin(), v.end()) + a;
        }

	    vector<char> sum;
	    add(sum);

	    for(int i=sum.size()-1; i>=0; i--) {
	        cout << sum[i];
	    }
	    cout << endl;
	}
	return 0;
}


/*
A working solution, without the padding. A lot faster.

#include <bits/stdc++.h>
using namespace std;

string a, b;

void add(vector<char> &sum) {

    int bsize = b.size()-1;
    int asize = a.size()-1;

    bool carry = false;
    bool prev_carry = false;

    char temp;

    while(bsize>=0) {
        temp = (a[asize] - b[bsize] == 0) ? '0' : '1';

        // Addition with no regard to previous carry
        carry = false;
        if(a[asize] == '1' && b[bsize] == '1') carry = true;

        // Modifying considering previous carry
        if (temp == '0' && prev_carry) temp = '1';
        else if (temp == '1' && prev_carry) {temp =  '0'; carry = true;}

        // Storing the result and moving to the next interation
        sum.push_back(temp);
        asize--;
        bsize--;
        // cout << "1. Adding " << a[asize+1] << " + " << b[bsize+1] << " + " << prev_carry << " = " << temp << " " << carry << endl;
        prev_carry = carry;
    }

    char lcarry;
    while(asize>=0 && prev_carry) {
        lcarry = (prev_carry) ? '1' : '0';
        temp = (a[asize] - lcarry == 0) ? '0' : '1';

        if(a[asize] == '1' && lcarry == '1') prev_carry = true;
        else prev_carry = false;

        // cout << "2. Adding " << a[asize+1] << " + " << lcarry << " = " << temp << " " <<  prev_carry << endl;

        sum.push_back(temp);
        asize--;
    }

    while(asize>=0) {
        sum.push_back(a[asize--]);
    }

    if (prev_carry) sum.push_back('1');
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a.size() < b.size()) {
            swap(a,b); // could do better performance wise
        }

        vector<char> sum;
        add(sum);

        for(int i=sum.size()-1; i>=0; i--) {
            cout << sum[i];
        }
        cout << endl;
    }
    return 0;
}

*/