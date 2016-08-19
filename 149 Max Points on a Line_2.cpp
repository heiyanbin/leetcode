// 149
// Max Points on a Line
// https://leetcode.com//problems/max-points-on-a-line/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {  
public:  
    int maxPoints(vector<Point> &points) {  
        int n = points.size();
        if(n<=2)
            return n;
        int maxCount = 0;
        map<double,int> mp;
        for(int i=0;i<n-1;i++)
        {
            int duplicates = 0;
            mp.clear();
            for(int j=i+1;j<n;j++)
            {
                if(points[j].x==points[i].x && points[j].y==points[i].y)
                {
                    duplicates++;
                    continue;
                }               
                double a;
                if(points[j].x==points[i].x)
                    a = INT_MAX;
                else
                    a = (double)(points[j].y-points[i].y)/(points[j].x-points[i].x);
                mp[a]++;
            }
            if(mp.size()>0)
            {
                for(map<double,int>::iterator it = mp.begin();it!=mp.end();it++)
                {
                    if(it->second + duplicates +1>maxCount)
                        maxCount = it->second + duplicates +1;
                }
            }
            else
            {
                if((duplicates+1)>maxCount)
                    maxCount = duplicates+1;
            }
        }
        return maxCount;
    }  
};  