#include <bits/stdc++.h>
using namespace std;

int idx = 1;
map<string, int> idxMap;

int give[51][51];
int score[51];
int receive[51];

void printGive(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << give[i][j] << " ";
        }
        cout << "\n";
    }
}

void printScore(int n) {
    for (int i=1; i<=n; i++) {
        cout << score[i] << " ";
    }
    cout << "\n";
}

int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();
    
    for (string f: friends) {
        if (idxMap.find(f) == idxMap.end()) {
            idxMap[f] = idx++;
        }
    }
      
    for (string gift: gifts) {
        istringstream ss(gift);
        string buffer;
        
        vector<string> result;
        
        while (getline(ss, buffer, ' ')) {
            result.push_back(buffer);
        }
        
        give[idxMap[result[0]]][idxMap[result[1]]]++;
        score[idxMap[result[0]]]++;
        score[idxMap[result[1]]]--;
    }
    
    printGive(n);
    printScore(n);
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++) {
            string winner;
            
            if (give[i][j] > give[j][i]) {
                winner = friends[i-1];
            } else if (give[i][j] < give[j][i]) {
                winner = friends[j-1];
            } else {
                if (score[idxMap[friends[i-1]]] > score[idxMap[friends[j-1]]]) winner = friends[i-1];
                else if (score[idxMap[friends[i-1]]] < score[idxMap[friends[j-1]]]) winner = friends[j-1];
                else continue;
            }
            
            cout << "winner: " << winner << "\n";
            receive[idxMap[winner]]++;
        }
    }
    
    int answer = INT32_MIN;
    for (int i=1; i<=n; i++) {
        answer = max(answer, receive[i]);
    }
    return answer;
}