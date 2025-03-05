class MinHeap {
    constructor() {
        this._heap = [null]
    }
    
    push(val) {
        this._heap.push(val)
        
        let currentIdx = this._heap.length - 1;
        while (currentIdx > 1) {
            const parentIdx = Math.floor(currentIdx / 2)
            if (this._heap[currentIdx] < this._heap[parentIdx]) {
                this._swap(currentIdx, parentIdx);
                currentIdx = parentIdx;
            } else break;
        }
        
    }
    
    pop(isTop) {
        if (this._heap.length === 1) return;
        if (this._heap.length === 2) return this._heap.pop();
        if (isTop) {
        	const lastParentIdx = Math.floor((this._heap.length - 1) / 2)
            const leafNodes = this._heap.slice(lastParentIdx);
            const max = Math.max(...leafNodes);
            this._swap(lastParentIdx + leafNodes.indexOf(max), this._heap.length - 1);
            return this._heap.pop();
        }
        
        const min = this._heap[1];
        this._heap[1] = this._heap.pop();
        
        let currentIdx = 1;
        let leftChildIdx = currentIdx * 2;
        let rightChildIdx = currentIdx * 2 + 1;
        
        while (this._heap[leftChildIdx]) {
            let swapChildIdx = leftChildIdx;
            if (this._heap[rightChildIdx] &&
                this._heap[rightChildIdx] < this._heap[leftChildIdx]) {
                swapChildIdx = rightChildIdx;
            }
            
            if (this._heap[currentIdx] > this._heap[swapChildIdx]) {
                this._swap(currentIdx, swapChildIdx);
                currentIdx = swapChildIdx;
                leftChildIdx = currentIdx * 2;
                rightChildIdx = currentIdx * 2 + 1;
            } else break;
        }
        
        return min;    
    }
    
    result() {
        if (this._heap.length === 1) return [0, 0];
        else if (this._heap.length === 2) return [this._heap[1], this._heap[1]];
        else {
            return [this.pop(true), this._heap[1]];
        }
    }
    
    _swap(iA, iB) {
        return [this._heap[iA], this._heap[iB]] = [this._heap[iB], this._heap[iA]];
    }
}

function solution(operations) {
    const minHeap = new MinHeap();
    
    for (const operation of operations) {
        const [cmd, data] = operation.split(" ");
        if (cmd === "I") {
            minHeap.push(parseInt(data));
		} else if (cmd === "D") {
            minHeap.pop(data === "1");
        }
    }
    
    return minHeap.result();
}