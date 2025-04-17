const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", (line) => {
  input.push(line.trim());
}).on("close", () => {
  solution();
});

function solution() {
  let lineIdx = 0;

  const N = parseInt(input[lineIdx++]);
  const weights = [];

  for (let i = 0; i < N; i++) {
    weights.push(parseInt(input[lineIdx++]));
  }

  function binarySearch(arr) {
    let lo = Math.min(...arr);
    let hi = Math.max(...arr);
    let result = -1;

    while (lo <= hi) {
      let lightSum = 0;
      let heavySum = 0;
      const mid = Math.floor((lo + hi) / 2);
      for (let i = 0; i < N; i++) {
        if (weights[i] === mid) continue;
        else if (weights[i] < mid) {
          lightSum += weights[i];
        } else {
          heavySum += weights[i];
        }
      }

      if (lightSum >= heavySum) {
        result = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return result;
  }

  console.log(binarySearch(weights));
}
