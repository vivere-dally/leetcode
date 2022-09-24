import java.util.HashMap;
import java.util.Map;

class Solution {
    public String minWindow(String s, String t) {
        Map<Character, Integer> need = new HashMap<>();
        Map<Character, Integer> have = new HashMap<>();
        for (int i = 0; i < t.length(); i++) {
            need.put(t.charAt(i), 1 + need.getOrDefault(t.charAt(i), 0));
            have.putIfAbsent(t.charAt(i), 0);
        }
        
        final int needCount = need.keySet().size();
        int haveCount = 0;
        int minSubstr = Integer.MAX_VALUE;
        int minStart = 0;
        int minEnd = 0;
        int start = 0;
        for (int end = 0; end < s.length(); end++) {
            char c = s.charAt(end);
            if (need.containsKey(c)) {
                int haveC = 1 + have.get(c);
                if (haveC == need.get(c)) {
                    haveCount++;
                }

                have.put(c, haveC);
            }

            // if (haveCount == needCount) {
            //     for (Character k : need.keySet()) {
            //         System.out.println("C: " + k + " = " + (need.get(k) - have.get(k)));
            //     }
            // }

            while (haveCount == needCount) {
                int currMinSubstr = end - start + 1;
                if (currMinSubstr < minSubstr) {
                    minSubstr = currMinSubstr;
                    minStart = start;
                    minEnd = end + 1; // +1 for the substring method, [left, right)
                }
                
                c = s.charAt(start);
                if (need.containsKey(c)) {
                    int haveC = have.get(c);
                    if (haveC == need.get(c)) {
                        haveCount--;
                    }

                    have.put(c, haveC - 1);
                }
                
                start++;
            }
        }

        return s.substring(minStart, minEnd);
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "aaab";
        String t = "ab";

        Solution sol = new Solution();
        System.out.println(sol.minWindow(s, t));
    }
}
