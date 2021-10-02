# abcabc
# g_left = a, g_right = b
# 

class Solution(object):
    def __convert(self, x):
        return ord(x) - ord('a') + 1
    
    def distinctEchoSubstrings(self, text):
        if len(text) == 1:
            return 0

        m = int(1e9 + 9)
        p = 31
        p_pow = 1
        g_left = self.__convert(text[0])
        g_right = self.__convert(text[1])
        hashes = set()
        for ws in range(1, len(text)):
            left = g_left
            right = g_right
            for mid in range(len(text) - ws):
                if left == right:
                    hashes.add(left)

                first_left = self.__convert(text[ws + mid - 1]) * p_pow
                last_left = self.__convert(text[ws + mid])
                left = (p * (left - first_left) + last_left) % m
                
                first_right = self.__convert(text[ws * 2 + mid -1]) * p_pow
                last_right = self.__convert(text[ws * 2 + mid])
                right = (p * (right - first_right) + last_right) % m
                    
            for i in range(ws, ws * 2):
                first_right = self.__convert()
                g_right = (p * (g_right - self.__convert(text[ws]) * p_pow))
                
            p_pow = p_pow * p
            g_left = (p * g_left + self.__convert(text[ws])) % m
        
if __name__ == '__main__':
    s = Solution()
    n = s.distinctEchoSubstrings("abab")
    print(n)
