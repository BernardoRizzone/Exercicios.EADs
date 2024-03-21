#include <iostream>
#include <string>
using namespace std;


class Aluno
{
private:
    string nome;
    float matricula;
    string curso;
    float notas;
    int faltas;

public:
    
    Aluno(string nome, float matricula, string curso, float notas, int faltas)
    {
        this->nome = nome;
        this->matricula = matricula;
        this->curso = curso;
        this->notas = notas;
        this->faltas = faltas;
    }

    
    void imprimirDados() 
    {
        cout << "Nome: " << nome << endl;
        cout << "Matrícula: " << matricula << endl;
        cout << "Curso: " << curso << endl;
        cout << "notas: " << notas << endl;
        cout << "faltas " << faltas << endl;
    }
};

int main() 
{
    const int MAX_ALUNOS = 100; 
    Aluno alunos[MAX_ALUNOS]; 
    int numAlunos = 0; 
    char opcao;

    
    do 
    {
        cout << "\nCadastro de Alunos:" << endl;
        cout << "Digite o nome do aluno: ";
        cin >> alunos[numAlunos].nome;
        cout << "Digite a matrícula do aluno: ";
        cin >> alunos[numAlunos].matricula;
        cout << "Digite o curso do aluno: ";
        cin >> alunos[numAlunos].curso;
        cout << "Digite a nota do aluno ";
        cin >> alunos[numAlunos].notas;
        cout << "Digite as faltas do aluno: ";
        cin >> alunos[numAlunos].falta;

        numAlunos++; 

        cout << "\nDeseja cadastrar outro aluno? (S/N): ";
        cin >> opcao;
    } while (opcao == 'S' || opcao == 's');

    
    cout << "\nAlunos cadastrados:" << endl;
    for (int i = 0; i < numAlunos; ++i) {
        cout << "\nDados do aluno " << i + 1 << ":" << endl;
        alunos[i].imprimirDados();
    }

    return 0;
}

