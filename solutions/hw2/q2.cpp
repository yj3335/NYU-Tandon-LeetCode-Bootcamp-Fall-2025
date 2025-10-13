class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> pCount(26, 0), sCount(26, 0);
        int pLen = p.length(), sLen = s.length();

        if (pLen > sLen) return result;

        for (int i = 0; i < pLen; ++i) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        if (pCount == sCount) result.push_back(0);

        for (int i = pLen; i < sLen; ++i) {
            sCount[s[i] - 'a']++;
            sCount[s[i - pLen] - 'a']--;

            if (pCount == sCount) result.push_back(i - pLen + 1);
        }

        return result;
    }
};