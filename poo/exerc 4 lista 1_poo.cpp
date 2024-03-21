#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Carro
{
private:
    string nomeDono;
    string telefoneDono;
    string marca;
    string placa;
    string cor;

public:
    
    Carro(string nomeDono, string telefoneDono, string marca, string placa, string cor)
    {
        this->nomeDono = nomeDono;
        this->telefoneDono = telefoneDono;
        this->marca = marca;
        this->placa = placa;
        this->cor = cor;
    }

    
    void imprimirDados() const
    {
        cout << "Dono: " << nomeDono << endl;
        cout << "Telefone do Dono: " << telefoneDono << endl;
        cout << "Marca: " << marca << endl;
        cout << "Placa: " << placa << endl;
        cout << "Cor: " << cor << endl;
    }
};

int main() 
{
    
    vector<Carro> carros;

    
    string nome, telefone, marca, placa, cor;
    char opcao;

    
    do
    {
        cout << "\nCadastro de Carro:" << endl;
        cout << "Digite o nome do dono: ";
        cin >> nome;
        cout << "Digite o telefone do dono: ";
        cin >> telefone;
        cout << "Digite a marca do carro: ";
        cin >> marca;
        cout << "Digite a placa do carro: ";
        cin >> placa;
        cout << "Digite a cor do carro: ";
        cin >> cor;
        carros.push_back(Carro(nome, telefone, marca, placa, cor));

        cout << "\nDeseja cadastrar outro carro? (S/N): ";
        cin >> opcao;
    } while (opcao == 'S' || opcao == 's');

    
    cout << "\nCarros cadastrados:" << endl;
    for (const Carro& carro : carros) {
        cout << "\nDados do carro:" << endl;
        carro.imprimirDados();
        cout << endl;
    }

    return 0;
}

