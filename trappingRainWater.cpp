class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prefix;
        vector<int>suffix;
        int maxi=0;
        for(int i=0;i<height.size();i++){
            maxi=max(maxi,height[i]);
            prefix.push_back(maxi);
        }
        maxi=0;
        for(int i=height.size()-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            suffix.push_back(maxi);
        }
        int res=0;
        reverse(suffix.begin(),suffix.end());
        for(int i=0;i<height.size();i++){
            res+=(min(prefix[i],suffix[i])-height[i]);
        }
        return res;
    }
};
