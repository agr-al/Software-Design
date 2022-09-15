#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    map<char, int> symbols = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    int romanToInt(string s) {
        int sum = 0;
        
        for (int i=0; i < s.length(); i++){
            if (symbols[s[i]] >= symbols[s[i+1]]){
                sum += symbols[s[i]];
            }
            else{
                sum -= symbols[s[i]];
            }
        }
        
        return sum;
        
    }
};