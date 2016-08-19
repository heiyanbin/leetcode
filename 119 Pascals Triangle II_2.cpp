// 119
// Pascals Triangle II
// https://leetcode.com//problems/pascals-triangle-ii/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lastRow;
        if(rowIndex<0) return lastRow;
        lastRow.push_back(1);
        for(int k=1;k<=rowIndex; k++)
        {
            vector<int> row;
            row.push_back(1);
            for(int j=1;j<k;j++)
            {
                row.push_back(lastRow[j-1]+lastRow[j]);
            }
            row.push_back(1);
            lastRow = row;
        }
        return lastRow;
    }
};