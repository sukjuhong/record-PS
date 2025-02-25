Array.prototype.isEmpty = function() {
    return this.length === 0;
};

Array.prototype.last = function() {
    return this[this.length - 1];
};

function solution(number, k) {
    const stack = []
    
    for (const num of number) {
        while (!stack.isEmpty()
              && k > 0
              && stack.last() < num) {
            stack.pop();
            k--;
        } 
        stack.push(num)
    }
    
    return stack
        .slice(0, number.length-k)
        .join("")
}