const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    const result = [];
    for (const char of str) {
        if (char === char.toLowerCase()) {
            result.push(char.toUpperCase());
        } else {
            result.push(char.toLowerCase());
        }
    }
    console.log(result.join(""));
});