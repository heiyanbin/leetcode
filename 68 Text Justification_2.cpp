// 68
// Text Justification
// https://leetcode.com//problems/text-justification/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        if(L==0) return vector<string>{""};
        vector<string> res, line;
        for(int i=0;i<words.size();)
        {
            line.clear();
            for(int count =0;count<L&&i<words.size();)
            {
                count+= (count==0? 0 :1) + words[i].size();
                if(count>L) break;
                line.push_back(words[i]);
                i++;
            }
            string s = line.size()==1 || i==words.size() ? right_pad(line,L): pad(line,L);
            res.push_back(s);   
        }
        return res;
    }
    string pad(vector<string> &words, int L)
    {
        int len = 0;
        for_each(words.begin(),words.end(),[&len](string &s)->void{len+=s.size();});
        int n = (L - len)/(words.size()-1), m = (L-len)%(words.size()-1);
        string s;
        for(int i=0;i<words.size()-1;++i)
        {
            s.append(words[i]);
            for(int j=0;j< n+ (i<m ? 1:0);++j )
                s.push_back(' ');
        }
        s.append(words[words.size()-1]);
        return s;
    }
    string right_pad(vector<string> &words,int L)
    {
        string s;
        for_each(words.begin(),words.end(),[&s](string &t)->void{s.append(t+" ");});
        s.pop_back();
        while(s.size()<L)
            s.push_back(' ');
        return s;
    }
};