// 15
// 3Sum
// https://leetcode.com//problems/3sum/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if(num.size()<3) return output;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-2;i++)
        {
            if(i!=0 && num[i]==num[i-1])
                continue;
            int front = i+1,rear = num.size()-1;
            while(front<rear)
            {
                int sum = num[i]+num[front]+num[rear];
                if(sum==0)
                {
                    output.push_back({num[i],num[front],num[rear]});
                    front++;rear--;
                    while(front<rear && num[front]==num[front-1])
                        front++;
                    while(front<rear && num[rear]==num[rear+1])
                        rear--;
                }
                else if(sum<0)
                    front++;
                else
                    rear--;
            }
        }
        return output;
    }
   
private:
    vector<vector<int>> output;
};