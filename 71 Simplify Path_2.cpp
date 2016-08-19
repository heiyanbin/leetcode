// 71
// Simplify Path
// https://leetcode.com//problems/simplify-path/
class Solution {
public:
    string simplifyPath(string path) {
        int i=0, j=0;
        while(j<path.size())
        {
            if(path[j]!='.')
            {
                if(path[j]!='/'|| i-1<0 || path[i-1]!='/') //handle duplicate ///
                {
                    path[i]=path[j];
                    i++;
                }
                j++;
            }
            else if(j+1<path.size() && path[j+1]!='.' && path[j+1]!='/') //handle "/.hidden"
            {
                 path[i++]=path[j++];
            }
            else if(j+2<path.size() && path[j+1]=='.' && (path[j+2]=='.'||path[j+2]!='/')) //handle "/..." and "/..hidden"
            {
                for(int k=0;k<3;k++)
                    path[i++]=path[j++];
            }
            else if(j+1<path.size() && path[j+1]=='.')
            {
                if(i-2>=0)
                {
                    i=i-2;
                    while(i>=0 && path[i]!='/')
                        i--;
                    if(i<0)
                        i=0;
                    else if(i==0 && path[i]=='/')
                        i++;
                }
                j=j+2;                
            }
            else
            {
                if(i-1>0)
                    i--;
                j++;
            }
        }
        if(i-1>0 && path[i-1]=='/')
            i--;
        return string (path,0,i);
    }
};