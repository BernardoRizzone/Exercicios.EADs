#include <iostream>
#include <vector>

using namespace std;

int pesqsent(const vector<int>& vet, int val) {
    int tamanho = vet.size();
    vector<int> copiaVetor(tamanho + 1); 

    
    for (int i = 0; i < tamanho; ++i) {
        copiaVetor[i] = vet[i];
    }

    
    copiaVetor[tamanho] = val;

    int i = 0;
    while (copiaVetor[i] != val) {
        ++i;
    }

    if (i < tamanho) {
        return i; 
    } else {
        return -1; 
    }
}

int main() {
    vector<int> meuVetor = {10, 20, 30, 40, 50}; 

    int valorProcurado;
    cout << "Digite o valor a ser procurado: ";
    cin >> valorProcurado;

    int posicao = pesqsent(meuVetor, valorProcurado);

    if (posicao != -1) {
        cout << "Valor encontrado na posição " << posicao << endl;
    } else {
        cout << "Valor não encontrado no vetor." << endl;
    }

    return 0;
}

