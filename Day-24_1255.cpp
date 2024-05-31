/*
1255. Maximum Score Words Formed by Letters
Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.
*/
class Solution
{
public:
    int ans=INT_MIN, n;
    void solve(int i, vector<int>& score, vector<string>& words,int total, vector<int>& freq)
    {
        ans=max(ans, total);
        if(i>=n) return;
        int j=0, cnt=0;
        vector<int>temp=freq;
        for(auto it:words[i])
        {
            temp[it-'a']--;
            cnt+=score[it-'a'];
            if(temp[it-'a']<0) break;
            j++;
        }
        if(j==words[i].size())
        {
            solve(i+1, score, words, total+cnt, temp);
        }
        solve(i+1, score, words, total, freq);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        vector<int>freq(26, 0);
        for(auto it:letters)
        {
            freq[it-'a']++;
        }
        ans=INT_MIN, n=words.size();
        solve(0, score, words, 0, freq);
        return ans;
    }
};

