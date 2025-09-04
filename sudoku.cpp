#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int a = 1; a <= n; a++){
        vector<unordered_set<int>> lines(9);
        vector<unordered_set<int>> columns(9);
        vector<unordered_set<int>> squares(9);
        bool valid = true;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                int num;
                cin >> num;
                if(lines[i].find(num) != lines[i].end())valid = false;
                if(columns[j].find(num) != columns[j].end())valid = false;
                int q = (i / 3) * 3 + (j / 3);
                if(squares[q].find(num) != squares[q].end())valid = false;
                lines[i].insert(num);
                columns[j].insert(num);
                squares[q].insert(num);
            }
        }
        cout << "Instancia " << a << endl;
        if (valid) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
        cout << endl;
    }
    return 0;
}