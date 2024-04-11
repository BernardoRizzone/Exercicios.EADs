#include <iostream>
#include <vector>

using namespace std;

int pesqseq(const vector<int>& vet, int val) {
    for (int i = 0; i < vet.size(); ++i) {
        if (vet[i] == val) {
            return i;
        }
    }
    return -1; 
}

int main() {
    vector<int> meuVetor = {10, 20, 30, 40, 50}; 

    int valorProcurado;
    cout << "Digite o valor a ser procurado: ";
    cin >> valorProcurado;

    int posicao = pesqseq(meuVetor, valorProcurado);

    if (posicao != -1) {
        cout << "Valor encontrado na posição " << posicao << endl;
    } else {
        cout << "Valor não encontrado no vetor." << endl;
    }

    return 0;
}

