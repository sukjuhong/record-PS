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

  const K = parseInt(input[lineIdx++]);

  for (let i = 1; i <= K; i++) {
    const [n, t] = input[lineIdx++].split(" ").map(Number);
    const caps = input[lineIdx++].split(" ").map(Number);

    let lo = -1;
    let hi = 1001;
    let mi = [];

    for (let j = 0; j < t; j++) {
      const [size, fit] = input[lineIdx++].split(" ").map(Number);

      switch (fit) {
        case 1:
          lo = Math.max(lo, size);
          break;
        case 0:
          if (!mi.includes(size)) {
            mi.push(size);
          }
          break;
        case -1:
          hi = Math.min(hi, size);
          break;
      }
    }

    console.log(`Data Set ${i}:`);
    if (lo >= hi) {
      console.log(`Inconsistent feedback\n`);
      continue;
    }

    if (mi.length > 1) {
      console.log(`Inconsistent feedback\n`);
      continue;
    }

    if (mi.length === 1) {
      const val = mi[0];
      if (lo >= val || val >= hi) {
        console.log(`Inconsistent feedback\n`);
        continue;
      } else {
        console.log(`1\n`);
        continue;
      }
    }

    let cnt = 0;
    for (let j = 0; j < n; j++) {
      if (lo < caps[j] && caps[j] < hi) {
        cnt++;
      }
    }
    console.log(`${cnt}\n`);
  }
}
