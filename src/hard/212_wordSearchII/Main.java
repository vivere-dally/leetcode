import java.util.*;

class Solution {

    // Todo they want a set of results LOl
    // Use a trie, you are supposed to find a certain word only once.
    public List<String> findWords(char[][] board, String[] words) {
        Map<Character, List<String>> wordDict = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            if (!wordDict.containsKey(words[i].charAt(0))) {
                wordDict.put(words[i].charAt(0), new ArrayList<>());
            }

            wordDict.get(words[i].charAt(0)).add(words[i]);
        }

        List<String> result = new ArrayList<>();
        int rows = board.length;
        int cols = board[0].length;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!wordDict.containsKey(board[row][col])) {
                    continue;
                }

                for (String word : wordDict.get(board[row][col])) {
                    if (dfs(board, row, col, word, 0, new HashSet<>())) {
                        result.add(word);
                    }
                }
            }
        }

        return result;
    }

    private boolean dfs(char[][] board, int row, int col, String word, int index, Set<List<Integer>> seen) {
        if (index >= word.length()) {
            return true;
        }

        if (row < 0 || row >= board.length || col < 0 || col >= board[0].length) {
            return false;
        }

        if (board[row][col] != word.charAt(index)) {
            return false;
        }

        seen.add(coord(row, col));
        boolean result = ((!seen.contains(coord(row + 1, col)) && dfs(board, row + 1, col, word, index + 1, seen))
                || (!seen.contains(coord(row - 1, col)) && dfs(board, row - 1, col, word, index + 1, seen))
                || (!seen.contains(coord(row, col + 1)) && dfs(board, row, col + 1, word, index + 1, seen))
                || (!seen.contains(coord(row, col - 1)) && dfs(board, row, col - 1, word, index + 1, seen)));

        seen.remove(coord(row, col));
        return result;
    }

    private List<Integer> coord(int row, int col) {
        return List.of(row, col);
    }
}

public class Main {
    public static void main(String[] args) {
        char[][] board = { 
            { 'o', 'a', 'b', 'n' },
            { 'o', 't', 'a', 'e' },
            { 'a', 'h', 'k', 'r' },
            { 'a', 'f', 'l', 'v' } };

        String[] words = { "oa", "oaa" };

        Solution s = new Solution();
        System.out.println(s.findWords(board, words));
    }
}
