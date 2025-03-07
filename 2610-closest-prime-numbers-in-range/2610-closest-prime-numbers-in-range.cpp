class Solution {
public:

    vector<int> closestPrimes(int left, int right) {
        vector<int> sieve(right+1, 1);
        sieve[0]=0;
        sieve[1]=0;

        for(int i=2; i<=sqrt(right); i++){
            if(sieve[i]==1){
                for(int j=i*i; j<=right; j+=i){
                    sieve[j]=0;
                }
            }
        }
        
        vector<int> prime;
        for(int i=left; i<=right; i++){
            if(sieve[i]==1){
                prime.push_back(i);
            }
        }
        if(prime.size()<2) return {-1, -1};

        int min_diff = INT_MAX;
        int num1 = -1, num2 = -1;

        for (int i = 1; i < prime.size(); i++) {
            int diff = prime[i] - prime[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
                num1 = prime[i - 1];
                num2 = prime[i];
            }
        }

        return {num1, num2};
    }
};