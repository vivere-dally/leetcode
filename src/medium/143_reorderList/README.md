# 143 Reorder List

You are given the head of a singly linked-list. The list can be represented as:

<pre>L<sub>0</sub> → L<sub>1</sub> → … → L<sub>n - 1</sub> → L<sub>n</sub>
</pre>

_Reorder the list to be on the following form:_

<pre>L<sub>0</sub> → L<sub>n</sub> → L<sub>1</sub> → L<sub>n - 1</sub> → L<sub>2</sub> → L<sub>n - 2</sub> → …
</pre>

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg)

<pre>**Input:** head = [1,2,3,4]
**Output:** [1,4,2,3]
</pre>

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg)

<pre>**Input:** head = [1,2,3,4,5]
**Output:** [1,5,2,4,3]
</pre>

**Constraints:**

* The number of nodes in the list is in the range `[1, 5 * 10<sup>4</sup>]`.
* `1 <= Node.val <= 1000`
