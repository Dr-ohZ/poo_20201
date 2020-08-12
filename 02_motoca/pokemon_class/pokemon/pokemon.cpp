#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Pokemon{
    string name;
    int lvl, xp;
    int hp, hp_max;

    Pokemon(string name = "Dito", int hp_max = 15) {
        if (hp_max > 15)
            hp_max = 15;
        this->name = name;
        this->lvl = 1;
        this->xp = 0;
        this->hp = hp_max;
        this->hp_max = hp_max;
        cout << "A wild pokemon appears!!!" << endl;
    }

    ~Pokemon(){
        cout << name << " is free!!!" << endl;
    }

    string to_String(){
        return "Nome: " + this->name + "\nXP/LvL: " + to_string(this->xp) + "/" + to_string(this->lvl) + "\tHP/MaxHP: " + to_string(this->hp) + "/" + to_string(this->hp_max);
    }


};

struct Pokeball{
    Pokemon * pokemon = {nullptr};

    void capture(Pokemon * pokemon){
        if (this->pokemon != nullptr)
            cout << "Pokeball already has a pokemon" << endl;
        else
            this->pokemon = pokemon;        
    }

    Pokemon * release(){
        if(this->pokemon == nullptr){
            cout << to_String() << endl;
            return nullptr;
        }
        Pokemon * temp = this->pokemon;
        this->pokemon = nullptr;
        cout << to_String() << endl;
        return temp;
    }

    string to_String(){
        if (this->pokemon == nullptr)
            return "None pokemon has been captured yet.";
        
        return "\t\tPokemon:\n" + this->pokemon->to_String();
    }

    void train(){
        if(!in_combat())
            return;
        this->pokemon->hp = max(this->pokemon->hp - (this->pokemon->hp_max / 4), 0);
        this->pokemon->xp += max(this->pokemon->lvl / 5, 1);
        level_up();
        cout << to_String() << endl;
        if (this->pokemon->hp <= 0)
            cout << this->pokemon->name + " is out of combat." << endl;
    }
    
    void recovery(){
        if (this->pokemon == nullptr){
            cout << to_String() << endl;
            return;
        }
        this->pokemon->hp = this->pokemon->hp_max;
        cout << to_String() << endl << this->pokemon->name + " has been recovered." << endl; 
    }

    void battle(){
        if(!in_combat())
            return;

        for(int rounds = 0; rounds < 3; rounds++){
            int damage = damage_taken();
            cout << this->pokemon->name + " has taken " << damage << " of damage!" << endl;
            this->pokemon->hp = battle_damage(damage);
            if(!in_combat())
                return;      
        }
        this->pokemon->xp += max(this->pokemon->lvl / 4, 1);
        cout << to_String() << endl;  
        level_up();
        
    }

    void level_up(){
        if(!in_combat())
            return;
        if (this->pokemon->xp >= 3 * this->pokemon->lvl){
                this->pokemon->xp = 0;
                this->pokemon->lvl += 1;
                this->pokemon->hp_max += 5;
                cout << this->pokemon->name + " level up!";
        }

    }

    bool in_combat(){
        if (this->pokemon == nullptr){
            cout << to_String() << endl;
            return false;
        }
        if (this->pokemon->hp <= 0){
            cout << this->pokemon->name + " is out of combat." << endl;
            return false;
        }
        return true;
    }

    int damage_taken(){
        int floor_damage = max(this->pokemon->hp_max / 10, 1);
        int ceiling_damage = max(this->pokemon->hp_max / 3, 1);
        float lvl_modfier = 1 - (this->pokemon->lvl / 100);
        return (rand() %  (ceiling_damage - floor_damage) + floor_damage) * lvl_modfier;

    }

    int battle_damage(int damage){
        int new_hp = max(this->pokemon->hp - damage, 0);
        if(new_hp == 0)
            cout << "\n" + this->pokemon->name + " has been defeated!\n" << endl;
        return new_hp;
    }
};


int main(){
    srand((unsigned)time(0));
    Pokeball pokeball;
    while (true){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "end")
            break;
        else if(cmd == "capture"){
            string nome;
            int hp = 0;
            ss >> nome >> hp;
            pokeball.capture(new Pokemon(nome, hp));
        }else if(cmd == "show"){
            cout << pokeball.to_String() << endl;

        }else if(cmd == "release"){
            Pokemon * temp = pokeball.release();
            if(temp != nullptr)
                delete temp;
        }else if(cmd == "train"){
            pokeball.train();
        }else if(cmd == "recovery"){
            pokeball.recovery();
        }else if(cmd == "battle"){
            pokeball.battle();
        }else
            cout << "Invalid comand!!!" << endl;
    }

}
