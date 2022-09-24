# [394. Decode String](https://leetcode.com/problems/decode-string/)

## Problem

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, `k`. For example, there will not be input like `3a` or `2[4]`.

The test cases are generated so that the length of the output will never exceed `1e5`.

*Example 1:*

```plaintext
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
```

*Example 2:*

```plaintext
Input: s = "3[a2[c]]"
Output: "accaccacc"
```

*Example 3:*

```plaintext
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
```

*Constraints:*

- `1 <= s.length <= 30`
- `s` consists of lowercase English letters, digits, and square brackets `'[]'`.
- s is guaranteed to be a *valid* input.
- All the integers in `s` are in the range `[1, 300]`.

## Solution

*Ideas:*

- Due to the fact that we have a nested structure `2[a3[b]]`, we can immediately think of a recursive approach
- We also have to build new strings, thus a `StringBuilder` would be necessary.

```java
class Solution {
    class Pair {
        public String item1;
        public Integer item2;
        public Pair(String item1, Integer item2) {
            this.item1 = item1;
            this.item2 = item2;
        }
    }
    
    public String decodeString(String s) {
        StringBuilder sb = new StringBuilder();
        int i = 0;
        while (i < s.length()) {
            if (Character.isDigit(s.charAt(i))) {
                Pair p = dfs(s, i);
                sb.append(p.item1);
                i += p.item2;
                continue;
            }
            
            sb.append(s.charAt(i));
            i += 1;
        }
        
        return sb.toString();
    }
    
    private Pair dfs(String s, int i) {
        if (i >= s.length()) {
            return new Pair("", 0);
        }
        
        int j = i;
        while (Character.isDigit(s.charAt(j))) {
            j += 1;
        }
        
        int number = Integer.parseInt(s.substring(i, j));
        j += 1; // Skip '['
        
        StringBuilder sb = new StringBuilder();
        while (j < s.length() && s.charAt(j) != ']') {
            if (Character.isDigit(s.charAt(j))) {
                Pair p = dfs(s, j);
                sb.append(p.item1);
                j += p.item2;
                continue;
            }
            
            sb.append(s.charAt(j));
            j += 1;
        }
        
        StringBuilder res = new StringBuilder();
        for (int k = 0; k < number; k += 1) {
            res.append(sb.toString());
        }
        
        // + 1 due to the fact that j is currently on ']'
        return new Pair(res.toString(), j - i + 1); 
    }
}
```

*Analysis:*

Let `N` be the length of the input string.

- `S: O(N * M)`: We use a StringBuilder which will contain the output result. `M` here denotes the factor of multiplication and will be a multiple of `300` in the worst case. For example, if we have `300[<string_of_length_N>]` we will get a memory of `O(300*N)`. However, we could have nested multipliers.
- `T: O(N * M)`: Each character is added to a string builder only once. However, the nested string builders will be multiplied by the factors resulting in that `M` term.
- *NOTE!*: if we consider the multiplication factor to be constant, then the algorithm is linear in both time and space.
