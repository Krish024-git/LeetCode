class Solution {
public:
    bool isValid(string s) {
            stack<char> stack;
            map<char, char> mapp = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (mapp.find(c) == mapp.end()) {
                stack.push(c);
            } else if (!stack.empty() && mapp[c] == stack.top()) {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();        
    }
};