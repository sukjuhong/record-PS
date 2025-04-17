const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", (line) => {
  input.push(line.trim());
}).on("close", () => {
  let idx = 0;

  const K = parseInt(input[idx++], 10);

  for (let t = 1; t <= K; t++) {
    const n = parseInt(input[idx++], 10);
    const [s, f] = input[idx++].split(" ").map(Number);

    const leak = new Array(1001).fill(0);

    for (let i = 0; i < n; i++) {
      const [si, fi, ri] = input[idx++].split(" ").map(Number);
      for (let time = si; time <= fi; time++) {
        leak[time] += ri;
      }
    }

    let total = 0;
    for (let time = s; time <= f; time++) {
      total += leak[time];
    }

    console.log(`Data Set ${t}:\n${total}\n`);
  }
});
