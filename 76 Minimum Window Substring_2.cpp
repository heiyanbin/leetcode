// 76
// Minimum Window Substring
// https://leetcode.com//problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string S, string T) {
        if(S.size()<T.size()) return "";
        int expected_count[256], appeared_count[256];
        fill(expected_count,expected_count+256,0);
        fill(appeared_count,appeared_count+256,0);
        for(char c: T)
            expected_count[c]++;
        int min_start=0, min_len=INT_MAX, wnd_start=0, appeared=0;
        
        for(int wnd_end=0;wnd_end<S.size();wnd_end++)
        {
            if(expected_count[S[wnd_end]]>0)
            {
                appeared_count[S[wnd_end]]++;
                if(appeared_count[S[wnd_end]]<=expected_count[S[wnd_end]])
                    appeared++;
            }
            if(appeared==T.size())
            {
                while(expected_count[S[wnd_start]]==0||appeared_count[S[wnd_start]]>expected_count[S[wnd_start]])
                {
                    appeared_count[S[wnd_start]]--;
                    wnd_start++;
                }
                if(wnd_end-wnd_start+1<min_len)
                {
                    min_len= wnd_end-wnd_start+1;
                    min_start= wnd_start;
                }
            }
        }
        if(min_len==INT_MAX) return "";
        return S.substr(min_start, min_len);
    }
};