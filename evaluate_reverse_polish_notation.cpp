// 150 Evaluate Reverse Polish Notation 
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
// 
// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        std::stack<int> stack;
        for (int i = 0; i < tokens.size(); ++i) {
            const std::string& token = tokens[i];
            if ("+" == token || "-" == token || "*" == token || "/" == token) {
                const int op2 = stack.top();
                stack.pop();
                const int op1 = stack.top();
                stack.pop();
                if ("+" == token) {
                    stack.push(op1 + op2);
                } else if ("-" == token) {
                    stack.push(op1 - op2);
                } else if ("*" == token) {
                    stack.push(op1 * op2);
                } else {
                    stack.push(op1 / op2);
                }
            } else {
                std::istringstream iss(token);
                int value = 0;
                iss >> value;
                stack.push(value);
            }
        }
        return stack.top();
    }
};
