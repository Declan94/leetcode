class Solution {
public:
	int reverse(int x) {
		int y = abs(x);
		long rx = 0;
		int sign = x == 0 ? 0 : y / x;
		while (y > 0) {
			int digi = y % 10;
			rx = rx * 10 + digi;
			if (rx > INT_MAX) return 0;
			y = y / 10;
		}
		return sign * rx;
	}
};