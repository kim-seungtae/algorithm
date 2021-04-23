class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2);
        vector<pair<int,int>> nums_idx(nums.size()); //원래 인덱스 같이 저장하는 vector
        for (int i=0; i<nums.size(); i++)
            nums_idx[i] = {nums[i], i};
        
        sort(nums_idx.begin(), nums_idx.end());
        
        int i=0, j=nums.size()-1;
        while(1) {
            if (nums_idx[i].first + nums_idx[j].first == target) {
                answer[0]=nums_idx[i].second;
                answer[1]=nums_idx[j].second;
                break;
            }
            else if (nums_idx[i].first + nums_idx[j].first > target) j--;
            else i++;
        }
        return answer;
    }
};