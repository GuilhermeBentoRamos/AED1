#include  <bits/stdc++.h>
//using namespace std;


void contarDigitos(int n, std::vector<long long>& contagem) {
    long long fator = 1;
    while (fator <= n) {
        long long divisor = fator * 10;
        long long bloco_alto = n / divisor;
        long long digito_atual = (n / fator) % 10;
        long long bloco_baixo = n % fator;

        for (int i = 0; i < 10; i++) {
            contagem[i] += bloco_alto * fator;
        }

        for (int i = 0; i < digito_atual; i++) {
            contagem[i] += fator;
        }

        contagem[digito_atual] += bloco_baixo + 1;

        contagem[0] -= fator; // Remove zeros à esquerda
        fator *= 10;
    }
}

int main() {
    int A, B;

    while (std::cin >> A >> B && (A || B)) {
        std::vector<long long> contagemA(10, 0);
        std::vector<long long> contagemB(10, 0);

        contarDigitos(A - 1, contagemA);
        contarDigitos(B, contagemB);

        for (int i = 0; i < 10; i++) {
            std::cout << (contagemB[i] - contagemA[i]);
            if (i < 9) std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}