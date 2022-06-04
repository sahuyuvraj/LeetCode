class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len2 < len1)
        {
            return false;
        }
        unordered_map<char, int> freq_S1, freq_S2;
        for (int i = 0; i < len1; i++)
        {
            freq_S1[s1[i]]++;
            freq_S2[s2[i]]++;
        }
        if (freq_S1 == freq_S2)
        {
            return true;
        }

        for (int j = len1; j < len2; j++)
        {
            char prevChar = s2[j - len1];
            freq_S2[prevChar]--;
            if (freq_S2[prevChar] == 0 && s2[j] != prevChar)
            {
                freq_S2.erase(prevChar);
            }
            freq_S2[s2[j]]++;
            if (freq_S1 == freq_S2)
            {
                return true;
            }
        }
        return false;
    }
};