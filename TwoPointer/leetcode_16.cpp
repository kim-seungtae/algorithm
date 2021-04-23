class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int s = nums.size(), diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i=0; i<s-2; i++) {
            int sum = target-nums[i], j=i+1, k=s-1;
            while (j<k) {
                if (nums[j] + nums[k] == sum) {
                    return target;
                } else if (nums[j] + nums[k] > sum) {
                    diff = abs(diff) > abs(nums[j]+nums[k]-sum) ? nums[j]+nums[k]-sum : diff;
                    k--;
                } else {
                    diff = abs(diff) > abs(nums[j]+nums[k]-sum) ? nums[j]+nums[k]-sum : diff;
                    j++;
                }
            }
        }
        return target+diff;
    }
};