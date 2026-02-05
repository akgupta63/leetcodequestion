class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string temp = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (temp == "" || temp == ".") {
                }
                else if (temp == "..") {
                    if (!stack.empty()) stack.pop_back();
                }
                else {
                    stack.push_back(temp);
                }
                temp = "";
            }
            else {
                temp += path[i];
            }
        }

        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i != stack.size() - 1)
                result += "/";
        }

        return result;
    }
};
