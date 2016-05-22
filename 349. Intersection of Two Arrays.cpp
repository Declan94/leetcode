class Solution {
public:
    void mergeSort(std::vector<int> &nums, int l, int r) {
        if (l + 1 >= r) return;
        int m = (l + r) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m, r);
        merge(nums, l, m, r);
    }

    void merge(std::vector<int> &nums, int l, int m, int r) {
        int n1 = m - l;
        int n2 = r - m;
        int * a1 = new int[n1];
        int * a2 = new int[n2];
        for (int i = 0; i < n1; ++i) {
            a1[i] = nums[l+i];
        }
        for (int i = 0; i < n2; ++i) {
            a2[i] = nums[m+i];
        }
        int p = 0, q = 0;
        for (int i = l; i < r; ++i) {
            if (p == n1) {
                nums[i] = a2[q++];
            } else if (q == n2) {
                nums[i] = a1[p++];
            } else if (a1[p] <= a2[q]) {
                nums[i] = a1[p++];
            } else {
                nums[i] = a2[q++];
            }
        }
        delete [] a1;
        delete [] a2;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        mergeSort(nums1, 0, nums1.size());
        mergeSort(nums2, 0, nums2.size());
        std::vector<int> ret;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                int x = nums1[i];
                ret.push_back(x);
                while (i < nums1.size() && nums1[i] == x) i ++;
                while (j < nums2.size() && nums2[j] == x) j ++;
            } else if (nums1[i] < nums2[j]) {
                i ++;
            } else {
                j ++;
            }
        }
        return ret;
    }
};


