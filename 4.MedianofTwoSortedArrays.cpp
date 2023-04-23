class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if(len % 2 == 0){
            return (getK(nums1, nums2, len/2) + getK(nums1, nums2, len/2 + 1)) / 2.0;
        } else {
            return getK(nums1, nums2, len/2 + 1);
        }
    }
    // 从nums1和nums2中找到第k小的值(k = 1 2 3 4 5 6 7...)
    int getK(vector<int>& nums1, vector<int>& nums2, int k){
        int m = nums1.size();
        int n = nums2.size();
        // i is the index of m, j is the index of n
        int i = 0, j = 0;  
        
        while(true){
            if(i == m) {
                return nums2[j + k - 1];
            }
            if(j == n){
                return nums1[i + k - 1];
            }
            if(k == 1){
                return min(nums1[i], nums2[j]);
            }

            int newi = min(i + k/2 - 1, m-1);
            int newj = min(j + k/2 - 1, n-1);
            int value1 = nums1[newi];
            int value2 = nums2[newj];
            if(value1 <= value2){
                k -= newi - i + 1;
                i = newi + 1;
            } else {
                k -= newj - j + 1;
                j = newj + 1;
            }
        }
    }
};
