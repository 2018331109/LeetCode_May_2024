/*
506. Relative Ranks
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

    The 1st place athlete's rank is "Gold Medal".
    The 2nd place athlete's rank is "Silver Medal".
    The 3rd place athlete's rank is "Bronze Medal".
    For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").

Return an array answer of size n where answer[i] is the rank of the ith athlete.
*/
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        int n=score.size();
        vector<string>ans(n);
        priority_queue<pair<int, int>>maxHeap;
        for(int i=0; i<n; i++)
        {
            maxHeap.push({score[i], i});
        }
        vector<string>rnk= {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int cnt=0;
        while(!maxHeap.empty())
        {
            auto top=maxHeap.top();
            maxHeap.pop();
            int ind=top.second;
            if(cnt<3)
            {
                ans[ind]=rnk[cnt];
            }
            else
            {
                ans[ind]=to_string(cnt+1);
            }
            cnt++;
        }
        return ans;
    }
};

