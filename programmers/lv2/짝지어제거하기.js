// https://school.programmers.co.kr/learn/courses/30/lessons/12973
function solution(s) {
  const stack = [s.at(0)];

  for (const ch of s.slice(1)) {
    if (stack[stack.length - 1] === ch) {
      stack.pop();
      continue;
    }

    stack.push(ch);
  }

  return stack.length === 0 ? 1 : 0;
}
