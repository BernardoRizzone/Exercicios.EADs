#include <iostream>
#include <vector>

using namespace std;

int pesqseq(const vector<int>& vet, int val) {
    int cont = 0; 
    for (int i = 0; i < vet.size(); ++i) {
        ++cont;
        if (vet[i] == val) {
            return cont; 
        }
    }
    return cont; 
}

int pesqbin(const vector<int>& vet, int val) {
    int cont = 0; 
    int esquerda = 0;
    int direita = vet.size() - 1;

    while (esquerda <= direita) {
        ++cont;
        int meio = esquerda + (direita - esquerda) / 2;

        if (vet[meio] == val) {
            return cont; 
        } else if (vet[meio] < val) {
            esquerda = meio + 1; 
        } else {
            direita = meio - 1; 
        }
    }

    return cont; 
}

int pesqsent(const vector<int>& vet, int val) {
    int cont = 0; 
    int tamanho = vet.size();
    vector<int> copiaVetor(tamanho + 1); 

   
    for (int i = 0; i < tamanho; ++i) {
        copiaVetor[i] = vet[i];
    }

    
    copiaVetor[tamanho] = val;

    int i = 0;
    while (copiaVetor[i] != val) {
        ++cont;
        ++i;
    }

    return cont; 
}

int main() {
    vector<int> meuVetor = {10, 20, 30, 40, 50}; 

    int valorProcurado;
    cout << "Digite o valor a ser procurado: ";
    cin >> valorProcurado;

    int contSeq = pesqseq(meuVetor, valorProcurado);
    int contBin = pesqbin(meuVetor, valorProcurado);
    int contSent = pesqsent(meuVetor, valorProcurado);

    cout << "Pesquisa sequencial: " << contSeq << " pesquisas" << endl;
    cout << "Pesquisa binária: " << contBin << " pesquisas" << endl;
    cout << "Pesquisa com sentinela: " << contSent << " pesquisas" << endl;

    return 0;
}

