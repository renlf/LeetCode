int maxSubArray(vector<int>& nums) {
    int max_sub = INT_MIN;
    int tmp_sub = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        tmp_sub = max(tmp_sub + nums[i], nums[i]);
        max_sub = max(tmp_sub, max_sub);
    }
    return max_sub;
}
