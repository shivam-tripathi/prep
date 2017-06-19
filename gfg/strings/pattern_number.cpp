#include <bits/stdc++.h>
using namespace std;

bool visited[10];
char temp[11];
char ans[11];
int ind;

// Finds the smallest count number of digits not yet visited and saves in temp array
void _set(int count) {
    int pos = count;
    for(int i=1; i <= ans[ind-1] && pos > 0; i++) {
        if(!visited[i]) {
            temp[count-pos] = i + '0';
            visited[i] = true;
            pos--;
        }
    }
}

// Inserts the temp ans of an action sequence
void insert(bool rev, int count) {
    if(rev) {
    	// If decreasing action, then the present number has to be bumbed up to the count size.
    	// This works because at the end of completion of any action we have exhausted all smallest size numbers
    	// To include decrease, we have to save the next frame of numbers, and to achieve this, we have to increase
    	// the end to include the frame.
    	// For any m size action string, only the first m+1 elements are used. This is why bumping works.
        visited[(int)(ans[ind-1] - '0')] = false;
        ans[ind-1] = ans[ind-1] + count;
        visited[(int)(ans[ind-1] - '0')] = true;
        _set(count);

        for(int i=count-1; i>=0; i--) {
            ans[ind++] = temp[i];
        }
    }
    else {
        _set(count);
        for(int i=0; i<count; i++) {
            ans[ind++] = temp[i];
        }
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;

	    // Inititialize data
	    int count = 1; // Stores count of series of I or D
	    bool inc = ((s[0] == 'I') ? true : false); // Stores if the present action is I
	    bool dec = ((inc) ? false : true); // Stores if the present action is D
	    memset(ans, '\0', sizeof ans); // Initialize ans to \0
	    memset(temp, '\0', sizeof temp); // Initialize temp storage for series of D or I to \0
	    memset(visited, false, sizeof visited); // Initialize visited to false
	    ind = 1; // Present active index is 1
	    ans[ind-1] = '1'; // First number is always 1
	    visited[1] = true; // We have therefore visited 1

	     // Loop over all actions. Answer is always of size s.size() + 1
	    for(int i=1; i<s.size(); i++) {

	            if ((inc && s[i] == 'I') || dec && s[i] == 'D')
	                count ++; // If present action is consistent with the previous action, continue

	            else if ((dec && s[i] == 'I') || (inc && s[i] == 'D')) { // If a mismatch occurs, compute the answer for the previous action
	                // insert inserts into ans depending on reverse of answer (D) is needed or direct (I)
	                (dec) ? insert(true, count) : insert(false, count);

	               	// Finally reset all values for next iteration, as we have already encountered one action of next iteration
	                count = 1;
	                swap(inc, dec);
	            }
	    }
	    (dec) ? insert(true, count) : insert(false, count);
	    cout << ans << endl;
	}
	return 0;
}