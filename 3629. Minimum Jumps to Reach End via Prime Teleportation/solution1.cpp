struct JumpInfo
{
    int index;
    int count;

    JumpInfo(int index, int count)
        : index(index), count(count)
    {

    }

};

class Solution {
public:
    int minJumps(std::vector<int>& nums) {
        
        std::unordered_map<int, std::vector<int>> teleportationMap; // prime_number -> idx
        std::set<int> primes;

        for(int i=0; i<nums.size(); i++)
        {
            if(isPrime(nums[i])) 
            {
                primes.insert(nums[i]);
            }
        }

        for(int i=0; i<nums.size(); i++)    
        {
            for(const auto prime : primes)
            {
                if(nums[i] % prime == 0)
                {
                    teleportationMap[prime].push_back(i);
                }
            }
            
        }

        std::vector<int> checked;
        checked.resize(nums.size(), 0);

        std::queue<JumpInfo> q;
        q.push(JumpInfo{0, 0});
        checked[0] = 1;

        while(!q.empty())
        {
            auto jumpInfo = q.front(); q.pop();

            auto jumpIdx = jumpInfo.index;
            auto jumpCount = jumpInfo.count;
            
            if(jumpIdx == nums.size() - 1) return jumpCount;
            
            if(isPrime(nums[jumpIdx]))
            {
                auto it = teleportationMap.find(nums[jumpIdx]);
                if(it != teleportationMap.end()) 
                {
                    for(const auto targetIdx : it->second)
                    {
                        if(checked[targetIdx] == 0 && jumpIdx != targetIdx)
                        {
                            checked[targetIdx] = 1;
                            q.push(JumpInfo{targetIdx, jumpCount + 1});     
                        }
                    }
                    teleportationMap.erase(it);
                }
            }

            if(jumpIdx - 1 >= 0 && checked[jumpIdx - 1] == 0)
            {
                checked[jumpIdx - 1] = 1;
                q.push(JumpInfo{jumpIdx - 1, jumpCount + 1});
            }
            if(jumpIdx + 1 < nums.size() && checked[jumpIdx + 1] == 0)
            {
                checked[jumpIdx + 1] = 1;
                q.push(JumpInfo{jumpIdx + 1, jumpCount + 1});
            }

        }
        return 0;
    }

    bool isPrime(int number)
    {
        if(number <= 1) return false;
        if(number <= 3) return true;

        for(int i=2; i<sqrt(number) + 1; i++)
        {
            if(number % i == 0) 
                return false;
        }

        return true;
    }

    // 마지막 숫자는 접근 할 수 있는 방법
        // 마지막 - 1에서 1칸 이동 or 점프
            // for all nums, last % p == 0 있는가?
            // 없으면, 마지막 - 1에서 다시 탐색

    // 처음부터 소수 찾아서 기록해가면서 체크
        // 만약 teleportation map을 구할수 있으면??

        // 먼저 소수를 구해
            // 그 소수로 나눠지는가를 찾으면 돼?
    
};