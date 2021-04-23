class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int s = nums.size();
        vector<vector<int>> ans;
        if (s < 3) return ans;
        
        sort(nums.begin(), nums.end());
        for (int i=0; i<s-2; i++) {
            int target = -nums[i];
            int j=i+1, k=s-1;
            while (j<k) {
                if (nums[j] + nums[k] == target) {
                    ans.push_back(vector<int> {nums[i], nums[j], nums[k]});
                    while (j<k && nums[j] == nums[j+1]) j++;
                    while (j<k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > target) k--;
                else j++;
            }
            while (i<s-2 && nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
};