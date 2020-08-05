#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;

bool is_digit(const char value) { return std::isdigit(value); }
bool is_numeric(const std::string& value) { return std::all_of(value.begin(), value.end(), is_digit); }

class Carro{

public:
    int nPessoas;
    int maxPessoas;
    float gasolina;
    float maxGasolina;
    float km;

    Carro(){
        this->nPessoas = 0;
        this->maxPessoas = 2;
        this->gasolina = 0;
        this->maxGasolina = 100;
        this->km = 0;
    }

    /*
    Carro(int nPessoas = 0, int maxPessoas = 2, float gasolina = 0, float maxGasolina = 100, float km = 0){
        this->nPessoas = nPessoas;
        this->maxPessoas = maxPessoas;
        this->gasolina = gasolina;
        this->maxGasolina = maxGasolina;
        this->km = km;
    }
    //*/

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

    void abastecer(float gasosa){
        cout << "abastecendo!\n";
        this->gasolina = fmin((this->gasolina + gasosa), this->maxGasolina);
    }

    void dirigir(int km){
        if (this->nPessoas <= 0){
            cout << "um carro fantasma?\n";
            return;
        }

        if(this->gasolina < km){
            cout << "sem gasosa, tururu\n";
            return;
        }

        this->gasolina -= km;
        this->km += km;
        cout << "simbora!!!\n";
    }

    float get_km(){
        return this->km;
    }

    float get_gasosa(){
        return this->gasolina;
    }

    int get_pessoas(){
        return this->nPessoas;
    }
};

int main() {
    Carro carro;

    while(true){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        string param;
        ss >> cmd;

        if(cmd == "end")
            break;
        else if(cmd == "embarcar")
            carro.embarcar();
        else if(cmd == "desembarcar")
            carro.desembarcar();
        else if(cmd == "abastecer"){
           ss >> param;
            if(param.size() > 0){
                carro.abastecer(strtof((param).c_str (), 0));
            }else{
                cout << "precisa dizer quanto meu jovem\n";
            }
        }else if(cmd == "dirigir"){
            ss >> param;
            if(param.size() > 0){
                carro.dirigir(strtof((param).c_str (), 0));
            }else{
                cout << "vai andar quanto peste?\n";
            }
        }else if(cmd == "quilometragem"){
            cout << carro.get_km() << " Km\n";
        }else if(cmd == "tanque"){
            cout << carro.get_gasosa() << " L\n";
        }else if(cmd == "pessoas"){
            cout << carro.get_pessoas() << " pessoas no carro\n";
        }else{
            cout << "Comando inválido!\n";
        }

    }

    return 0;
}

