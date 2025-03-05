const INF = 987654321;

class MinHeap {
    constructor() {
        this.heap = [null]
    }
    
    isEmpty() {
        return this.heap.length === 1;
	}
    
    push(node) {
        let current = this.heap.length;
        
        while (current > 1) {
        	const parent = Math.floor(current / 2)
            if (this.heap[parent][1] > node[1]) {
                this.heap[current] = this.heap[parent]
                current = parent;
            } else break;
        }
        
        this.heap[current] = node;
    }
    
    pop() {
        let min = this.heap[1];
        
        if (this.heap.length >= 2) {
            this.heap[1] = this.heap[this.heap.length-1];
            this.heap.splice(this.heap.length-1);
            
            let current = 1;
            let left = current * 2;
            let right = current * 2 + 1;
            
            while (this.heap[left]) {
                let compare = left;
                if (this.heap[right] && this.heap[left][1] > this.heap[right][1]) {
                    compare = right;
                }
                
                if (this.heap[current][1] > this.heap[compare][1]) {
                    [this.heap[current], this.heap[compare]] =
                        [this.heap[compare], this.heap[current]];
                    current = compare;
                    left = current * 2;
                    right = current * 2 + 1;
                } else break;
            }
        } else if (this.heap.length === 2) {
            this.heap.pop();
        } else {
            return null;
        }
        
        return min;
    }
}

function solution(n, s, a, b, fares) {
    // -1은 못가는 길, cost가 있다면 갈 수 있다.
    const map = Array.from({ length: n+1 }, () => []);
    for (const fare of fares) {
        const [dept, dest, cost] = fare
        map[dept].push([dest, cost]);
        map[dest].push([dept, cost]); 
    }
    
   	const costA = getCost(map, n, s);
    const costB = getCost(map, n, a);
    const costC = getCost(map, n, b);
    
    let minCost = INF;
    for (let i=1; i<=n; i++) {
        minCost = Math.min(minCost, costA[i] + costB[i] + costC[i])
    }
    
    return minCost;
}

function getCost(map, n, dept) {
    const costs = new Array(n+1).fill(INF);
    const pq = new MinHeap();
    costs[dept] = 0;
   	pq.push([dept, 0]);
    
    while (!pq.isEmpty()) {
        const [curDest, curCost] = pq.pop();
     	for (const [nxtDest, tmpCost] of map[curDest]) {
            const nxtCost = curCost + tmpCost;
            if (nxtCost < costs[nxtDest]) {
                costs[nxtDest] = nxtCost;
                pq.push([nxtDest, nxtCost]);
            }
        }
    } 
    
    return costs;
}