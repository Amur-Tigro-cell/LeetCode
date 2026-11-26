
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> phone = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;
        string current;

        backtrack(digits, 0, current, result, phone);

        return result;
    }

private:
    void backtrack(string& digits, int index,
                   string& current,
                   vector<string>& result,
                   vector<string>& phone) {

        // Base case: one combination is complete
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters for the current digit
        string letters = phone[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);

            // Process the next digit
            backtrack(digits, index + 1,
                      current, result, phone);

            // Backtrack
            current.pop_back();
        }
    }
};
