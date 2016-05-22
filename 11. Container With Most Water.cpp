class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size()-1;
		int max = 0;
		while (left < right) {
			int lh = height[left], rh = height[right];
			int area = min(lh, rh) * (right - left);
			if (area > max) max = area;
			if (lh < rh) 
				while (left < right && height[left] <= lh) left ++;
			else 
				while (left < right && height[right] <= rh) right --;
		}
		return max;
	}
};