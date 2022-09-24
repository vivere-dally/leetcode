class Solution {
    public boolean canBeIncreasing(int[] nums) {
        if (nums.length == 2) {
            return true;
        }

        int prev = nums[0], index = -1;
        for (int i = 1; i < nums.length; i++) {
            if (prev >= nums[i]) {
                if (index != -1) {
                    return false;
                }

                index = i;
            }

            prev = nums[i];
        }

        if (index == -1 || index == 0 || index == 1 || index == nums.length - 1) {
            return true;
        }

        return nums[index - 1] < nums[index + 1] || (index >= 2 && nums[index - 2] < nums[index]);
    }
}

// class Main {
//     public static void main(String[] args) {
//         Solution s = new Solution();
//         System.out.println(s.canBeIncreasing(new int[] { 1, 2, 10, 5, 7 }));
//         System.out.println(s.canBeIncreasing(new int[] { 2, 3, 1, 2 }));
//         System.out.println(s.canBeIncreasing(new int[] { 1, 1, 1 }));
//         System.out.println(s.canBeIncreasing(new int[] { 1, 2, 3 }));
//         System.out.println(s.canBeIncreasing(new int[] { 100, 21, 100 }));
//         System.out.println(s.canBeIncreasing(new int[] { 10, 100, 21, 100 }));
//         System.out.println(s.canBeIncreasing(new int[] { 105, 924, 32, 968 }));
//         System.out.println(s.canBeIncreasing(new int[] { 103, 191, 918, 124, 658 }));
//     }
// }
