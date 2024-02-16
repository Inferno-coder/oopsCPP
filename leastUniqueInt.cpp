class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        vector<pair<int,int>>vec;
        for(auto it:freq){
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),[](pair<int,int>a,pair<int,int>b){
         return a.second<b.second;
        });
        int i=0;
        int n=vec.size();
        for(i=0;i<vec.size();i++){
        auto temp=vec[i];
        int key=temp.first;
        int val=temp.second;
        if(k==0)return n-i;
        if(k>=val){
            k-=val;
            continue;
        }
        else{
            return (n-1)-i+1;
        }
        }
        return 0;
    }
};
