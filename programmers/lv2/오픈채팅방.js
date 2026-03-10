// https://school.programmers.co.kr/learn/courses/30/lessons/42888
function solution(record) {
  const history = {};
  for (const r of record) {
    const e = r.split(" ");
    const cmd = e[0];
    const uid = e[1];
    const nickname = e[2];
    if (cmd !== "Leave") {
      history[uid] = nickname;
    }
  }

  let messages = [];
  for (const r of record) {
    const [cmd, uid] = r.split(" ");
    let sentence = "";
    if (cmd === "Enter") {
      sentence += history[uid] + "님이 들어왔습니다.";
      messages.push(sentence);
    } else if (cmd === "Leave") {
      sentence += history[uid] + "님이 나갔습니다.";
      messages.push(sentence);
    }
  }
  return messages;
}
