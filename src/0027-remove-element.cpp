
#include <utils.h>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[res++] = nums[i];
            }
        }
        return res;
    }
};


TEST(_0027,RemoveElement) {
    Solution s;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int res = s.removeElement(nums, val);
}
