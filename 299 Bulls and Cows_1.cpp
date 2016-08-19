// 299
// Bulls and Cows
// https://leetcode.com//problems/bulls-and-cows/
class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> counter;
        for (int i = 0; i < secret.length(); ++i) {
            counter[secret[i]]++;
        }
        int bulls = 0, cows = 0;
        vector<bool> marked(secret.size());
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
                counter[secret[i]]--;
                marked[i] = true;
            }
        }
        for (int i = 0; i < guess.size(); ++i) {
            if (!marked[i] && counter[guess[i]] > 0) {
                ++cows;
                counter[guess[i]]--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};