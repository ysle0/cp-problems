// https://school.programmers.co.kr/learn/courses/30/lessons/12981
function solution(n, words) {
  const set = new Set();
  let i = 0;
  let cnt = 0;
  let lastWord = null;
  while (true) {
    if (i === n) {
      i = 0;
      cnt++;
    }

    const idx = cnt * n + i;
    if (idx >= words.length) break;
    const w = words[idx];
    if (lastWord !== null && lastWord.at(-1) !== w.at(0)) {
      return [i + 1, cnt + 1];
    }
    lastWord = w;
    if (set.has(w)) {
      return [i + 1, cnt + 1];
    } else {
      set.add(w);
    }
    i++;
  }
  return [0, 0];
}
