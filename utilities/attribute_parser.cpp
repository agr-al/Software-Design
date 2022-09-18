#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

vector<string> split(string& input){
    set<char> delimiters = {'<',' ','=','"','>','/'};
    
    string word;
    vector<string> result;
    
    for (auto chr: input){
        if (delimiters.find(chr) != delimiters.end()){
                if (!(word.empty())){
                result.push_back(word);
                word.clear();
            }
        }
        else{
            word.push_back(chr);
        }
    }
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int lines, queries;
    cin >> lines >> queries;
    cin.ignore();
    // vector<string> parsed;
    string tag, line;
    string attribute, value;
    map<string, string> dict; 
    for (auto i=0; i < lines; i++){
        getline(cin, line);
        if (line[1] != '/'){
            auto parsed = split(line);
            if (!(tag.empty())) tag.push_back('.');
            tag.append(parsed[0]);
        
            int j = 1;        
            while(j < parsed.size()){
                attribute = parsed[j];
                j++;
                value = parsed[j];
                j++;
                // cout << tag << ' ' << attribute << endl;
                dict[tag+'~'+attribute] = value;
            }
        }
        else{
            while (!(tag.empty()) && tag.back()!='.')
                tag.pop_back();
            if (tag.back() == '.')
                tag.pop_back();
        }   
          
    }
    
    string query;
    for (auto k=0; k < queries; k++){
        cin >> query;
        if (dict.find(query) != dict.end()){
            cout << dict[query] << '\n';
        }
        else {
            cout << "Not Found!\n";
        }
    }
    
    return 0;
}
