/*
1608. Special Array With X Elements Greater Than or Equal X
You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.
*/
class Solution
{
public:
    int specialArray(vector<int>& nums)
    {
        vector<int>v(1001, 0);
        for(auto it:nums)
        {
            v[it]++;
        }
        int total=nums.size();
        for(int i=0;i<=1000;i++)
        {
            if(i==total) return i;
            total-=v[i];
        }
        return -1;
    }
};

