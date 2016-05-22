class Solution {
public:
	
	bool isChMatch(char a, char p) {
		return a == p or p == '.';
	}

	string mySubStr(string s, int pos) {
		if (s.length() > 0) return s.substr(pos);
		else return s;
	}

	bool isMatch(string s, string p) {
		if (p.length() == 0)
			return s.length() == 0;
		if (p.length() == 1)
			return s.length() == 1 && isChMatch(s[0], p[0]);
		if (p[1] != '*') 
			return s.length() >= 1 && isChMatch(s[0], p[0]) && isMatch(s.substr(1), p.substr(1));
		int repeat = 0;
		while (repeat <= s.length()) {
			if (repeat > 0 && !isChMatch(s[repeat-1], p[0]))
				return false;
			if (isMatch(mySubStr(s, repeat), p.substr(2)))
				return true;
			repeat ++;
		}
		return false;
	}


};

// this method is slow, using index pointer instead of substr would be faster.