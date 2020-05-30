class Solution {
private:
    unordered_map<int, unordered_set<int>> g;
    unordered_set<int> s;
    vector<int> c;
    vector<int> ans;
    int rid;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N);
        if(N == 1) return ans;
        for(auto&& edge: edges) {
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        c.resize(N);
        int rd = 0;
        rid = edges[0][0];
        dfs(rid, rd);
        s.clear();
        ans[rid] = rd;
        d2(rid);
        return ans;
    }

    void dfs(int p_node, int& p_rd) {
        s.insert(p_node);
        auto& ps = g[p_node];
        for(auto&& cur: ps) {
            if(s.count(cur) > 0) continue;
            int l_rd = 0;
            dfs(cur, l_rd);
            c[p_node] += c[cur];
            p_rd += c[cur] + l_rd;
        }
        c[p_node] += 1;
    }

    void d2(int p_node) {
        s.insert(p_node);
        auto& ps = g[p_node];
        for(auto&& cur: ps) {
            if(s.count(cur) > 0) continue;
            ans[cur] = ans[p_node] + c[rid] - 2*c[cur];
            d2(cur);
        }
    }
};