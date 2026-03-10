// https://school.programmers.co.kr/learn/courses/30/lessons/12945

#include <string>
#include <vector>

using namespace std;

static const int dividend = 1'234'567;

int solution(int n) {
	vector f{0, 1, 1, 2};
    f.reserve(100'000);
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i-2] + f[i-1]) % dividend;
    }
    return f[n];
}