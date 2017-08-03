#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upper_bound(vector<int> &nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        if (high == 0)
            return (nums[0] == target) ? 0 : -1;

        while(low < high) {
            mid = (low+high+1)/2;
            if (nums[mid] == target) {
                low = mid;
            }
            if (nums[mid] > target) {
                high = mid-1;
            }
            if (nums[mid] < target) {
                low = mid+1;
            }
        }
        return (nums[high] == target) ? high : -1;
    }

    int lower_bound(vector<int> &nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        if (high == 0)
            return (nums[high] == target) ? 0 : -1;

        while(low < high) {
            mid = (low+high)/2;
            if (nums[mid] == target)
                high = mid;
            if (nums[mid] < target)
                low = mid+1;
            if (nums[mid] > target)
                high = mid-1;
        }
        return (nums[mid] == target) ? mid : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int upper = upper_bound(nums, target);
        int lower = lower_bound(nums, target);
        vector<int> ans;
        ans.push_back(lower);
        ans.push_back(upper);
        return ans;
    }
};