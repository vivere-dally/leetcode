import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public int numDecodings(String s) {
        if (s.charAt(0) == '0') {
            return 0;
        }
        
        Map<Integer, Integer> dp = new HashMap<>();
        Set<Character> allowed = new HashSet<>();
        allowed.addAll(Arrays.asList('0', '1', '2', '3', '4', '5', '6'));
        
        dp.put(s.length(), 1);
        return dfs(s, 0, dp, allowed);
    }
    
    private int dfs(String s, int index, Map<Integer, Integer> dp, Set<Character> allowed) {
        if (index > s.length()) {
            return 0;
        }
        
        if (dp.containsKey(index)) {
            return dp.get(index);
        }
        
        if (s.charAt(index) == '0') {
            return 0;
        }
        
        int result = dfs(s, index + 1, dp, allowed);
        if (index + 1 < s.length() &&
            (
                s.charAt(index) == '1' ||
                (s.charAt(index) == '2' && allowed.contains(s.charAt(index + 1)))
            )
           ) {
            result += dfs(s, index + 2, dp, allowed);
        }
        
        dp.put(index, result);
        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();

        System.out.println(s.numDecodings("10"));
    }
}
