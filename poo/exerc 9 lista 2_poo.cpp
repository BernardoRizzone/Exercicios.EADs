#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Aluno
{
private:
    string nome;
    string matricula;
    int idade;
    int semestre;
    string curso;

public:
    
    Aluno(string _nome, string _matricula, int _idade, int _semestre, string _curso) 
    {
        nome = _nome;
        matricula = _matricula;
        idade = _idade;
        semestre = _semestre;
        curso = _curso;
    }

    
    string getNome() { return nome; }
    string getMatricula() { return matricula; }
    int getIdade() { return idade; }
    int getSemestre() { return semestre; }
    string getCurso() { return curso; }
};

class CadastroAlunos
{
private:
    vector<Aluno> alunos;

public:
    
    void adicionarAluno()
    {
        string nome, matricula, curso;
        int idade, semestre;

        cout << "Digite o nome do aluno: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Digite a matricula do aluno: ";
        getline(cin, matricula);
        cout << "Digite a idade do aluno: ";
        cin >> idade;
        cout << "Digite o semestre do aluno: ";
        cin >> semestre;
        cout << "Digite o curso do aluno: ";
        cin.ignore();
        getline(cin, curso);

        alunos.push_back(Aluno(nome, matricula, idade, semestre, curso));
    }

    
    void listarAlunos()
    {
        cout << "Lista de Alunos:" << endl;
        for (size_t i = 0; i < alunos.size(); ++i) {
            cout << "Nome: " << alunos[i].getNome() << endl;
            cout << "Matrícula: " << alunos[i].getMatricula() << endl;
            cout << "Idade: " << alunos[i].getIdade() << endl;
            cout << "Semestre: " << alunos[i].getSemestre() << endl;
            cout << "Curso: " << alunos[i].getCurso() << endl;
            cout << endl;
        }
    }
};

int main()
{
    CadastroAlunos cadastro;

    int opcao;

    do {
        cout << "Menu:" << endl;
        cout << "1. Adicionar aluno" << endl;
        cout << "2. Listar alunos" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastro.adicionarAluno();
                break;
            case 2:
                cadastro.listarAlunos();
                break;
            case 3:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while (opcao != 3);

    return 0;
}
