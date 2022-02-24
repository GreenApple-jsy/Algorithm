class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>answer = {};
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i) {
            for (int j = i + 1; j < nums_size; ++j) {
                if (nums[i] + nums[j] == target) {
                    answer.push_back(i);
                    answer.push_back(j);
                    break;
                }
            }
        }
        return answer;
    }
};

