class Solution {
public:
vector<vector<int>> solve(vector<int>&nums,vector<vector<int>>&ans,int index,vector<int>&temp){
    //base case
    if(index>=nums.size()){
        ans.push_back(temp);
        return ans;
    }
    //exclude
    solve(nums,ans,index+1,temp);
    //include
    temp.push_back(nums[index]);
    solve(nums,ans,index+1,temp);
    //backtrack
    temp.pop_back();
    return ans;
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        ans=solve(nums,ans,0,temp);
        return ans;
    }
};
