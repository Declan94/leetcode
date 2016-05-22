class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		vector<vector<int>> ret;
		for (int i = 0; i < len-2; ++i)
		{
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i-1]) continue;
			int j = i+1, k = len-1;
			while (j < k) {
				int sum = nums[j]+nums[k];
				if (sum > -nums[i])
					k --;
				else if (sum < -nums[i])
					j ++;
				else {
					ret.push_back({nums[i], nums[j], nums[k]});
					j++;
					while (nums[j] == nums[j-1] && j < k) j++;
					k--;
					while (nums[k] == nums[k+1] && j < k) k--;
				}
			}
		}
		return ret;
	}
};