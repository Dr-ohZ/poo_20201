#include <iostream>
#include <sstream>
using namespace std;


struct Pessoa {
    string nome;
    int idade;

    Pessoa(string nome = "", int idade = -1){
        this->nome = nome;
        this->idade = idade;
        cout << this->nome << " esta nascendo\n"; 
    }
    ~Pessoa(){
        cout << this->nome << " esta morrendo\n";
    }
};

struct Motinha{

    int potencia = 0, tempo;

    Pessoa * pessoa {nullptr}; //agregação

    Motinha(int p){
        this->potencia = p;
    }
    //Pessoa pessoa = null;
    void embarcar(Pessoa * pessoa){
        if(this->pessoa != nullptr)
            cout << "ja tem gente na motinha\n";
        else{
            this->pessoa = pessoa;
            this->tempo = 0;
        }

    }

    Pessoa * desembarcar(){
        if(this->pessoa == nullptr)
            return nullptr;
        Pessoa * temp = this->pessoa;
        this->pessoa = nullptr;
        return temp; 
    }

    void dirigir(int tempo){
        if(this->pessoa == nullptr)
            cout << "nao tem ninguem na motinha\n"; 
        else if(this->pessoa->idade >= 4){
            if(this->tempo >= tempo){
                cout << pessoa->nome << ": Urruuu, dando uma voltinha\n";
                fazer_barulho();
                this->tempo -= tempo;
            }else{
                cout << "tempo insuficiente, me dê mais dinheiro\n";
            }
        }
        else
            cout << pessoa->nome << "Você não sabe andar ainda\n";
    }

    void fazer_barulho(){
        for(int i = 0; i < this->potencia; i++)
            cout << "run ";
        cout << "\n";
    }

    void pagar(int tempo){
        this->tempo += tempo;

    }

};

int main() {
    Motinha *motinha = new Motinha(0);
    string line;
    string cmd;


    while(true){
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;

        if(cmd == "end"){
            break;
        }else if(cmd == "init"){//potencia
            int p;
            ss >> p;
            motinha = new Motinha(p);

        }else if(cmd == "embarcar"){//nome idade
            string nome;
            int idade;
            ss >> nome >> idade;
            
            motinha->embarcar(new Pessoa(nome, idade));

        }else if(cmd == "dirigir"){
            int tempo;
            ss >> tempo;
            motinha->dirigir(tempo);
        }else if(cmd == "desembarcar"){
            Pessoa * temp = motinha->desembarcar();
            if(temp != nullptr)
                delete temp;
        }else if(cmd == "pagar"){
            int grana;
            ss >> grana;
            motinha->pagar(grana);
        }else{
            cout << "comando invalido\n";
        }
    }
}

