class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> result;
        map<int, int> index;
        for (int i=0; i<nums.size(); i++)
        {
        	if (index[target-nums[i]]) {
        		result.push_back(index[target-nums[i]]);
        		result.push_back(i+1);
        		return result;
        	}
        	index[nums[i]] = i+1;
        }
        return result;
    }
};