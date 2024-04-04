#include <iostream>
#include <string>

using namespace std;

class Pessoa {
protected:
    string nome;
    int idade;

public:
    Pessoa(const string& nome, int idade)
        : nome(nome), idade(idade) {}

    string getNome() const { return nome; }
    int getIdade() const { return idade; }
};

class Empregado : public Pessoa {
protected:
    float salarioBase;
    float valorVendas;

public:
    Empregado(const string& nome, int idade, float salarioBase, float valorVendas)
        : Pessoa(nome, idade), salarioBase(salarioBase), valorVendas(valorVendas) {}

    virtual float calcularSalario() const {
        return salarioBase;
    }

    float getValorVendas() const { return valorVendas; }
};

class Vendedor : public Empregado {
private:
    float comissao;

public:
    Vendedor(const string& nome, int idade, float salarioBase, float valorVendas, float comissao)
        : Empregado(nome, idade, salarioBase, valorVendas), comissao(comissao) {}

    float calcularSalario() const override {
        float salario = salarioBase + (comissao / 100.0) * valorVendas;
        return salario;
    }
};

int main() {
    string nome;
    int idade;
    float salarioBase, valorVendas, comissao;

    cout << "Digite o nome do vendedor: ";
    getline(cin, nome);

    cout << "Digite a idade do vendedor: ";
    cin >> idade;

    cout << "Digite o salario base do vendedor: ";
    cin >> salarioBase;

    cout << "Digite o valor das vendas do vendedor: ";
    cin >> valorVendas;

    cout << "Digite a comissao do vendedor (em porcentagem): ";
    cin >> comissao;

    // Criando um objeto Vendedor com as informações fornecidas pelo usuário
    Vendedor vendedor(nome, idade, salarioBase, valorVendas, comissao);

    cout << "\nInformacoes do Vendedor:" << endl;
    cout << "Nome: " << vendedor.getNome() << endl;
    cout << "Idade: " << vendedor.getIdade() << endl;
    cout << "Salario Base: " << salarioBase << endl;
    cout << "Valor das Vendas: " << valorVendas << endl;
    cout << "Comissao: " << comissao << "%" << endl;
    cout << "Salario total: " << vendedor.calcularSalario() << endl;

    return 0;
}
