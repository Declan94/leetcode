class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int min_l = INT_MAX;
		string prefix;
		for (auto &s : strs) {
			if (s.length() < min_l) {
				min_l = s.length();
				prefix = s;
			}
		}
		if (strs.size() == 0 || min_l == 0) return "";
		for (auto &s : strs) {
			int l;
			for (l=0; l<min_l; l++) {
				if (prefix[l] != s[l]) {
					min_l = l;
					prefix = prefix.substr(0, l);
					break;
				}
			}
		}
		return prefix;
	}
};

// class Solution {
// public:
// 	string longestCommonPrefix(vector<string>& strs) {
// 		int min_l = INT_MAX;
// 		for (auto s:strs) {
// 			if (s.length() < min_l) {
// 				min_l = s.length();
// 			}
// 		}
// 		if (strs.size() == 0 || min_l == 0) return "";
// 		int l = 0, r = min_l;
// 		while (l < r) {
// 			int m = (l + r) / 2 + 1;
// 			string temp = strs[0].substr(l, m-l);
// 			bool satisfy = true;
// 			for (auto s:strs) {
// 				if (s.compare(l, m-l, temp) != 0) {
// 					satisfy = false;
// 					break;
// 				}
// 			}
// 			if (satisfy) {
// 				l = m;
// 			} else {
// 				r = m-1;
// 			}
// 		}
// 		return strs[0].substr(0, l);
// 	}
// };