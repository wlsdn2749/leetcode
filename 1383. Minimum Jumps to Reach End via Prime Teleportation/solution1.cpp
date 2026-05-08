class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> spf(maxVal + 1);
        for(int i=2; i <= maxVal; i++)
        {
            if(spf[i] == 0)
            {
                for(int j=i; j <= maxVal; j += i)
                {
                    if(spf[j] == 0)
                        spf[j] = i;
                }
            }
        }
        
        auto isPrime = [&](int x)
        {
            return x >= 2 && spf[x] == x;       
        };

        unordered_map<int, vector<int>> teleportationMap;

        for(int i=0; i<n; i++)
        {
            int x = nums[i];
            int prev = -1; //이 prev는 왜쓰는거지?

            while(x > 1)
            {
                int p = spf[x];

                teleportationMap[p].push_back(i); // p는 x의 소인수

                while(x%p == 0) // 소인수 분해시 중복되는 소인수 제거
                {
                    x /= p;
                }
            }
        }

        vector<int> dist(n, -1); // 방문 배열
        queue<int> q; // bfs

        dist[0] = 0;
        q.push(0);

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

            if (i == n-1) return dist[i];

            auto push = [&](int ni)
            {
                if(ni >= 0 && ni < n && dist[ni] == -1)
                {
                    dist[ni] = dist[i] + 1; // 방문 배열에 횟수 기록
                    q.push(ni);
                }
            };

            push(i-1);
            push(i+1);

            int val = nums[i];

            if(isPrime(val))
            {
                auto it = teleportationMap.find(val);
                if(it != teleportationMap.end())
                {
                    for(int j : it->second)
                    {
                        if(j != i && dist[j] == -1)
                        {
                            dist[j] = dist[i] + 1;
                            q.push(j);
                        }
                    }

                    teleportationMap.erase(it);
                }
            }
        }
        return -1;
    }
};