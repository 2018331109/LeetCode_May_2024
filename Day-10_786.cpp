/*
786. K-th Smallest Prime Fraction
You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
*/
class Solution
{
public:
    typedef vector<double> V;

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        priority_queue<V, vector<V>, greater<V>>pq;
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            pq.push({1.0*arr[i]/arr[n-1], (double)i, (double)n-1});
        }
        int cnt=1;
        while(cnt<k)
        {
            V vec=pq.top();
            pq.pop();
            int i=vec[1], j=vec[2]-1;
            pq.push({1.0*arr[i]/arr[j], (double)i, (double)j});
            cnt++;
        }
        V vec=pq.top();
        int i=vec[1], j=vec[2];
        return {arr[i], arr[j]};

    }
};

