class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size(),0);
        prefix.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++) {
            prefix.push_back((nums[i]*prefix[i-1]));
        }
        suffix[suffix.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2; i>=0; i--) {
            suffix[i] = nums[i]*suffix[i+1];
        }
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int temp = 1;
            if(i==0) ans.push_back(suffix[i+1]);
            else if (i==nums.size()-1) ans.push_back(prefix[i-1]);
            else {
                temp *= (suffix[i+1]*prefix[i-1]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};