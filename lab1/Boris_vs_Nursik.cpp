#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> nursik, borsic;
    
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        borsic.push(n);
    }

    for (int i = 0; i < 5; i++) {
        int k;
        cin >> k;
        nursik.push(k);
    }

    int max_moves = 1000000;  
    int moves = 0;

    while (!borsic.empty() && !nursik.empty() && moves < max_moves) {
        int bor_card = borsic.front();
        int nur_card = nursik.front();
        borsic.pop();
        nursik.pop();
        moves++;

        if ((bor_card > nur_card && !(bor_card == 9 && nur_card == 0)) || 
            (bor_card == 0 && nur_card == 9)) {
            borsic.push(bor_card);    
            borsic.push(nur_card);    
        } else {
            nursik.push(bor_card);   
            nursik.push(nur_card);    
        }
    }

    if (moves == max_moves) {
        cout << "botva" ;
    } else if (!borsic.empty()) {
        cout << "Boris " << moves ;
    } else {
        cout << "Nursik " << moves ;
    }

}
