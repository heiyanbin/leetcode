// 90
// Subsets II
// https://leetcode.com//problems/subsets-ii/
class Solution{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> x(S.size());
        sort(S.begin(),S.end());
        int i=0;
        for(int j=0,c=1;j<S.size();j++)//calculate how many times an item could be selected
        {
            if(i==0 || S[j]!=S[i-1])
            {
                S[i]=S[j];
                selectCount.push_back(1);
                i++;
            }
            else
                selectCount[i-1]++;
        }
        vector<int> S2(S.begin(),S.begin()+i);
        select(S2,0,x,0);
        return v;
    }
    void select(vector<int> &S, int i, vector<int> &x, int index) //based on select or not
    {
        if(i>=S.size())
            v.push_back(vector<int>(x.begin(),x.begin()+index));
        else
        {
            select(S,i+1,x,index);
            if(selectCount[i]>0)
            {
                x[index]= S[i];
                selectCount[i]--;
                select(S,i,x,index+1);
                selectCount[i]++;
            }
        }
    }
    
private:
    vector<vector<int>> v;
    vector<int> selectCount;
};