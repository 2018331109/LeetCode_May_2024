/*
1002. Find Common Characters
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 100
    words[i] consists of lowercase English letters.

*/
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>v(26,INT_MAX);
        for(auto s:words)
        {
            vector<int>temp(26, 0);
            for(auto it:s) temp[it-'a']++;
            for(int i=0;i<26;i++) v[i]=min(v[i], temp[i]);
        }
        vector<string>ans;
        for(int i=0;i<26;i++)
        {
            while(--v[i]>=0) ans.push_back(string(1, (i+'a')));
        }
        return ans;
    }
};
