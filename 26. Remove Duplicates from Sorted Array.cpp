class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.empty())
    		return 0;
        int count = 1, p = 0;
        for (auto x : nums) {
        	if (x > nums[p]) {
        		nums[++p] = x;
        		count ++;
        	}
        }
        return count;
    }
};