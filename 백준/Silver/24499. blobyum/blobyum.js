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
  const [N, K] = input[lineIdx++].split(" ").map(Number);
  const applepies = input[lineIdx].split(" ").map(Number);

  let maxSum = 0;
  let curSum = 0;
  for (let i = 0; i < K; i++) {
    curSum += applepies[i];
  }
  maxSum = curSum;

  for (let i = 0; i < N - 1; i++) {
    curSum -= applepies[i];
    curSum += applepies[(i + K) % N];
    maxSum = Math.max(maxSum, curSum);
  }

  console.log(maxSum);
}
