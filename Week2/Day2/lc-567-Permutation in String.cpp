#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s2.length() < s1.length()) return false;

        std::vector<int> s1_count(26, 0), window_count(26, 0);

        // Initialize counts for the first window
        for (int i = 0; i < s1.length(); ++i) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }

        if (s1_count == window_count) return true;

        // Slide the window across string s2
        for (int i = s1.length(); i < s2.length(); ++i) {
            window_count[s2[i] - 'a']++;                   // Add incoming character
            window_count[s2[i - s1.length()] - 'a']--;    // Remove outgoing character

            if (s1_count == window_count) return true;
        }

        return false;
    }
};