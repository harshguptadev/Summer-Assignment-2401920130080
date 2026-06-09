#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> ans;
        if (s.length() < p.length()) return ans;

        std::vector<int> p_count(26, 0), window_count(26, 0);
        
        // Initialize counts for the first window
        for (int i = 0; i < p.length(); ++i) {
            p_count[p[i] - 'a']++;
            window_count[s[i] - 'a']++;
        }

        if (p_count == window_count) ans.push_back(0);

        // Slide the window across string s
        for (int i = p.length(); i < s.length(); ++i) {
            window_count[s[i] - 'a']++;                  // Add incoming character
            window_count[s[i - p.length()] - 'a']--;     // Remove outgoing character

            if (p_count == window_count) {
                ans.push_back(i - p.length() + 1);
            }
        }

        return ans;
    }
};