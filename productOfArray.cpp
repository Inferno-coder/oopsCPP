class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix;
        vector<int>suffix;
        int sz=nums.size();
        int pro1=1,pro2=1;
        for(int i=0;i<sz;i++){
         pro1*=nums[i];
         prefix.push_back(pro1);
         pro2*=nums[sz-1-i];
         suffix.insert(suffix.begin(),pro2);
        }
        vector<int>ans;
        ans.push_back(suffix[1]);
        for(int i=1;i<sz-1;i++){
          ans.push_back(prefix[i-1]*suffix[i+1]);
        }
        ans.push_back(prefix[sz-2]);
        return ans;
    }
};
