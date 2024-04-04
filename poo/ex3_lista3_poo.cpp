#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Produto 
{
protected:
    string nome;
    float precoUnitario;
    int quantidadeEstoque;

public:
    Produto(const string& nome, float precoUnitario, int quantidadeEstoque)
        : nome(nome), precoUnitario(precoUnitario), quantidadeEstoque(quantidadeEstoque) {}

    virtual float calcularValorTotal() const 
    {
        return precoUnitario * quantidadeEstoque;
    }

    virtual void salvarDados(ofstream& arquivo) const 
    {
        arquivo << nome << " " << precoUnitario << " " << quantidadeEstoque << " ";
    }

    string getNome() const { return nome; }
    float getPrecoUnitario() const { return precoUnitario; }
    int getQuantidadeEstoque() const { return quantidadeEstoque; }
};

class Eletronico : public Produto
 {
private:
    float consumoEnergia;
    int voltagemSuportada;

public:
    Eletronico(const string& nome, float precoUnitario, int quantidadeEstoque, float consumoEnergia, int voltagemSuportada)
        : Produto(nome, precoUnitario, quantidadeEstoque), consumoEnergia(consumoEnergia), voltagemSuportada(voltagemSuportada) {}

    void salvarDados(ofstream& arquivo) const override 
    {
        Produto::salvarDados(arquivo);
        arquivo << consumoEnergia << " " << voltagemSuportada << endl;
    }
};

class Alimento : public Produto
{
private:
    string prazoValidade;

public:
    Alimento(const string& nome, float precoUnitario, int quantidadeEstoque, const string& prazoValidade)
        : Produto(nome, precoUnitario, quantidadeEstoque), prazoValidade(prazoValidade) {}

    void salvarDados(ofstream& arquivo) const override 
    {
        Produto::salvarDados(arquivo);
        arquivo << prazoValidade << endl;
    }
};

void salvarProdutos(const vector<Produto*>& produtos, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) 
    {
        for (const auto& produto : produtos) {
            produto->salvarDados(arquivo);
        }
        arquivo.close();
        cout << "Dados dos produtos salvos com sucesso em " << nomeArquivo << endl;
    } else 
    {
        cout << "Erro ao abrir o arquivo " << nomeArquivo << endl;
    }
}

int main() 
{
    vector<Produto*> produtos;

    char opcao;
    do {
        cout << "\nEscolha o tipo de produto a ser cadastrado:" << endl;
        cout << "1. Eletronico" << endl;
        cout << "2. Alimento" << endl;
        cout << "3. Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == '1') 
        {
            string nome;
            float precoUnitario, consumoEnergia;
            int quantidadeEstoque, voltagemSuportada;

            cout << "\nDigite o nome do produto eletronico: ";
            cin >> nome;
            cout << "Digite o preco unitario do produto: ";
            cin >> precoUnitario;
            cout << "Digite a quantidade em estoque do produto: ";
            cin >> quantidadeEstoque;
            cout << "Digite o consumo de energia do produto (em watts): ";
            cin >> consumoEnergia;
            cout << "Digite a voltagem suportada pelo produto: ";
            cin >> voltagemSuportada;

            produtos.push_back(new Eletronico(nome, precoUnitario, quantidadeEstoque, consumoEnergia, voltagemSuportada));
        } else if (opcao == '2') 
        {
            string nome, prazoValidade;
            float precoUnitario;
            int quantidadeEstoque;

            cout << "\nDigite o nome do alimento: ";
            cin >> nome;
            cout << "Digite o preco unitario do alimento: ";
            cin >> precoUnitario;
            cout << "Digite a quantidade em estoque do alimento: ";
            cin >> quantidadeEstoque;
            cout << "Digite o prazo de validade do alimento: ";
            cin >> prazoValidade;

            produtos.push_back(new Alimento(nome, precoUnitario, quantidadeEstoque, prazoValidade));
        }

    } while (opcao != '3');

    salvarProdutos(produtos, "dados_produtos.txt");

    
    for (auto& produto : produtos)
    {
        delete produto;
    }

    return 0;
}
