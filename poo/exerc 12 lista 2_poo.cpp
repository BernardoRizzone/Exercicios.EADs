#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dono
{
private:
    string nome;
    string telefone;

public:
    Dono() {}

    Dono(string _nome, string _telefone) : nome(_nome), telefone(_telefone) {}

    
    void cadastrarDadosPessoais() 
    {
        cout << "Digite seu nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Digite seu telefone: ";
        getline(cin, telefone);
    }

    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }
};

class Carro
{
private:
    string marca;
    string placa;
    string cor;

public:
    Carro() {}

    Carro(string _marca, string _placa, string _cor) : marca(_marca), placa(_placa), cor(_cor) {}

    
    void cadastrarDadosVeiculo()
    {
        cout << "Digite a marca do veiculo: ";
        cin.ignore();
        getline(cin, marca);
        cout << "Digite a placa do veiculo: ";
        getline(cin, placa);
        cout << "Digite a cor do veiculo: ";
        getline(cin, cor);
    }

    string getMarca() const { return marca; }
    string getPlaca() const { return placa; }
    string getCor() const { return cor; }
};

class CadastroCarros
{
private:
    vector<Carro> carros;

public:
    void adicionarCarro(const Carro& carro) 
    {
        carros.push_back(carro);
    }

    void imprimirCarros() const
    {
        cout << "Lista de Carros Cadastrados:" << endl;
        for (const auto& carro : carros)
        {
            cout << "Marca: " << carro.getMarca() << endl;
            cout << "Placa: " << carro.getPlaca() << endl;
            cout << "Cor: " << carro.getCor() << endl;
            cout << endl;
        }
    }
};

int main()
{
    CadastroCarros cadastro;

    Dono dono;
    Carro carro;

    
    cout << "=== Cadastro de Dados Pessoais ===" << endl;
    dono.cadastrarDadosPessoais();
    cout << "\n=== Cadastro de Dados do Veiculo ===" << endl;
    carro.cadastrarDadosVeiculo();

    cadastro.adicionarCarro(carro);

    
    cadastro.imprimirCarros();

    return 0;
}
