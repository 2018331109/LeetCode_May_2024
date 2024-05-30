/*
2597. The Number of Beautiful Subsets
You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
*/

class Solution {
public:
    int ans, x;
    void solve(int i, vector<int>& nums, unordered_map<int, int>& mp)
    {
        if(i>=nums.size())
        {
            ans++;
            return;
        }
        //taken:
        if(!mp[nums[i]-x] and !mp[nums[i]+x])
        {
            mp[nums[i]]++;
            solve(i+1, nums, mp);
            mp[nums[i]]--;
        }
        //not taken:
        solve(i+1, nums, mp);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        ans=0, x=k;
        unordered_map<int, int>mp;
        solve(0, nums, mp);
        return ans-1;
    }
};
