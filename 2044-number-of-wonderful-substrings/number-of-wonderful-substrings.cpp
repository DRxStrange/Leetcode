class Solution {
public:
    long long wonderfulSubstrings(string word) {
         unordered_map<long long, long long> freq;

        // The empty prefix can be the smaller prefix, which is handled like this
        freq[0] = 1;

       long long mask = 0;
    long long res = 0;
        for (char c : word) {
          long long bit = c - 'a';

            // Flip the parity of the c-th bit in the running prefix mask
            mask ^= (1 << bit);

            // Count smaller prefixes that create substrings with no odd occurring letters
            if (freq.find(mask) != freq.end()) {
                res += freq[mask];
                freq[mask]++;
            } else {
                freq[mask] = 1;
            }

            // Loop through every possible letter that can appear an odd number of times in a substring
            for (long long odd_c = 0; odd_c < 10; odd_c++) {
                if (freq.find(mask ^ (1 << odd_c)) != freq.end()) {
                    res += freq[mask ^ (1 << odd_c)];
                }
            }
        }

        return res;
    }
};