#include <iostream>
#include <cmath>
using namespace std;

class Calculadora {
private:
    const double PI = 3.14;
    double raioCirculo;
    double ladoCubo;

    
    double calcularComprimentoCircunferencia() {
        return 2 * PI * raioCirculo;
    }

    double calcularAreaCircunferencia() {
        return PI * pow(raioCirculo, 2);
    }

    double calcularAreaLateralCubo() {
        return 4 * pow(ladoCubo, 2);
    }

    double calcularAreaTotalCubo() {
        return 6 * pow(ladoCubo, 2);
    }

    double calcularVolumeCubo() {
        return pow(ladoCubo, 3);
    }

public:
    
    void definirDimensoesCirculo(double raio) {
        raioCirculo = raio;
    }

    void definirDimensoesCubo(double lado) {
        ladoCubo = lado;
    }

    
    void imprimirCalculos() {
        cout << "Círculo:" << endl;
        cout << "Comprimento da circunferência: " << calcularComprimentoCircunferencia() << endl;
        cout << "Área da circunferência: " << calcularAreaCircunferencia() << endl << endl;

        cout << "Cubo:" << endl;
        cout << "Área lateral do cubo: " << calcularAreaLateralCubo() << endl;
        cout << "Área total do cubo: " << calcularAreaTotalCubo() << endl;
        cout << "Volume do cubo: " << calcularVolumeCubo() << endl;
    }
};

int main() {
    Calculadora calculadora;

    double raio, lado;
    cout << "Digite o raio do círculo: ";
    cin >> raio;

    cout << "Digite o lado do cubo: ";
    cin >> lado;

    
    calculadora.definirDimensoesCirculo(raio);
    calculadora.definirDimensoesCubo(lado);

    
    calculadora.imprimirCalculos();

    return 0;
}

