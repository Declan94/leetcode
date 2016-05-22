class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int ret = 0, min_diff = INT_MAX;
		for (int i = 0; i < len-2; ++i)
		{
			if (i > 0 && nums[i] == nums[i-1]) continue;
			int j = i+1, k = len-1;
			while (j < k) {
				int sum = nums[j]+nums[k]+nums[i];
				int diff = abs(sum - target);
				if (diff < min_diff) {
					ret = sum;
					min_diff = diff;
				}
				if (sum > target)
					k --;
				else if (sum < target)
					j ++;
				else 
					break;
			}
			if (min_diff == 0) break;
		}
		return ret;
	}
};