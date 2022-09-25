# [739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)

## Problem

### Statement

Given an array of integers temperatures represents the daily temperatures, return an array answer such that `answer[i]` is the number of days you have to wait after the `ith` day to get a warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

### Examples

*Example 1:*

```plaintext
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

*Example 2:*

```plaintext
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
```

*Example 3:*

```plaintext
Input: temperatures = [30,60,90]
Output: [1,1,0]
```

### Constraints

- `1 <= temperatures.length <= 1e5`
- `30 <= temperatures[i] <= 100`

## Solution

### Ideas

- Due to the fact that the range of temperatures is small `[30, 100]`, we can keep track of the latest index of a certain temperature.
- We can process the array from right to left and given a temperature T, we are looking for temperatures in `[T + 1, 100]` for the smallest index (i.e., closest to the current temperature).

### Code

```java
class Solution {
    private int[] temps;
    
    public int[] dailyTemperatures(int[] T) {
        temps = new int[71];
        
        int[] res = new int[T.length];
        for (int i = T.length - 1; i >= 0; i -= 1) {
            int min = Integer.MAX_VALUE;
            for (int t = T[i] + 1; t <= 100; t += 1) {
                int idx = getT(t);
                if (idx != 0) {
                    min = Math.min(min, idx - i);
                }
            }
            
            if (min != Integer.MAX_VALUE) {
                res[i] = min;
            }
            
            setT(T[i], i);
        }
        
        return res;
    }
    
    private int getT(int t) {
        return temps[t - 30];
    }
    
    private void setT(int t, int i) {
        temps[t - 30] = i;
    }
}
```

### Analysis

Let `N` be the length of the input array.

- `S: O(N)`: We use an array of the same length for the result.
- `T: O(N)`: We process the temperature at most once. The search for the smallest index is constant time.
