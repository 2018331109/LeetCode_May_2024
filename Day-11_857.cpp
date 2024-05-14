/*
857. Minimum Cost to Hire K Workers
There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

    Every worker in the paid group must be paid at least their minimum wage expectation.
    In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.

Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.
*/
class Solution
{
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k)
    {
        int n=quality.size();
        double result=DBL_MAX;
        vector<pair<double, int>>rat(n);
        for(int i=0; i<n; i++)
        {
            rat[i]=make_pair((double)wage[i]/quality[i], quality[i]);
        }
        sort(rat.begin(), rat.end());
        priority_queue<int, vector<int>>pq;
        double sum=0;
        for(int i=0; i<k; i++)
        {
            pq.push(rat[i].second);
            sum+=rat[i].second;
        }
        double manager=rat[k-1].first;
        result=manager*sum;
        for(int i=k; i<n; i++)
        {
            manager=rat[i].first;
            pq.push(rat[i].second);
            sum+=rat[i].second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            result=min(result, manager*sum);
        }
        return result;
    }
};

