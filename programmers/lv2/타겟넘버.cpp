// https://school.programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

static int gAnswer = 0;
static int gCnt = 0;

void dfs(
    int sum,
    int target,
    vector<int> const& numbers
) {
    const auto len = numbers.size();
    if (gCnt == len) {
        if (target == sum) {
            ++gAnswer;
        }
        return;
    }
    
    dfs(sum + numbers[++gCnt], target, numbers);
    dfs(sum - numbers[++gCnt], target, numbers);
}

int solution(
    vector<int> numbers,
    int target
) {
    dfs(0, target, numbers);
    
    return gAnswer;
}

