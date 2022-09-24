import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        List<Set<Integer>> pi = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            pi.add(new HashSet<>());
        }

        for (int[] prerequisite : prerequisites) {
            pi.get(prerequisite[0]).add(prerequisite[1]);
        }

        List<Boolean> answers = new ArrayList<>();
        for (int[] query : queries) {
            boolean found = false;
            Set<Integer> checked = new HashSet<>();
            Queue<Integer> toCheck = new LinkedList<Integer>();
            toCheck.add(query[0]);

            while (!found && toCheck.peek() != null && checked.size() != numCourses - 1) {
                int element = toCheck.remove();
                if (checked.contains(element)) {
                    continue;
                }

                Set<Integer> children = pi.get(element);
                if (children.contains(query[1])) {
                    found = true;
                    continue;
                }

                for (Integer child : children) {
                    toCheck.add(child);
                }
            }

            answers.add(found);
        }

        return answers;
    }
}

class Main {
    public static void main(String[] args) {
        int n = 2;
        int[][] prerequisites = {{1, 0}};
        int[][] queries = {{0, 1}, {1, 0}};
        Solution sol = new Solution();
        var x = sol.checkIfPrerequisite(n, prerequisites, queries);
        System.out.println(x);

    }
}
