class Solution {
    public String convert(String s, int numRows) {
        StringBuilder sb = new StringBuilder();
        int charsPerRow = s.length() / numRows;
        int gap = numRows / 2;
        int rowLen = charsPerRow + (charsPerRow - 1) * gap;
        for (int i = 0; i < numRows; i++) {
            int k = 0;
            int p = 0;
            for (int j = 0; j < rowLen; j++) {
                if (j % (gap + 1) == 0) {
                    int charPos = i + k * (rowLen - 1);
                    if (charPos >= s.length()) {
                        sb.append(' ');
                    } else {
                        sb.append(s.charAt(charPos));
                    }

                    k++;
                } else if (i > 0 && i < numRows - 1 && j % ((numRows - i - 1) + (gap + 1) * p) == 0) {
                    System.out.println("hmm = " + (rowLen * (j - 1) + i));
                    System.out.println("================");
                    sb.append('?');
                    p++;
                } else {
                    sb.append(' ');
                }
            }

            sb.append('\n');
        }

        return sb.toString();
    }
}

class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.convert("PAYPALISHIRING", 3));
    }
}
