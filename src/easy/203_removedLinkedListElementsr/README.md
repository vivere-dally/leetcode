# 203\. Remove Linked List Elements

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return _the new head_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)

<pre>**Input:** head = [1,2,6,3,4,5,6], val = 6
**Output:** [1,2,3,4,5]
</pre>

**Example 2:**

<pre>**Input:** head = [], val = 1
**Output:** []
</pre>

**Example 3:**

<pre>**Input:** head = [7,7,7,7], val = 7
**Output:** []
</pre>

**Constraints:**

* The number of nodes in the list is in the range `[0, 10<sup>4</sup>]`.
* `1 <= Node.val <= 50`
* `0 <= val <= 50`
