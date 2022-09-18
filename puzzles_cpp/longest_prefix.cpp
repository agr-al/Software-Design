#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs);
    
    string longestCommonUtil(string str1, string str2);
    
};

string Solution::longestCommonPrefix(vector<string>& strs){
    
    string result = "";
    int prefix_len = strs.size();
    string prefix = strs[0];
    
    for (int i=1; i<prefix_len; i++){
        prefix = this->longestCommonUtil(prefix, strs[i]);
    }
    
    return prefix;
    
}

string Solution::longestCommonUtil(string str1, string str2){
    
    string result = "";
    int len = min(str1.length(), str2.length());

    for(int i=0; i<len; i++){
        
        if (str1[i] != str2[i]){
            break;
        }
        result += str1[i];
    }
        return result;
        
}