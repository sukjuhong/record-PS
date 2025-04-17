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
  const numberpad = {
    1: [1, 2, 3, 4, 5, 6, 7, 8, 9, 0],
    2: [2, 3, 5, 6, 8, 9, 0],
    3: [3, 6, 9],
    4: [4, 5, 6, 7, 8, 9, 0],
    5: [5, 6, 8, 9, 0],
    6: [6, 9],
    7: [7, 8, 9, 0],
    8: [8, 9, 0],
    9: [9],
    0: [0],
  };

  const resultSet = new Set();
  function dfs(path, depth) {
    if (depth === 3) return;

    resultSet.add(path.join(""));

    const last = path[path.length - 1];
    for (const next of numberpad[last]) {
      dfs([...path, next], depth + 1);
    }
  }

  for (let i = 1; i <= 9; i++) {
    dfs([i], 0);
  }

  const results = [...resultSet].map(Number).sort((a, b) => a - b);

  function binarySearchClosestMin(arr, target) {
    let lo = 0;
    let hi = arr.length - 1;
    let result = -1;

    while (lo <= hi) {
      let mid = Math.floor((lo + hi) / 2);

      if (target >= arr[mid]) {
        result = arr[mid];
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    return result;
  }

  function binarySearchClosestMax(arr, target) {
    let lo = 0;
    let hi = arr.length - 1;
    let result = -1;

    while (lo <= hi) {
      let mid = Math.floor((lo + hi) / 2);

      if (target <= arr[mid]) {
        result = arr[mid];
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return result;
  }

  let lineIdx = 0;

  const K = parseInt(input[lineIdx++]);

  for (let i = 0; i < K; i++) {
    const number = parseInt(input[lineIdx++]);

    const closestMin = binarySearchClosestMin(results, number);
    const closestMax = binarySearchClosestMax(results, number);

    const closestMinDiff = Math.abs(number - closestMin);
    const closestMaxDiff = Math.abs(number - closestMax);

    if (closestMinDiff < closestMaxDiff) {
      console.log(closestMin);
    } else {
      console.log(closestMax);
    }
  }
}
