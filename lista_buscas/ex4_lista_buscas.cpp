#include <iostream>
#include <vector>

using namespace std;

int pesqbin(const vector<int>& vet, int val) {
    int esquerda = 0;
    int direita = vet.size() - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (vet[meio] == val) {
            return meio; // 
        } else if (vet[meio] < val) {
            esquerda = meio + 1; 
        } else {
            direita = meio - 1; 
        }
    }

    return -1; 
}

int main() {
    vector<int> meuVetor = {10, 20, 30, 40, 50}; 

    int valorProcurado;
    cout << "Digite o valor a ser procurado: ";
    cin >> valorProcurado;

    int posicao = pesqbin(meuVetor, valorProcurado);

    if (posicao != -1) {
        cout << "Valor encontrado na posição " << posicao << endl;
    } else {
        cout << "Valor não encontrado no vetor." << endl;
    }

    return 0;
}

