class Solution {
public:
	void moveToLeft(vector<int>& nums, int l, int& r) {
		r --;
        while (l < r && nums[r] == nums[r+1]) r--;
	}

	void moveToRight(vector<int>& nums, int& l, int r) {
		l ++;
		while (l < r && nums[l] == nums[l-1]) l++;
	}

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ll, l, r, rr, subtarget;
        ll = 0;
        rr = nums.size()-1;
        int rbound = rr;
        vector<vector<int>> ret;
        while (ll + 2 < rr) {
        	l = ll + 1;
        	r = rr - 1;
        	subtarget = target - nums[ll] - nums[rr];
        	while (l < r) {
        		int sum = nums[l] + nums[r];
        		if (sum > subtarget) {
        			moveToLeft(nums, l, r);
        		} else if (sum < subtarget) {
        			moveToRight(nums, l, r);
        		} else {
        			ret.push_back({nums[ll], nums[l], nums[r], nums[rr]});
        			moveToLeft(nums, l, r);
        			moveToRight(nums, l, r);
        		}
        	}
        	moveToLeft(nums, ll+2, rr);
        	if (ll + 2 == rr || nums[ll] + nums[rr] + nums[rr-1] + nums[rr-2] < target) {
        		moveToRight(nums, ll, rbound-2);
        		int temp = nums[ll] + nums[ll+1] + nums[ll+2];
        		while (ll + 2 < rbound && temp + nums[rbound] > target) rbound--;
        		rr = rbound;
        	}
        }
        return ret;
    }
};