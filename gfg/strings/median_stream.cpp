#include <bits/stdc++.h>
using namespace std;

// This is a std::set (BST) based solution, which relies on maintaining  two separate sets for
// storing the first half and the second half of all the elements.
// MID = ceil(count/2.0)
// This mid serves as the cornerstone of addition of elements
// If a.size() < MID ----> see if it goes into a or b
// else see if it goes into a or b
// Best practice would be maintain a table to store
// count | a.size() prev | b.size() prev | MID | inserted into (a/b) ?
// Dry run this

// Heap based solution is similar to this -> log n based addition and removal

#define MID ceil(_count/2.0)
#define CHECKNULL {}

multiset<int> a, b;
multiset<int> :: iterator it;
int _count;

int getfirst(int which) {
    switch(which) {
        case 1:
        		if (a.empty()) return 0;
        		it = a.begin();
                break;
        case 2:
        		if (b.empty()) return 0;
        		it = b.begin();
                break;
        default: return -1;
    }
    return *it;
}

int getlast(int which) {
    switch(which) {
        case 1:
        		if (a.empty()) return 0;
        		it = a.end();
                break;
        case 2:
        		if (b.empty()) return 0;
        		it = b.end();
                break;
        default: return -1;
    }
    it--;
    return *it;
}

int poplast(int which) {
    int temp;
    switch(which) {
        case 1:
        		if (a.empty()) return 0;
        		it = a.end();
                it--;
                temp = *it;
                a.erase(it);
                break;
        case 2:
				if (b.empty()) return 0;
				it = b.end();
                it--;
                temp = *it;
                b.erase(it);
                break;
        default: return -1;
    }
    return temp;
}

int popfirst(int which) {
    int temp;
    switch(which) {
        case 1:
                if (a.empty()) return 0;
                it = a.begin();
                temp = *it;
                a.erase(it);
                break;
        case 2:
                if (b.empty()) return 0;
                it = b.first();
                temp = *it;
                b.erase(it);
                break;
        default: return -1;
    }
    return temp;
}

int main() {
    int n;
    cin >> n;
    int x;
    while(n--) {
        cin >> x;
        _count ++;

        // cout << a.size() << " | " << b.size() << " +++ " << MID << " " << _count << endl;

        if(a.size() < MID) {
            if (b.size() != 0) {
                int temp = getfirst(2);
                if (temp < x) {
                    temp = popfirst(2);
                    swap(temp, x);
                    b.insert(temp);
                }
            }
            a.insert(x);
        }
        else if(a.size() >= MID) {
        	// cout << getlast(1) << " < " << x << endl;
            if (x > getlast(1)) {
                b.insert(x);
            }
            else{
                int elem = poplast(1);
            	// cout << "Here " << elem << endl;
                b.insert(elem);
                a.insert(x);
            }
        }

        if (_count%2 != 0) {
            cout << getlast(1) << endl;
        }
        else {
            cout << (getlast(1) + getfirst(2))/2.0 << endl;
        }
    }
}


/*

Count sort based

#include <bits/stdc++.h>
using namespace std;

const int size = (1e5) + 10;
int arr[size];

int main(int argc, char const *argv[])
{
	memset(arr, 0, sizeof arr);
	int n;
	cin >> n;
	int count = 0;
	while(n--) {
		int x;
		cin >> x;
		arr[x] += 1;
		count += 1;

		int mid = count/2;
	}

	return 0;
}

*/

/*

Insertion sort method O(n^2) complexity

#include <iostream>
using namespace std;

const int asize = (int)1e5 + 10;

int arr[asize];
int _end;

int main() {
	int n, x;
	scanf("%d", &n);
    scanf("%d", &arr[0]);
	n -= 1;
	_end = 0;
	cout << arr[0] << endl;
	while(n--) {
	    scanf("%d", &x);

	    int last = _end;
	    while(last>=0 && arr[last] > x) {
            arr[last+1] = arr[last];
            last--;
        }

        arr[last+1] = x;
        _end++;

	    int size = (_end+1)/2;

	    if((_end+1)%2 == 0) {
	        cout << (arr[size] + arr[size-1])/2.0 << endl;
	    }
	    else {
	        cout << arr[size] << endl;
	    }
	}
	return 0;
}*/