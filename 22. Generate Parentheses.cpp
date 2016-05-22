class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string>> all;
		char * temp = new char(n*2);
		vector<string> ps;
		if (n == 0) {
			return ps;
		}
		ps.push_back("()");
		all.push_back(ps);
		for (int i=1; i<n; i++) {
			ps.clear();
			for (int x1=0; x1<all[i-1].size(); x1++) {
				sprintf(temp, "(%s)", all[i-1][x1].c_str());
				string n(temp, i*2+2);
				ps.push_back(n);
			}
			for (int j=i-1; j>0; j--) {
				for (int x1=0; x1<all[j-1].size(); x1++) {
					for (int x2=0; x2<all[i-j-1].size(); x2++) {
						string s1 = all[j-1][x1];
						string s2 = all[i-j-1][x2];
						sprintf(temp, "(%s)%s", s1.c_str(), s2.c_str());
						string n(temp, i*2+2);
						ps.push_back(n);
					}
				}
			}
			for (int x2=0; x2<all[i-1].size(); x2++) {
				sprintf(temp, "()%s", all[i-1][x2].c_str());
				string n(temp, i*2+2);
				ps.push_back(n);
			}
			all.push_back(ps);
		}	
		delete temp;
		return ps; 
	}
};