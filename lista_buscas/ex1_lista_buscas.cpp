#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tamanho;
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    
    vector<int> vet(tamanho);

    
    for (int i = 0; i < tamanho; ++i) {
        cout << "Digite o valor para a posição " << i << ": ";
        cin >> vet[i];
    }

    
    cout << "Valores do vetor:" << endl;
    for (int i = 0; i < tamanho; ++i) {
        cout << vet[i] << " ";
    }
    cout << endl;

    return 0;
}

