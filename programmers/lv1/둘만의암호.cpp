// https://school.programmers.co.kr/learn/courses/30/lessons/155652
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    unordered_set<char> skipSet(skip.begin(), skip.end());
    string answer = "";
    for (char c: s) {
        int cur = index;
        while (cur > 0) {
            while (skipSet.find(c + 1) != skipSet.end()) {
                c++;
            }
            
            if (c == 'z') {
                c = 'a';
            } else {
                c++;
            } 
            
            while (skipSet.find(c) != skipSet.end()) {
                c++;
            }
            
            cur--;
        }
        answer += c;
    }
    
    return answer;
}
