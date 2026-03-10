// https://school.programmers.co.kr/learn/courses/30/lessons/12951
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string s, char separator) {
    vector<string> ret;
    int cur = 0;
    int pos = 0;
    while ((pos = s.find(separator, cur)) != string::npos) {
        const int len = pos-cur;
        ret.push_back(s.substr(cur, len));
        cur = pos+1;
    }
    ret.push_back(s.substr(cur));
    return ret;
}

string solution(string s) {
    auto v = split(s, ' ');
    for (int i = 0; i < v.size(); i++) {
        const char c = v[i][0];
        bool is_first_ch_number = c > '0' && c < '9';
        
        for (int j = 0; j < v[i].size(); j++) {
            v[i][j] = tolower(v[i][j]);
        }
        if (is_first_ch_number) continue;
        v[i][0] = toupper(c);
    }
    
    string answer;
    for (int i = 0; i < v.size(); i++) {
        if (i != v.size()-1) answer += v[i] + " ";
        else answer += v[i];
    }
    return answer;
}