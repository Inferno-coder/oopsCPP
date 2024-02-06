class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            int freq[26]={0};
            for(int j=0;j<temp.length();j++){
                freq[temp[j]-'a']++;
            }
            string str="";
            char alp='a';
            for(int j=0;j<26;j++){
            str+=alp;
            alp++;
            str+=to_string(freq[j]);
            }
            mp[str].push_back(temp);
        }

        vector<vector<string>>res;
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};
