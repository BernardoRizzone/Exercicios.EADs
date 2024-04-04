#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Veiculo 
{
private:
    float peso;
    int ano;
    string cor;
    string marca;

public:
    
    Veiculo(float peso, int ano, const string& cor, const string& marca)
        : peso(peso), ano(ano), cor(cor), marca(marca) {}

    
    void setPeso(float novoPeso) { peso = novoPeso; }
    void setAno(int novoAno) { ano = novoAno; }
    void setCor(const string& novaCor) { cor = novaCor; }
    void setMarca(const string& novaMarca) { marca = novaMarca; }

    
    float getPeso() const { return peso; }
    int getAno() const { return ano; }
    string getCor() const { return cor; }
    string getMarca() const { return marca; }

    
    void imprimir() const 
    {
        cout << "Marca: " << marca << ", Ano: " << ano << ", Cor: " << cor << ", Peso: " << peso << " kg" << endl;
    }
};

class Concessionaria 
{
private:
    vector<Veiculo> veiculos;

public:
    
    void adicionarVeiculo(const Veiculo& veiculo) 
    {
        veiculos.push_back(veiculo);
    }

    
    void imprimirVeiculos() const 
    {
        cout << "Veiculos cadastrados:" << endl;
        for (const auto& veiculo : veiculos) {
            veiculo.imprimir();
        }
    }

    
    void imprimirEmArquivo(const string& nomeArquivo) const 
    {
        ofstream arquivo(nomeArquivo);
        if (arquivo.is_open()) 
        {
            arquivo << "Veiculos cadastrados:" << endl;
            for (const auto& veiculo : veiculos) 
            {
                arquivo << "Marca: " << veiculo.getMarca() << ", Ano: " << veiculo.getAno()
                        << ", Cor: " << veiculo.getCor() << ", Peso: " << veiculo.getPeso() << " kg" << endl;
            }
            cout << "Veiculos cadastrados foram salvos no arquivo: " << nomeArquivo << endl;
            arquivo.close();
        } else 
        {
            cout << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        }
    }
};

int main() {
    Concessionaria concessionaria;

    char adicionarMais;
    do {
        float peso;
        int ano;
        string cor, marca;

        cout << "Digite o peso do veiculo: ";
        cin >> peso;
        cout << "Digite o ano do veiculo: ";
        cin >> ano;
        cout << "Digite a cor do veiculo: ";
        cin.ignore(); 
        getline(cin, cor);
        cout << "Digite a marca do veiculo: ";
        getline(cin, marca);

        concessionaria.adicionarVeiculo(Veiculo(peso, ano, cor, marca));

        cout << "Deseja adicionar mais veiculos? (s/n): ";
        cin >> adicionarMais;
    } while (adicionarMais == 's' || adicionarMais == 'S');

    
    concessionaria.imprimirVeiculos();

    
    concessionaria.imprimirEmArquivo("veiculos_cadastrados.txt");

    return 0;
}
