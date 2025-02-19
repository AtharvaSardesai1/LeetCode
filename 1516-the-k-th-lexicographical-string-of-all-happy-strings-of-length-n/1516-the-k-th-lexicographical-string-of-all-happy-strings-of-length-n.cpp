class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> final;
        queue<string> q;

        // Pushing all the start points
        q.push("a");
        q.push("b");
        q.push("c");
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (curr.size() == n) {
                final.push_back(curr);
                continue;
            }

            // else build the next two strings
            string first = curr;
            string second = curr;

            if (curr.back() == 'a') {
                first.push_back('b');
                second.push_back('c');
            }
            else if (curr.back() == 'b') {
                first.push_back('a');
                second.push_back('c');
            }
            else if (curr.back() == 'c') {
                first.push_back('a');
                second.push_back('b');
            }

            q.push(first);
            q.push(second);
        }
        if(final.size()<k){
            return "";
        }
        return final[k-1];
    }
};