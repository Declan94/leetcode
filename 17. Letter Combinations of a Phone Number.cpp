class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string d2l_map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string compressed;
        for (auto c : digits) {
        	if (c >= '2' && c <= '9')
        		compressed.push_back(c);
        }
        digits = compressed;
        int l = digits.length();
        int * stack = new int[l];
        int top = 0;
        stack[top] = -1;
        string str(l, 'a');
        vector<string> ret;
        while (top >= 0 && top < l) {
        	string &choices = d2l_map[int(digits[top]-'0')];
        	stack[top] ++;
        	if (stack[top] >= choices.length()) {
        		top --;
        	} else {
        		str[top] = choices[stack[top]];
        		if (top == l-1) {
        			ret.push_back(str);
        		} else {
        			stack[++top] = -1;
        		}
        	}
        }
        delete stack;
        return ret;
    }
};