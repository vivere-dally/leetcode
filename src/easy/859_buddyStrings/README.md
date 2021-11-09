# 859\. Buddy Strings

Given two strings `s` and `goal` , return `true` _if you can swap two letters in_ `s` _so the result is equal to_ `goal` _, otherwise, return_ `false` _._

Swapping letters is defined as taking two indices `i` and `j` (0-indexed) such that `i != j` and swapping the characters at `s[i]` and `s[j]` .

* For example, swapping at indices `0` and `2` in `"abcd"` results in `"cbad"`.

**Example 1:**

<pre>**Input:** s = "ab", goal = "ba"
**Output:** true
**Explanation:** You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
</pre>

**Example 2:**

<pre>**Input:** s = "ab", goal = "ab"
**Output:** false
**Explanation:** The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
</pre>

**Example 3:**

<pre>**Input:** s = "aa", goal = "aa"
**Output:** true
**Explanation:** You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
</pre>

**Example 4:**

<pre>**Input:** s = "aaaaaaabc", goal = "aaaaaaacb"
**Output:** true
</pre>

**Constraints:**

* `1 <= s.length, goal.length <= 2 * 10<sup>4</sup>`
* `s` and `goal` consist of lowercase letters.
