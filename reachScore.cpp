class Solution
{
    public:
    // Complete this function
    long long solve(int ind,vector<int>&arr,long long n,vector<vector<int>>&dp){
      if(n==0)return 1;
      if(ind<0 || n<0)return 0;
      if(dp[ind][n]!=-1)return dp[ind][n];
      int pick=0;
      if(arr[ind]<=n)pick=solve(ind,arr,n-arr[ind],dp);
      int notPick=solve(ind-1,arr,n,dp);
      return dp[ind][n]=pick+notPick;
    }
    
 
    
    long long int count(long long int n)
    {
    	// Your code here
    	vector<int>arr={3,5,10};
    	vector<vector<int>>dp(3,vector<int>(n+1,-1));
    	return solve(2,arr,n,dp);
    }
};
