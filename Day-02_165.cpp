/*
165. Compare Version Numbers
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.
*/
class Solution
{
public:
    int compareVersion(string v1, string v2)
    {
        int i=0, j=0, n=v1.size(), m=v2.size();
        int mx1=0, mx2=0;
        while(i<n or j<m)
        {
            int k=i;
            while(k<n and v1[k]!='.')
            {
                mx1=mx1*10+(v1[k]-'0'), k++;
            }
            i=k+1, k=j;
            while(k<m and v2[k]!='.')
            {
                mx2=mx2*10+(v2[k]-'0'), k++;
            }
            j=k+1;
            if(mx1>mx2) return 1;
            if(mx2>mx1) return -1;
            mx1=0, mx2=0;
        }
        return 0;
    }
};

