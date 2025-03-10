class Solution {
public:
    bool isVowel(char c){
        if (c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u'){
            return true;
        }
        else return false;
    }

    long atleastK(string word, int k){
        long validSubstrings =0;
        int start =0; 
        int end =0;

        unordered_map<char, int> vowelCount;
        int consonant = 0;

        while(end<word.length()){
            char newLetter = word[end];
            if(isVowel(newLetter)) vowelCount[newLetter]++;
            else consonant++;

            while(vowelCount.size() ==5 && consonant>=k){
                validSubstrings  += word.length() -end;
                char startLetter = word[start];
                if(isVowel(startLetter)){
                    vowelCount[startLetter]--;
                    if(vowelCount[startLetter]==0) vowelCount.erase(startLetter);
                    
                }
                else consonant--;
                start++;
            }
            end++;
        }
        return validSubstrings;
            
    }
    long long countOfSubstrings(string word, int k) {
        return atleastK(word, k) - atleastK(word, k+1);
    }
};