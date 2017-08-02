#include <bits/stdc++.h>
using namespace std;

int pivot (vector<int>& nums) {
    int size = nums.size();
    int seed = nums[size-1];
    if (nums[0] <= seed) return 0;

    int low = 0, high = size-1, mid;

    while(low <= high) {
        mid = (low + high) / 2;
        cout << "Pivot :: low: " << low  << " " << nums[low] << " high: " << high << " " << nums[high] << " mid " << mid << " " << nums[mid] << endl;
        if (nums[mid] < nums[mid-1]) return mid;
        if (nums[mid] < seed) high = mid;
        if (nums[mid] > seed) low = mid+1;
    }
    return mid;
}

int _search(vector<int> &nums, int low, int high, int seed) {
    if (low > high) return -1;
    int mid;
    while(low <= high) {
        mid = (low+high)/2;

        cout << "low: " << low  << " " << nums[low] << " high: " << high << " " << nums[high] << " mid " << mid << " " << nums[mid] << endl;

        if (nums[mid] == seed) return mid;
        if (nums[mid] < seed) low = mid+1;
        if (nums[mid] > seed) high = mid-1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums;
    int size, temp;
    cin >> size;
    for(int i=0; i<size; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    int p =  pivot(nums);
    cout << p << endl;

    int target;
    cin >> target;

    int ans = _search(nums, 0, p-1, target);
    if(ans == -1)
        ans = _search(nums, p, nums.size()-1, target);

    cout << ans << endl;

    return 0;
}