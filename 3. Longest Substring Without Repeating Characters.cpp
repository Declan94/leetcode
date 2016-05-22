class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	map<char, int> hash;
    	int start = 0;
    	int len = 0;
    	int maxlen = 0;
        for (int i=0; i<s.length(); i++) {
        	if (hash.find(s[i]) != hash.end()) {
        		maxlen = len > maxlen ? len : maxlen;
        		len = i - hash[s[i]];
        		for (int j = start; j < hash[s[i]]; j++) {
        			hash.erase(s[j]);
        		}
        		start = hash[s[i]] + 1;
        	} else {
        		len ++;
        	}
        	hash[s[i]] = i;
        }
        maxlen = len > maxlen ? len : maxlen;
        return maxlen;
    }
};