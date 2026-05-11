class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        vector<int> stack;
        for(auto num : nums)
        {
            stack.resize(0);

            while (num > 0)
            {
                stack.push_back(num % 10);
                num /= 10;
            }
            

            while(!stack.empty())
            {
                auto t = stack[stack.size()-1]; stack.pop_back();
                result.push_back(t);
            }
        }
        return result;
    }
};