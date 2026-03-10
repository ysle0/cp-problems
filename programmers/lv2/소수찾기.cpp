// https://school.programmers.co.kr/learn/courses/30/lessons/42839
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

int is_prime(int n) {
    if (n <= 1)
        return false;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    unordered_set<int> test;
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            string word = numbers.substr(0, i);
            const int iword = stoi(word);
            if (is_prime(iword))
                test.insert(iword);
        }
    } while (
        std::next_permutation(numbers.begin(), numbers.end())
    );
    
    return test.size();
}