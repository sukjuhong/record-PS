function solution(array, commands) {
    return commands.map((command) => {
        const from = command[0]
        const to = command[1]
        const idx = command[2]
        
        return array.slice(from-1, to)
        	.sort((a, b) => a - b)[idx-1]
    })
}