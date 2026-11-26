
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {

            // Push opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                // No opening bracket to match
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();

                // Check matching brackets
                if (ch == ')' && top != '(') {
                    return false;
                }

                if (ch == '}' && top != '{') {
                    return false;
                }

                if (ch == ']' && top != '[') {
                    return false;
                }
            }
        }

        // Valid only if no opening brackets remain
        return st.empty();
    }
};
