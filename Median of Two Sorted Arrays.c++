class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            int maxLeftX = (partitionX == 0)
                           ? INT_MIN : nums1[partitionX - 1];

            int minRightX = (partitionX == m)
                            ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0)
                           ? INT_MIN : nums2[partitionY - 1];

            int minRightY = (partitionY == n)
                            ? INT_MAX : nums2[partitionY];

            // Correct partition found
            if (maxLeftX <= minRightY &&
                maxLeftY <= minRightX) {

                // Odd total number of elements
                if ((m + n) % 2 == 1) {
                    return max(maxLeftX, maxLeftY);
                }

                // Even total number of elements
                return (max(maxLeftX, maxLeftY) +
                        min(minRightX, minRightY)) / 2.0;
            }

            // Move binary search to the left
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }

            // Move binary search to the right
            else {
                low = partitionX + 1;
            }
        }

        return 0.0;
    }
};
