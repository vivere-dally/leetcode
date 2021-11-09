#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /**
     * Boyer-Moore Voting Algorithm: https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
    */
    int majorityElement(vector<int> &nums) {
        int majority = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (majority == nums[i]) {
                count++;
            } else if (majority != nums[i] && count > 0) {
                count--;
            } else {
                majority = nums[i];
                count = 1;
            }
        }

        return majority;
    }
};

int main() {
    Solution s;
    vector<int> v = {2, 2, 1, 1, 1, 2, 2};
    cout << s.majorityElement(v) << endl;
    return 0;
}
