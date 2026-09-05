class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int p1 = (low + high) / 2;
            int p2 = (m + n + 1) / 2 - p1;

            int l1 = (p1 == 0) ? INT_MIN : nums1[p1 - 1];
            int r1 = (p1 == m) ? INT_MAX : nums1[p1];

            int l2 = (p2 == 0) ? INT_MIN : nums2[p2 - 1];
            int r2 = (p2 == n) ? INT_MAX : nums2[p2];

            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 1)
                    return max(l1, l2);

                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) {
                high = p1 - 1;
            }
            else {
                low = p1 + 1;
            }
        }

        return 0.0;
    }
};