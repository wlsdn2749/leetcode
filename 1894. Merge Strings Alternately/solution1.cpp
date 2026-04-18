class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        
        int wl1 = word1.length();
        int wl2 = word2.length();

        if(wl1 <= wl2)
        {
            for(int i = 0; i < wl1; i++)
            {
                result += word1[i];
                result += word2[i];        
            }
            for(int i = wl1; i < wl2; i++)
            {
                result += word2[i];
            }
        }
        else
        {
            for(int i = 0; i < wl2; i++)
            {
                result += word1[i];
                result += word2[i];        
            }
            for(int i = wl2; i < wl1; i++)
            {
                result += word1[i];
            }
        }     
        return result;   
    }
};