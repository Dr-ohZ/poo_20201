#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

class Espiral{
public:
    std::string nome;
    int qtd;
    float value;

    Espiral():
        Espiral("-", 0, 0.0){

        }

    Espiral(std::string nome, int qtd, float value):
        nome(nome), qtd(qtd), value(value){

        }
    std::string toString(){
        std::stringstream ss;
        ss << this->nome << " : " << this->qtd << " U : " << this->value << " R$";
        return ss.str();
    }

};

class Machine{
public:
    float saldo;
    int max;
    std::vector<Espiral*> espirais;

    Machine():
        Machine(0, 0){

        }

    Machine(int qtd, int max):
        espirais(qtd){
            this->saldo = 0;
            this->max = max;
            for(std::vector<Espiral*>::iterator it = this->espirais.begin(); it != this->espirais.end(); it++)
                *it = new Espiral();
            
        }
    
    void toString(){
        std::cout << "Saldo: " << this->saldo << std::endl;
        for(int i = 0; i < this->espirais.size(); i++)
            std::cout << i << " [ " + this->espirais[i]->toString() + " ]" << std::endl;
    }

    void set(int pos, std::string nome, int qtd, float value){
        if(pos < 0 || pos > this->espirais.size()){
            std::cout << "Error: out of index!\n";
            return;
        }

        if(qtd < 0 || qtd > this->max){
            std::cout << "Error: quantity has not a permissible value or max units quantity exceeded!\n";
            return;
        }
        Espiral * esp = this->espirais[pos];
        if(esp->nome != "-"){
            std::cout << "Error: espiral is already busy!\n";
            return;
        }
        this->espirais[pos] = new Espiral(nome, qtd, value);
        delete esp;
    }

    void clear(int pos){
        if(pos < 0 || pos >= this->espirais.size()){
            std::cout << "Error: out of index!\n";
            return;
        }
        Espiral * esp = this->espirais[pos];
        this->espirais[pos] = new Espiral();
        delete esp;
    }

    void cash(float cash){
        if(cash < 0)
            cash *= -1;
        this->saldo += cash;
    }

    void troco(){
        std::cout << "Was paid back to you: " << this->saldo << std::endl;
        this->saldo = 0;
    }

    void buy(int pos){
        if(pos < 0 || pos >= this->espirais.size()){
            std::cout << "Error: out of index!\n";
            return;
        }
        Espiral * esp = this->espirais[pos];
        if(esp->nome == "-" || esp->qtd == 0){
            std::cout << "Error: there is no product!\n";
            return;
        }
        if(esp->value > this->saldo){
            std::cout << "Error: saldo is not enough!\n";
            return;
        }
        this->saldo -= esp->value;
        esp->qtd--;
        std::cout << "You bought one " + esp->nome << std::endl;
        
    }

};

int main(){
    std::cout << std::setprecision(2) << std::fixed;
    Machine machine;
    std::string line, cmd;
    //*
    while (true){
        
        getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        if(cmd == "end")
            break;
        else if(cmd == "init"){
            int qtd, max;
            ss >> qtd >> max;            
            machine = Machine(qtd, max);
        }else if(cmd == "show"){
            machine.toString();
        }else if(cmd == "set"){
            int pos, qtd;
            std::string nome;
            float value;
            ss >> pos >> nome >> qtd >> value;
            machine.set(pos, nome, qtd, value);
        }else if(cmd == "clr"){
            int pos;
            ss >> pos;
            machine.clear(pos);
        }else if(cmd == "cash"){
            float cash;
            ss >> cash;
            machine.cash(cash);
        }else if(cmd == "troco"){
            machine.troco();
        }else if(cmd == "buy"){
            int pos;
            ss >> pos;
            machine.buy(pos);
        }else
            std::cout << "Invalid comand!!!" << std::endl;
    }//*/
}