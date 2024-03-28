#include <iostream>
#include <string>

using namespace std;

class Contato 
{
private:
    string telefone;
    string nome;
    string endereco;
    string cep;

public:
    
    Contato(string _telefone, string _nome, string _endereco, string _cep)
    {
        telefone = _telefone;
        nome = _nome;
        endereco = _endereco;
        cep = _cep;
    }

    
    string getTelefone() const { return telefone; }
    void setTelefone(string _telefone) { telefone = _telefone; }

    string getNome() const { return nome; }
    void setNome(string _nome) { nome = _nome; }

    string getEndereco() const { return endereco; }
    void setEndereco(string _endereco) { endereco = _endereco; }

    string getCep() const { return cep; }
    void setCep(string _cep) { cep = _cep; }

    
    void imprimirContato() const
    {
        cout << "Nome: " << nome << endl;
        cout << "Telefone: " << telefone << endl;
        cout << "Endereco: " << endereco << endl;
        cout << "CEP: " << cep << endl;
        cout << endl;
    }
};

int main() 
{
    
    Contato contato1("61982582527", "Joao", "sqs 415, 205", "15366-371");
    Contato contato2("61984761069", "Ana", "sqs 405, 104", "24341-857");
    Contato contato3("61981943390", "Fabio", "sqn 109, 306", "18325-478");
    Contato contato4("6184362352", "Catarina", "sqn 309, 201", "27493-903");

    
    cout << "Dados do Contato 1:" << endl;
    contato1.imprimirContato();

    cout << "Dados do Contato 2:" << endl;
    contato2.imprimirContato();

    cout << "Dados do Contato 3:" << endl;
    contato3.imprimirContato();

    cout << "Dados do Contato 4:" << endl;
    contato4.imprimirContato();

    return 0;
}
