
#include <utils.h>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int len = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[len] != nums[i]) {
                nums[++len] = nums[i];
            }
        }
        return len + 1;
    }
};

TEST (_0026,RemoveDuplicates) {
    Solution s;

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int res =  s.removeDuplicates(nums);
    cout << "result is " << res << endl;
}