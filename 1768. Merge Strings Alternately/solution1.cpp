class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        
        int wl1 = word1.length();
        int wl2 = word2.length();

        if(wl1 <= wl2)
        {
