class Solution {
    public int numTrees(int n) {
        int result = 0, p = 1, pp = 1;
        for(int i = 1; i <= n; i++) {
            result = result + p * pp;
            pp = p;
            p = result;
        }
        
        return result;
    }
}

class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.numTrees(3));
    }
}
