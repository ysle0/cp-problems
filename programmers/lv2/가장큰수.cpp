// https://school.programmers.co.kr/learn/courses/30/lessons/42746
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> v;
    for (int n: numbers) {
        v.push_back(to_string(n));
    }
    sort(v.begin(), v.end(), [](string a, string b) {
        return a+b > b+a;
    });
    	
    string answer="";
    for (string s: v) {
        answer += s;
    }
    
    if (answer == string(answer.length(), '0'))
        return "0";
        
    return answer;
}