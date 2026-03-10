// https://school.programmers.co.kr/learn/courses/30/lessons/131127

function solution(want, number, discount) {
  let found = 0;
  const end = discount.length - 10 + 1;
  for (let i = 0; i < end; i++) {
    const m = {};
    for (let stride = 0; stride < 10; stride++) {
      const k = discount[i + stride];
      if (!m[k]) m[k] = 1;
      else m[k]++;
    }

    let match = true;
    for (let j = 0; j < want.length; j++) {
      const w = want[j];
      const cnt = number[j];

      if (m[w] && m[w] >= cnt) continue;
      match = false;
      break;
    }

    if (match) found++;
  }
  return found;
}
