#include <iostream>

using namespace std;

struct Pokemon
{
    int id;
    string nome, tipo, sexo;
    int lvl, xp;
    int hp, hp_max;
    int atk, def, spd, sp_atk, sp_def;
    string ability;
    int captured;

    Pokemon() {}

    bool capture(){

    }

    bool train(){

    }

    bool battle(){

    }

    bool recover(){
        this->hp = this->hp_max;
    }


};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
