#include <iostream>
using namespace std;

struct Carro{
    int nPessoas = 0;
    int maxPessoas = 2;
    float gasolina = 0;

    bool embarcar(){
        if (this->nPessoas < this->maxPessoas){
            this->nPessoas++;
            cout << "embarcou\n";
            return true;
        }
        cout << "ta lotado\n";
        return false;
    }

    bool desembarcar(){
        if (this->nPessoas <= 0){
            cout << "tá vazio\n";
            return false;
        }
        this->nPessoas--;
        cout << "desembarcou!\n";
        return true;
    }
};

int main() {
    Carro * carro = new Carro();
    Carro * carro2 = carro;
    carro->embarcar();
    carro->embarcar();
    carro->embarcar();
    cout << carro->nPessoas << "\n";
    cout << carro2->nPessoas << "\n";
    carro->desembarcar();
    cout << carro->nPessoas << "\n";
    return 0;
}

