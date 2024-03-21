#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Aluno 
{
private:
    string nome;
    string matricula;
    string curso;

public:
    
    Aluno(string nome, string matricula, string curso)
    {
        this->nome = nome;
        this->matricula = matricula;
        this->curso = curso;
    }

    
    void imprimirDados() 
    {
        cout << "Nome: " << nome << endl;
        cout << "Matrícula: " << matricula << endl;
        cout << "Curso: " << curso << endl;
    }
};

int main()
{
    
    vector<Aluno> alunos;

    
    string nome, matricula, curso;
    char opcao;

    
    do
    {
        cout << "\nCadastro de Alunos:" << endl;
        cout << "Digite o nome do aluno: ";
        cin >> nome;
        cout << "Digite a matrícula do aluno: ";
        cin >> matricula;
        cout << "Digite o curso do aluno: ";
        cin >> curso;

        
        alunos.push_back(Aluno(nome, matricula, curso));

        cout << "\nDeseja cadastrar outro aluno? (S/N): ";
        cin >> opcao;
    } while (opcao == 'S' || opcao == 's');

    
    cout << "\nAlunos cadastrados:" << endl;
    for (const Aluno& aluno : alunos)
    {
        aluno.imprimirDados();
        cout << endl;
    }

    return 0;
}

