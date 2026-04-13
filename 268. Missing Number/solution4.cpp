class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::unorderd_set<int> s;
        for(int i=0; i<=nums.size(); i++)
        {
            s.add(i);
        }
        for(const auto&)
        
