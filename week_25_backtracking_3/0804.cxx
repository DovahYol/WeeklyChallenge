class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans(1);
        if (nums.size() == 0)
            return ans;
        bk(0, ans, nums);
        return ans;
    }

    void bk(int index, vector<vector<int>>& ans, vector<int>& nums)
    {
        vector<vector<int>> temp;
        temp.reserve(ans.size());
        std::for_each(ans.begin(), ans.end(), [&](vector<int>& ele) {
            vector<int> cur(ele);
            cur.push_back(nums[index]);
            temp.push_back(cur);
        });
        ans.insert(ans.end(), temp.begin(), temp.end());
        if (++index < nums.size())
            bk(index, ans, nums);
    }
};
