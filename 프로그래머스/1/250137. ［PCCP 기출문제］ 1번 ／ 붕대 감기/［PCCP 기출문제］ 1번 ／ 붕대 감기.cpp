#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int MAX_HEALTH = health;
    int time = 0;
   	int conti = 0; 
    int attackIdx = 0;
    while (attackIdx < attacks.size()) {
        time++;
        conti++; 
        
        if (attacks[attackIdx][0] == time) {
            conti = 0;
            health -= attacks[attackIdx++][1];
        } else {    
            health += bandage[1];
            if (conti == bandage[0]) {
                conti = 0;
                health += bandage[2];
            }
            health = health < MAX_HEALTH ? health : MAX_HEALTH;
        }
         
        if (health <= 0) {
            health = -1;
            break;
        }
    }
    return health;
}