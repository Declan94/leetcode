class Solution {
	void search(string s, int p, int q, int &maxl, int& start) {
		while (p >= 0 && q < s.length() && s[p] == s[q]) {
			p --;
			q ++;
		}
		if (q-p-1 > maxl) {
   			maxl = q-p-1;
   			start = p+1;
		}
	}
public:
	string longestPalindrome(string s) {
		int maxl = 0;
		int start = 0;
		int strl = s.length();
		for (int i = 0; i < strl; ++i) {
			search(s, i, i, maxl, start);
			search(s, i, i+1, maxl, start);
		}
		return s.substr(start, maxl);
	}
};