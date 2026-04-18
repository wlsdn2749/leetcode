class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        const string& s = (str1.length() <= str2.length()) ? str2 : str1;
        const string& t = (str1.length() <= str2.length()) ? str1 : str2;

        int sl = s.length();
        int tl = t.length();

        string result;

        for(int i=0; i<tl; i++)
        {
            if(!IsGcd(s, t, i)) continue;

            result.clear();
            for(int j=0; j<=i; j++)
                result += t[j];
        }

        return result;
    }

    bool IsGcd(const string& s, const string& t, int tl)
    {
        // check t[0:tl] divides s
        //
        if(s.length() % (tl+1) != 0) return false;
        if(t.length() % (tl+1) != 0) return false;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != t[i%(tl+1)])
            {
                return false;
            }
        }

       for(int i=0; i<t.length(); i++)
        {
            if(t[i] != t[i%(tl+1)])
            {
                return false;
            }
        }

        return true;
    }
};

// ABC, ABCABC
// 1. check shorted
// 2. shroted's ~1 to ~n (if successed)
// 3. it's gcd (if failed)
