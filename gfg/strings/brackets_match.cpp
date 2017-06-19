#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
	    string s;
	    cin >> s;
	    bool flag = true;
	    stack<char> brackets;
	    for(int i=0; i<s.size(); i++) {
	        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
	            brackets.push(s[i]);
	        }
	        else {
	        	if (brackets.empty()) {
	        		flag = false;
	        		break;
	        	}
	            if (s[i] == '}') {
	                if (brackets.top() != '{') {
	                    flag = false;
	                    break;
	                } else if (brackets.top() == '{') {
	                    brackets.pop();
	                    continue;
	                }
	            }

	            if (s[i] == ']') {
	                if (brackets.top() != '[') {
	                    flag = false;
	                    break;
	                } else if (brackets.top() == '[') {
	                    brackets.pop();
	                    continue;
	                }
	            }

	            if (s[i] == ')') {
	                if (brackets.top() != '(') {
	                    flag = false;
	                    break;
	                } else if (brackets.top() == '(') {
	                    brackets.pop();
	                    continue;
	                }
	            }
	        }
	    }
	    if (flag && brackets.empty()) {
	        cout << "balanced" << endl;
	    } else cout << "unbalanced" << endl;
	}
	return 0;
}

// Always check if you're exceeding index limits. Same goes for stack too.
// Check if you're not poping from empty stack. Also, check if stack is empty in the last.