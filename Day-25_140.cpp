/*
140. Word Break II
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/
class Solution {
public:
    vector<string>ans;
    unordered_set<string>st;
    void solve(int i, string& cur, string& s)
    {
        if(i>=s.size())
        {
            ans.push_back(cur);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            string sub=s.substr(i, j-i+1);
            if(st.count(sub))
            {
                string temp=cur;
                if(!cur.empty()) cur+=' ';
                cur+=sub;
                solve(j+1, cur, s);
                cur=temp;
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string cur="";
        for(auto it:wordDict)
        {
            st.insert(it);
        }
        solve(0, cur, s);
        return ans;
        
    }
};
