// 174
// Dungeon Game
// https://leetcode.com//problems/dungeon-game/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        assert(dungeon.size() > 0 && dungeon[0].size() > 0);
        for (int i = dungeon.size() - 1; i >=0  ; --i) {
            for (int j = dungeon[i].size() - 1; j >= 0; --j) {
                dungeon[i][j] = -dungeon[i][j] + 1;
                if (i < dungeon.size() - 1 && j < dungeon[i].size() - 1) 
                    dungeon[i][j] = max(dungeon[i][j], dungeon[i][j] + min (dungeon[i + 1][j] - 1, dungeon[i][j + 1] - 1 ));
                else if (i < dungeon.size() - 1)
                    dungeon[i][j] = max(dungeon[i][j], dungeon[i][j] + dungeon[i + 1][j] - 1);
                else if (j < dungeon[i].size() - 1)
                    dungeon[i][j] = max(dungeon[i][j], dungeon[i][j] + dungeon[i][j + 1] - 1);
            }
        }
        return dungeon[0][0] <= 0 ? 1 : dungeon[0][0];
    }
};