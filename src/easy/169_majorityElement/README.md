# 169. Majority Element

Given an array `nums` of size `n` , return _the majority element_.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

**Example 1:**

```plaintext
**Input:** nums = [3, 2, 3]
**Output:** 3
```

**Example 2:**

```plaintext
**Input:** nums = [2, 2, 1, 1, 1, 2, 2]
**Output:** 2
```

**Constraints:**

* `n == nums.length`
* `1 <= n <= 5 * 10<sup>4</sup>`
* `-2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1`

**Follow-up:** Could you solve the problem in linear time and in `O(1)` space?

## Solution

Use [Boyer-Moore Voting algorithm](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)
