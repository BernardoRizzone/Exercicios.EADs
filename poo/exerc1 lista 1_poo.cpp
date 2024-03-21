#include <iostream>
#include <string>
using namespace std;

class agendaTelefonica 
{
private:
    string nome;
    string telefone;
    string email;
    string marca;

public:
     
    agendaTelefonica(string nome, string telefone, string email, string marca) 
    {
        this->nome = nome;
        this->telefone = telefone;
        this->email = email;
        this->marca = marca;
    }

    void imprimirDados() 
    {
        cout << "Nome: " << nome << endl;
        cout << "Telefone: " << telefone << endl;
        cout << "E-mail: " << email << endl;
        cout << "Marca: " << marca << endl;
    }
};

int main()
{
    agendaTelefonica contato1("João", "123456789", "joao@GMAIL.com", "APPLE");
    agendaTelefonica contato2("Maria", "987654321", "maria@GMAILe.com", "SAMSUNG");

    cout << "Contato 1:" << endl;
    contato1.imprimirDados();

    cout << "\nContato 2:" << endl;
    contato2.imprimirDados();

    return 0;
}


