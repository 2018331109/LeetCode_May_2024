/*
1404. Number of Steps to Reduce a Number in Binary Representation to One
Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

    If the current number is even, you have to divide it by 2.

    If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.
*/
class Solution
{
public:
    int numSteps(string s)
    {
        int ans=0, n=s.size()-1, c=0;
        while(n>0)
        {
            if((s[n]-'0'+c)==2) ans+=1, c=1;
            else if((s[n]-'0'+c)==0) ans+=1, c=0;
            else ans+=2, c=1;
            n--;
        }
        return ans+=c;
    }
};

