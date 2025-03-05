class Solution {
public:
    bool checkPowersOfThree(int n) {
        /*Ternary representation to be used
        Keep dividing by three tille quotient is <3
        if anytime remainder is 2, return false*/

        while(n>1){
            int rem = n %3;
            if (rem ==2) return false;
            n /=3;

        }
        return true;
    }
};