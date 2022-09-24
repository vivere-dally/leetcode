# [735. Asteroid Collision](https://leetcode.com/problems/asteroid-collision/)

## Problem

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

*Example 1:*

```plaintext
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
```

*Example 2:*

```plaintext
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
```

*Example 3:*

```plaintext
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
```

*Constraints:*

- `2 <= asteroids.length <= 104`
- `-1000 <= asteroids[i] <= 1000`
- `asteroids[i] != 0`

## Solution

*Ideas:*

- Why a stack? Seems suitable to the idea of positive asteroids moving to the right, and the rightmost will collide with the leftmost negative one.
- All asteroids that move to the left before having an asteroid that moves to the right can be added to the stack since they will never collide with anything
- We add all positive asteroids to the stack until we meet a negative one
- If we have a positive asteroid on top of the stack and we are currently on a negative asteroid, we can try to collide them according to the problem rules. Otherwise, we just add the asteroid to the stack
- If the positive asteroid is smaller than the negative one, then we pop it from the stack and we don't increment `i` because we want to match the current negative asteroid with other positive ones from the stack.

```java
class Solution {
    public int[] asteroidCollision(int[] A) {
        final int n = A.length;
        final Stack<Integer> s = new Stack<>();
        
        int i = 0;
        while (i < n && A[i] < 0) {
            s.push(A[i]);
            i += 1;
        }
        
        while (i < n) {
            if (A[i] > 0 || s.isEmpty() || s.peek() < 0) {
                s.push(A[i]);
                i += 1;
                continue;
            }
            
            if (s.peek() > Math.abs(A[i])) {
                i += 1;
                continue;
            }
            
            if (s.peek() == Math.abs(A[i])) {
                s.pop();
                i += 1;
                continue;
            }
            
            s.pop();
        }
        
        int[] res = new int[s.size()];
        for (int j = s.size() - 1; j >= 0; j -= 1) {
            res[j] = s.pop();
        }
        
        return res;
    }
}
```

*Analysis:*

Let `N` be the length of the input array.

- `S: O(N)`: We use a stack which could contain all the elements in the array in the worst case. We also build a result array which has the same length as the Stack, thus it would be `O(3 * N) -> O(N)`
- `T: O(N)`: We check every asteroid at least once, but as every asteroid that loses a collision is never checked again, we are guaranteed `O(N)`.
