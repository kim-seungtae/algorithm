class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int s = nums.size();
        for (int i=0; i<s; i++)
            while (nums[i] > 0 && nums[i] <= s && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        
        for (int i=0; i<s; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return s+1;
    }
};


// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int s = nums.size();
//         sort(nums.begin(), nums.end());
        
//         int FMP = 1;
//         for (int i=0; i<s; i++) {
//             if (nums[i] > 0 && nums[i] == FMP) FMP++; 
//             if (nums[i] > FMP) break;
//         }
//         return FMP;
//     }
// };