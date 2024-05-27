/*
131. Palindrome Partitioning
Given a string s, partition s such that every
substring
of the partition is a
palindrome
. Return all possible palindrome partitioning of s.
*/
class Solution
{
public:
    int n;
    vector<vector<string>>ans;
    bool isPalindrome(string& s, int l, int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r]) return false;
            l++, r--;
        }
        return true;
    }
    void backtrack(string& s, int idx, vector<string>temp)
    {
        if(idx==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx; i<n; i++)
        {
            if(isPalindrome(s, idx, i))
            {
                temp.push_back(s.substr(idx, i-idx+1));
                backtrack(s, i+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        n=s.size();
        vector<string>temp;
        backtrack(s, 0, temp);
        return ans;
    }
};

