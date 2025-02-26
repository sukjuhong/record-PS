class Heap { 
    constructor(arr) {
        this._arr = arr.slice();
        this._buildHeap(this._arr);
    }
    
    _buildHeap(arr) { 
        const n = arr.length;
        for (let i=Math.floor(n/2)-1; i>=0; i--) {
            this._heapify(arr, n, i);
        }
	}
    
    _heapify(arr, len, idx) { 
        let smallest = idx;
        const left = 2 * idx + 1;
        const right = 2 * idx + 2;

        if (left < len && arr[smallest] > arr[left]) {
            smallest = left;
        }

        if (right < len && arr[smallest] > arr[right]) {
            smallest = right;
        }

        if (smallest !== idx) {
            [arr[idx], arr[smallest]] = [arr[smallest], arr[idx]];
            this._heapify(arr, len, smallest);
        }
    }
    
    get top() {
        return this._arr[0];
    }
    
    get length() {
        return this._arr.length;
    }
    
    push(ele) {
        this._arr.push(ele)
        let idx = this._arr.length - 1;
        while (idx >= 0) {
            const nxtIdx = Math.floor((idx - 1) / 2);
            if (this._arr[idx] < this._arr[nxtIdx]) {
                [this._arr[idx], this._arr[nxtIdx]] =
                    [this._arr[nxtIdx], this._arr[idx]];
                idx = nxtIdx;
            } else break;
        }
    }
    
    pop() {
        [this._arr[0], this._arr[this.length-1]] =
            [this._arr[this.length-1], this._arr[0]];
        const result = this._arr.pop();
        this._heapify(this._arr, this.length, 0);
        return result;
    }
}

function solution(scoville, K) {
    const scovilleHeap = new Heap(scoville);
    let count = 0;
    
    while (scovilleHeap.length >= 2 && scovilleHeap.top < K) {
        const first = scovilleHeap.pop();
        const second = scovilleHeap.pop(); 
        
        const mixed = first + second * 2;
        
        scovilleHeap.push(mixed)
        count++;
    }
    
    if (scovilleHeap.top < K) {
        return -1;
    }
    
    return count;
}