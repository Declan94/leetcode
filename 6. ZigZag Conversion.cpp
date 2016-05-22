class Solution {

public:
	string convert(string s, int numRows) {
		if (numRows == 1 || s.empty()) return s;
		string ret;
		int line_no = 0, i = 0;
		int step[2] = {numRows * 2 - 2, 0};
		bool pingpong = false;
		while (line_no < numRows && i < s.length()) {
			ret.push_back(s[i]);
			if (step[(int)pingpong] == 0) pingpong = !pingpong;
			i += step[(int)pingpong];
			pingpong = !pingpong;
			if (i >= s.length()) {
				line_no ++;
				step[0] -= 2;
				step[1] += 2;
				i = line_no;
				pingpong = false;
			}
		}
		return ret;
	}
};