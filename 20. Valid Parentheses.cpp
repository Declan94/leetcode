// class Solution {
// public:
//     bool isValid(string s) {
//     	int l = s.length();
//     	char * stack = new char[l];
//     	int top = -1;
//     	map<char, char> bracket_map;
//     	bracket_map[')'] = '(';
//     	bracket_map[']'] = '[';
//     	bracket_map['}'] = '{';
//     	for (auto c : s) {
//     		if (bracket_map.find(c) != bracket_map.end()) {
//     			if (top < 0 || stack[top] != bracket_map[c]) {
//     				return false;
//     			} else {
//     				top --;
//     			}
//     		} else {
//     			stack[++top] = c;
//     		}
//     	}
// 		delete stack;
//     	return top == -1;
//     }
// };

class Solution {
public:
    bool isValid(string s) {
    	vector<char> stack;
    	for (auto c : s) {
    		if (c == ')' || c == ']' || c == '}') {
    			if (stack.empty() || abs(c - stack.back()) > 2) {
    				return false;
    			} else {
    				stack.pop_back();
    			}
    		} else {
    			stack.push_back(c);
    		}
    	}
    	return stack.empty();
    }
};

