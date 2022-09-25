# [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## Problem

Given two strings `s` and `p`, return an array of all the start indices of `p`'s anagrams in `s`. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

*Example 1:*

```plaintext
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

*Example 2:*

```plaintext
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

## Solution

*Ideas:*

- Checking for anagrams is easy because we can use a frequency array and if we have the same count for each character, then we found an anagram.
- Here a queue is used due to the fact that when moving left to right, we have to keep a window of exactly `p` size. If that window is an anagram, then the starting index is the first element in the queue.
- If the size of `p` is greater than the size of `s`, then we can return an empty list due to the fact that it is impossible to find an anagram.

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if (p.length() > s.length()) {
            return new ArrayList<>();
        }
        
        final int[] pFreq = freq(p),
                    aFreq = new int[26];
        
        final List<Integer> res = new ArrayList<>();
        final Queue<Integer> q = new LinkedList<>();
        
        for (int i = 0; i < s.length(); i += 1) {
            aFreq[i(s.charAt(i))] += 1;
            q.add(i);
            
            if (q.size() == p.length()) {
                boolean isAnagram = true;
                for (int j = 0; j < 26; j += 1) {
                    if (pFreq[j] != aFreq[j]) {
                        isAnagram = false;
                        break;
                    }
                }
                
                if (isAnagram) {
                    res.add(q.peek());
                }
                
                aFreq[i(s.charAt(q.remove()))] -= 1;
            }
        }
        
        return res;
    }
    
    private int[] freq(String s) {
        int[] f = new int[26];
        for (char c : s.toCharArray()) {
            f[i(c)] += 1;
        }
        
        return f;
    }
    
    private int i(char c) {
        return (int) c - 'a';
    }
}
```

*Analysis:*

Let `N` be the length of `s`.

- `S: O(N)`: We use a queue which could contain all the indexes in from `1` to `len(s)`.
- `T: O(N)`: We check every character in `s` at most once.
