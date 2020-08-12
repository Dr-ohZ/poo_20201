#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void show(vector<int>& vet){
    cout << "[ ";
    for(auto v : vet)
        cout << v << " ";
    cout << "]" << endl;

}

void rshow(vector<int>& vet){
    cout << "[ ";
    for(int i = vet.size() - 1; i >= 0; i--)
    cout << vet[i] << " ";
    cout << "]" << endl;

}

int find(vector<int>& vet, int value){
    for(int i = 0; i < vet.size(); i++){
        if(vet[i] == value)
            return i;
    }
    return -1;
}

void insert(vector<int>& vet, int pos, int value){

    if(pos < 0)
        return;

    if(pos > vet.size())
        pos = vet.size();
    vet.insert(vet.begin() + pos, value);

}

bool remove(vector<int>& vet, int pos){
    if(pos < 0 || pos >= vet.size())
        return false;
    vet.erase(vet.begin() + pos);
    return true;
}

void remove_all(vector<int>& vet, int value){
    std::vector<int>::iterator it = vet.begin();
    while (it != vet.end()){
        if(*it == value)
            vet.erase(it);
        else
            it++;
    }
    
}

int main(){
    vector<int> vet;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if(line == "end"){
            break;
        }else if(cmd == "add"){
            int value;
            while(ss >> value)
                vet.push_back(value);
        }else if(cmd == "show"){
            show(vet);
        }else if(cmd == "get"){
            int pos;
            ss >> pos;
            cout << vet[pos] << endl;
        }else if(cmd == "set"){
            int pos, value;
            ss >> pos >> value;
            vet[pos] = value;
        }else if(cmd == "rshow"){
            rshow(vet);
        }else if(cmd == "find"){

            int value;
            cout << "[ ";
            while(ss >> value)
                cout << find(vet, value) << " ";
            cout << "]\n";

        }else if(cmd == "ins"){
            int pos, value;
            ss >> pos >> value;
            insert(vet, pos, value);
        }else if(cmd == "rmi"){
            int pos;
            ss >> pos;
            if(!remove(vet,pos))
                cout << "fail" << endl;
        }else if(cmd == "rma"){
            int value;
            ss >> value;
            remove_all(vet, value);
        }else{
            cout << "Comando invalido\n";
        }
    }
}