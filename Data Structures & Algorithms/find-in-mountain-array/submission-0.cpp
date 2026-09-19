/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
   public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int lo = 1, hi = n - 2;
        int peak;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            int left = mountainArr.get(m - 1);
            int mid = mountainArr.get(m);
            int right = mountainArr.get(m + 1);
            if (left < mid && mid < right) {
                lo = m + 1;
            } else if (left > mid && mid > right) {
                hi = m - 1;
            } else {
                peak = m;
                break;
            }
        }
        // search increasing part
        lo = 0, hi = peak;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            int val = mountainArr.get(m);
            if (val < target) {
                lo = m + 1;
            } else if (val > target) {
                hi = m - 1;
            } else {
                return m;
            }
        }
        lo = peak, hi = n - 1;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            int val = mountainArr.get(m);
            if (val < target) {
                hi = m - 1;
            } else if (val > target) {
                lo = m + 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};