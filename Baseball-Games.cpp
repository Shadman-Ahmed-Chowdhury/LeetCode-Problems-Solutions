class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector <int> result;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == "C") {
                result.pop_back();
            } else if(ops[i] == "D") {
                int l = result[result.size() - 1];
                result.push_back(l * 2);
            } else if(ops[i] == "+") {
                int l1 = result[result.size() - 1];
                int l2 = result[result.size() - 2];
                result.push_back(l1 + l2);
            } else {
                int x = 0;
                stringstream geek(ops[i]);
                geek >> x;
                result.push_back(x);
            }
        }
        int sum = 0;
        for(int i = 0; i < result.size(); i++) {
            sum += result[i];
        }
        return sum;
    }
};