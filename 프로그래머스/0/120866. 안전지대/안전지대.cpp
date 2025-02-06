#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

const int dy[9] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
const int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void init(int** safe_area, int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            safe_area[i][j] = 0;
        }
    }
}

void fill_area(int** safe_area, int y, int x, int size) {
    for (int i=0; i<9; i++) {
     	int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= size || nx < 0 || nx >= size) continue;
        safe_area[ny][nx] = 1;
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int n = board.size();
    
    int** safe_area = new int*[n];
    for (int i=0; i<n; i++) {
        safe_area[i] = new int[n];
    }
    
    init(safe_area, n);
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (board[i][j] == 1) {
                fill_area(safe_area, i, j, n);
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (safe_area[i][j] == 0) answer++;
            cout << safe_area[i][j] << " ";
        }
        cout << "\n";
    }
    
    return answer;
}