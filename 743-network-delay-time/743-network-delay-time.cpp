class Solution {
public:

    vector<pair<int, int>> adj[101];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (auto &a : times)
            adj[a[0]].push_back({a[1], a[2]});
        int ans = 0;
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            for (auto &a : adj[p.second])
            {
                if (dist[a.first] > dist[p.second] + a.second)
                {
                    dist[a.first] = dist[p.second] + a.second;
                    pq.push({dist[a.first], a.first});
                }
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};