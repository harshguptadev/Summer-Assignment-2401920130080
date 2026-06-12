#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;
        int n = chars.size();
        
        while (read < n) {
            char current_char = chars[read];
            int count = 0;
            
            // Count occurrences of the current consecutive group
            while (read < n && chars[read] == current_char) {
                read++;
                count++;
            }
            
            // Write the character
            chars[write++] = current_char;
            
            // If count > 1, write its digits
            if (count > 1) {
                string count_str = to_string(count);
                for (char c : count_str) {
                    chars[write++] = c;
                }
            }
        }
        
        return write;
    }
};