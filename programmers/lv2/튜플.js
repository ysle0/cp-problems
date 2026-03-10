// https://school.programmers.co.kr/learn/courses/30/lessons/64065
function solution(s) {
  let str = s.split("");
  str = str
    .slice(1, s.length - 1)
    .join("")
    .split("},");

  const ans = [];
  str.sort((a, b) => a.length - b.length);

  for (const token of str) {
    const ch = token.replaceAll("{", "").replaceAll("}", "").split(",");

    for (const c of ch) {
      if (!ans.includes(+c)) {
        ans.push(+c);
      }
    }
  }

  return ans;
}
