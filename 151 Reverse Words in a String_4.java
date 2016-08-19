// 151
// Reverse Words in a String
// https://leetcode.com//problems/reverse-words-in-a-string/
class Solution {
    public String reverseWords(String s) {
        if(s==null) return null;
        if(s.trim().equals("")) return "";
        char[] a = s.trim().toCharArray();
        char prev=' ';
        int wordStart=0;
        while(wordStart<a.length && isSeparator(a[wordStart]))
            wordStart++;
        for(int i=wordStart;i<a.length;i++)
        {
            if(isSeparator(prev)&&!isSeparator(a[i]))
                wordStart=i;
            if(!isSeparator(a[i]) && (i+1==a.length || isSeparator(a[i+1])))
            {
                int k=wordStart, j=i;
                while(k<j)
                {
                    char temp=a[k];
                    a[k]=a[j];
                    a[j]=temp;
                    k++;j--;
                }
            }
            prev=a[i];
        }
        StringBuffer sb = new StringBuffer();
        prev=' ';
        for(int i=a.length-1;i>=0;i--)
        {
            if(!isSeparator(a[i]) || !isSeparator(prev))
            {
                sb.append(a[i]);
                prev=a[i];
            }
        }
        return sb.toString();
    }
    
    private boolean isSeparator(char c)
    {
        return c==' ';
    }
}