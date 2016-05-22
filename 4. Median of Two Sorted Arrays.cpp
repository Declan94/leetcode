class Solution {
	bool adjustSearchRange(vector<int>& nums1, vector<int>& nums2, int index, int& l1, int& r1, int m2, int &ret) {
		int s1 = nums1.size(), s2 = nums2.size();
		int m1 = (l1 + r1) / 2;
        int v1 = nums1[m1];
		int v2 = nums2[m2];
		int smaller_cnt = m1 + m2;	//count of numbers which <= v1
		int offset = 0;	// 0 means smaller_cnt is accurate, 1 means smaller_cnt is upper bound, -1 means smaller_cnt is lower bound
		if (m2 > 0 && v1 < nums2[m2-1]) {
			offset = 1;
		} else if (m2+1 < s2 && v1 > nums2[m2+1]) {
			offset = -1;
		} else if (v1 > v2) {
			smaller_cnt = m1 + m2 + 1;
		}
		if (offset == 0) {
			if (smaller_cnt == index || v1 == v2 && smaller_cnt == index - 1) {
				ret = v1;
				return true;
			}
			if (smaller_cnt < index) {
				l1 = min(m1+1, r1);
			} else {
				r1 = max(m1-1, l1);
			}
		} else if (offset > 0) {
			if (smaller_cnt <= index) {
				l1 = min(m1+1, r1);
			}
		} else if (offset < 0) {
			if (smaller_cnt >= index) {
				r1 = max(m1-1, l1);
			}
		}
		return false;
	}
	int findIndexNumber(vector<int>& nums1, vector<int>& nums2, int index) {
		int s1 = nums1.size(), s2 = nums2.size();
		int l1 = 0, r1 = s1-1, l2 = 0, r2 = s2-1;
		int ret;
        while (1) {
        	int m2 = (l2 + r2) / 2;
        	if (adjustSearchRange(nums1, nums2, index, l1, r1, m2, ret)) {
        		return ret;
        	}
        	int m1 = (l1 + r1) / 2;
        	// printf("%d %d, %d %d\n", l1, r1, l2, r2);
        	if (adjustSearchRange(nums2, nums1, index, l2, r2, m1, ret)) {
        		return ret;
        	}
        	// printf("%d %d, %d %d\n", l1, r1, l2, r2);
        	// printf("\n");
        }
	}
	double findSingleMedian(vector<int>& nums) {
		int s = nums.size();
		if (s % 2 == 1) {
			return nums[s/2];
		} else {
			return double(nums[s/2-1] + nums[s/2]) / 2;
		}
	}
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        if (s1 == 0) return findSingleMedian(nums2);
        if (s2 == 0) return findSingleMedian(nums1);
        int total = s1 + s2;
        if (total % 2 == 1) {
        	return findIndexNumber(nums1, nums2, total / 2);
        } else {
        	int mid1 = findIndexNumber(nums1, nums2, total / 2 - 1);
        	int mid2 = findIndexNumber(nums1, nums2, total / 2);
        	return double(mid1 + mid2) / 2;
        }
    }
};

