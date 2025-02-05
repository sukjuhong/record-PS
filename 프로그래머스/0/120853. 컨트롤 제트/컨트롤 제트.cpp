#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    stringstream ss(s);
    string token, last;
    
    while (getline(ss, token, ' ')) {
        if (token != "Z") {
            answer += stoi(token);
            last = token;
        } else {
            answer -= stoi(last);
        }
    } 
    
    return answer;
}