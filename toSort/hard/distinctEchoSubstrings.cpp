#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int getIntFromChar(char c) {
        return c - 'a' + 1;
    }

public:
    int distinctEchoSubstrings(string text) {
// hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q 
// hash( txt[s .. s+m-1] ) : Hash value at shift s. 
// hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1) 
// d: Number of characters in the alphabet 
// q: A prime number 
// h: d^(m-1)
        if (text.size() == 1) {
            return 0;
        }
        
        const int p = 31;
        const int m = 1e9 + 9;
        unordered_set<long long> hashes;
        long long
            p_pow = 1,
            g_left = (p_pow * this->getIntFromChar(text[0])) % m,
            g_right = (p_pow * this->getIntFromChar(text[1])) % m;
        vector<long long> p_pows{p_pow};
        for (int window_size = 1; window_size < text.size(); window_size++) {
            long long left = g_left, right = g_right;
            for (int middle = 0; middle < text.size() - window_size; middle++) {
                left = (p * (left - this->getIntFromChar(text[window_size + middle - 1]) * p_pow) + this->getIntFromChar(text[window_size + middle])) % m;
                right = (p * (right - this->getIntFromChar(text[window_size * 2 + middle - 1]) * p_pow) + this->getIntFromChar(text[window_size * 2 + middle])) % m;
                if (left == right) {
                    hashes.insert(left);
                }
            }

            p_pow = (p_pow * p) % m;
            g_left = (p * g_left + this->getIntFromChar(text[window_size])) % m;
            long long p_pow_g_right = p_pow;
            for (int i = 0; i < window_size; i++) {
                g_right = (p * (g_right - this->getIntFromChar(text[window_size * 2 + i - 1]) * p_pows[i]) + this->getIntFromChar(text[window_size * 2 + i])) % m;
            }

            for (int i = window_size + 1; i <= window_size * 2; i++) {
                g_right = (p * g_right + this->getIntFromChar(text[i])) % m;
            }
        }
        
        return hashes.size();
        
//         string s, text_c;
//         hash<string> hasher;
//         set<long long> hashes;
//         int unique = 0;
//         long long s_hash;
//         for (int l = 1; l <= text.size(); l++) {
//             text_c.push_back(text[l - 1]);
//             s = text_c;
//             for (int i = 0; i <= text.size() - l; i++) {
//                 long long s_hash = hasher(s);
//                 if (hashes.find(s_hash) != hashes.end()) {
//                     hashes.erase(s_hash);
//                     unique++;
//                 }
//                 else {
//                     hashes.insert(hasher(s + s));
//                 }

//                 s.erase(0, 1);
//                 s.push_back(text[l + i]);
//             }
//         }
        
//         return unique;
    }
};

int main()
{
    Solution s;
    cout << s.distinctEchoSubstrings("leetcodeleetcode");
}
