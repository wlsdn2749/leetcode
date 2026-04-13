class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::unordered_set<int> s;
        for(int i=0; i<=nums.size(); i++)
        {
            s.emplace(i);
        }
        for(const auto num : nums)
        {
            s.erase(num);
        }

        int result = 0;
        for(const auto num : s)
        {
            result = num;
        }       

        return result;
        
    }
};