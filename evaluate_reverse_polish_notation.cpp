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