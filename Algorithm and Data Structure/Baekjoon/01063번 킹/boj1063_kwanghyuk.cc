#include <iostream>
#include <string>
using namespace std;
 
// a = 킹, b = 돌
 
int main() {
    char posa[3], posb[3];
    int n;
    cin >> posa >> posb >> n;
    while (n > 0) {
        string command;
        cin >> command;
 
        //오른쪽
        if (command == "R") { // command가 R일때
            if (posa[0] + 1 <= 'H') {  // 킹이 범위를 넘어서지 않고
                if (posa[0] + 1 == posb[0] && posa[1] == posb[1]) { // 킹이 오른쪽으로 이동했을때 돌이랑 위치가 같으면
                    if (posb[0] + 1 <= 'H') { // 돌이 범위를 넘어서지 않으면
                        posa[0] += 1;
                        posb[0] += 1;
                    }
                }
                else {
                    posa[0] += 1;
                }
            }
        }
        
        //왼쪽
        if (command == "L") {
            if (posa[0] - 1 >= 'A') {
                if (posa[0] - 1 == posb[0] && posa[1] == posb[1]) {
                    if (posb[0] - 1 >= 'A') {
                        posa[0] -= 1;
                        posb[0] -= 1;
                    }
                }
                else {
                    posa[0] -= 1;
                }
            }
        }
 
        //위쪽
        if (command == "T") {
            if (posa[1] + 1 <= (8+'0')) {
                if (posa[1] + 1 == posb[1] && posa[0] == posb[0]) {
                    if (posb[1] + 1 <= (8+'0')) {
                        posa[1] += 1;
                        posb[1] += 1;
                    }
                }
                else {
                    posa[1] += 1;
                }
            }
        }
        
        //아래쪽
        if (command == "B") {
            if (posa[1] - 1 >= (1+'0')) {
                if (posa[1] - 1 == posb[1] && posa[0] == posb[0]) {
                    if (posb[1] - 1 >= (1 + '0')) {
                        posa[1] -= 1;
                        posb[1] -= 1;
                    }
                }
                else {
                    posa[1] -= 1;
                }
            }
        }
 
        //오위대     두개다 +1씩 증가
        if (command == "RT") {
            if (posa[0] + 1 <= 'H' && posa[1] + 1 <= (8 + '0')) {
                if (posa[0] + 1 == posb[0] && posa[1] + 1 == posb[1]) {
                    if (posb[0] + 1 <= 'H' && posb[1] + 1 <= (8 + '0')) {
                        posa[0] += 1, posa[1] += 1;
                        posb[0] += 1, posb[1] += 1;
                    }
                }
                else {
                    posa[0] += 1, posa[1] += 1;
                }
            }
        }
 
        //왼위대    알파벳-1 숫자+1
        if (command == "LT") {
            if (posa[0] - 1 >= 'A' && posa[1] + 1 <= (8 + '0')) {
                if (posa[0] - 1 == posb[0] && posa[1] + 1 == posb[1]) {
                    if (posb[0] - 1 >= 'A' && posb[1] + 1 <= (8 + '0')) {
                        posa[0] -= 1, posa[1] += 1;
                        posb[0] -= 1, posb[1] += 1;
                    }
                }
                else {
                    posa[0] -= 1, posa[1] += 1;
                }
            }
        }
        //오아대 알파벳+1 숫자 -1
        if (command == "RB") {
            if (posa[0] + 1 <= 'H' && posa[1] - 1 >= (1 + '0')) {
                if (posa[0] + 1 == posb[0] && posa[1] - 1 == posb[1]) {
                    if (posb[0] + 1 <= 'H' && posb[1] - 1 >= (1 + '0')) {
                        posa[0] += 1, posa[1] -= 1;
                        posb[0] += 1, posb[1] -= 1;
                    }
                }
                else {
                    posa[0] += 1, posa[1] -= 1;
                }
            }
        }
 
        //왼아대  알파벳-1 숫자 -1
        if (command == "LB") {
            if (posa[0] - 1 >= 'A' && posa[1] - 1 >= (1 + '0')) {
                if (posa[0] - 1 == posb[0] && posa[1] - 1 == posb[1]) {
                    if (posb[0] - 1 >= 'A' && posb[1] - 1 >= (1 + '0')) {
                        posa[0] -= 1, posa[1] -= 1;
                        posb[0] -= 1, posb[1] -= 1;
                    }
                }
                else {
                    posa[0] -= 1, posa[1] -= 1;
                }
            }
        }
        n--;
    }
    cout << posa[0] << posa[1] << '\n' << posb[0] << posb[1];
    return 0;
}