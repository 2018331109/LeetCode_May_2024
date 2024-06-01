/*
552. Student Attendance Record II
An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

    'A': Absent.
    'L': Late.
    'P': Present.

Any student is eligible for an attendance award if they meet both of the following criteria:

    The student was absent ('A') for strictly fewer than 2 days total.
    The student was never late ('L') for 3 or more consecutive days.

Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.
*/
//Recursion:
class Solution
{
public:
    int memo[100001][2][3];
    int mod=1e9+7;
    int solve(int n, int abs, int late)
    {
        if(abs>=2 or late>=3) return 0;
        if(n==0) return 1;
        if(memo[n][abs][late]!=-1)
        {
            return memo[n][abs][late];
        }
        int a=solve(n-1, abs+1, 0)%mod;
        int l=solve(n-1, abs, late+1)%mod;
        int p=solve(n-1, abs, 0)%mod;
        return memo[n][abs][late]=((a+l)%mod+p)%mod;
    }
    int checkRecord(int n)
    {
        memset(memo, -1, sizeof(memo));
        return solve(n, 0, 0);
    }
};
//DP
class Solution
{
public:
    int mod=1e9+7;
    int memo[100001][2][3];
    int checkRecord(int n)
    {
        for(int a=0; a<=1; a++)
        {
            for(int l=0; l<=2; l++)
            {
                memo[0][a][l]=1;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int a=0; a<=1; a++)
            {
                for(int l=0; l<=2; l++)
                {
                    long ans=memo[i-1][a][0];
                    ans+=(a+1<=1)? memo[i-1][a+1][0]: 0;
                    ans+=(l+1<=2)? memo[i-1][a][l+1]: 0;
                    memo[i][a][l]=ans%mod;
                }
            }
        }
        return memo[n][0][0];
    }
};

