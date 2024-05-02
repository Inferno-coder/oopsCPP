class Solution {
public:
    int findMaxK(vector<int>& nums) {
     unordered_set<int>st;
     for(auto it:nums)st.insert(it);
     int maxi=-999;
     for(int i=0;i<nums.size();i++){
        if(nums[i]>0 && st.count(-(nums[i])))maxi=max(maxi,nums[i]);
     }
     return maxi==-999?-1:maxi;   
    }
};
