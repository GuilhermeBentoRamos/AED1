#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int a = 1; a <= n; a++) {
        int **line = new int*[9];
        int **column = new int*[9];
        int **square = new int*[9];
        for (int i = 0; i < 9; i++) {
            line[i] = new int[10];
            column[i] = new int[10];
            square[i] = new int[10];

            for (int j = 0; j < 10; j++) {
                line[i][j] = 0;
                column[i][j] = 0;
                square[i][j] = 0;
            }
        }

        bool valid = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int num;
                cin >> num;
                num--;

                int q = (i / 3) * 3 + (j / 3);
                if(line[i][num] == 1) valid = false;
                if(column[j][num] == 1) valid = false;
                if(square[q][num] == 1) valid = false;
                
                line[i][num] = 1;
                column[j][num] = 1;
                square[q][num] = 1;
            }
        }

        cout << "Instancia " << a << endl;
        if(valid)
            cout << "SIM" << endl << endl;
        else
            cout << "NAO" << endl << endl;

        for (int i = 0; i < 9; i++) {
            delete[] line[i];
            delete[] column[i];
            delete[] square[i];
        }
        delete[] line;
        delete[] column;
        delete[] square;
    }
    return 0;
}