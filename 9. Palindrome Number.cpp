class Solution {
public:
    bool isPalindrome(int x) {
    	if (x < 0) return false;
        int d = 1, xx = x;
        while (xx > 9) {
        	d *= 10;
        	xx /= 10;
        }
        while (x > 0) {
        	if (x % 10 != x / d) return false;
        	x = (x % d) / 10;
        	d = d / 100;
        }
        return true;
    }
};