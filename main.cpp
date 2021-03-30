#include <iostream>
#include <string>
using namespace std;

bool checkInput(string str){
    bool check = false;
    for(int i = 0; i < str.length(); i++){
        if (str[i] == 'O' || str[i] == 'X' || str[i] == '.') check = true;
    }
    return check;
}

bool checkLength(string str){
    return str.length() == 9;
}

char getSymbol(string str, int x, int y){
    return str[y*3 + x];
}

string getSubColumn(string str, int index){
    string temp = "";
    for(int i = 0; i <= 2; i++){
        temp += getSymbol(str, index, i);
    }
    return temp;
}

string getDiagonal1(string str){
    string temp = "";
    for(int i = 0; i < 3; i++){
        temp += getSymbol(str, i, i);
    }
    return temp;
}

string getDiagonal2(string str){
    string temp = "";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 2-j) temp += getSymbol(str, i, j);
        }
    }
    return temp;
}

int countSymbols(string str, char sym){
    int count = 0;
    for(int i = 0; i < str.length(); i++){
        if (str[i] == sym) count ++;
    }
    return count;
}

bool PetyaWon(string str){
    bool temp = false;
    string XXX = "XXX";
    for(int i = 0; i < 3; i++){
        if(XXX == str.substr(i * 3, 3) || XXX == getSubColumn(str, i) || XXX == getDiagonal1(str) || XXX == getDiagonal2(str)) temp = true;
    }
    return temp;
}

bool VanyaWon(string str){
    bool temp = false;
    string OOO = "OOO";
    for(int i = 0; i < 3; i++){
        if(OOO == str.substr(i * 3, 3) || OOO == getSubColumn(str, i) || OOO == getDiagonal1(str) || OOO == getDiagonal2(str)) temp = true;
    }
    return temp;
}

int main() {
    string str1, str2, str3, str;
    int countO, countX;

    cout << "Enter 3 strings: " << std::endl;
    cin >> str1 >> str2 >> str3;
    str = str1 + str2 + str3;

    countO = countSymbols(str, 'O');
    countX = countSymbols(str, 'X');

    if(checkInput(str) == false || checkLength(str) == false || countO > countX || (countX - countO) > 1 ||
       (PetyaWon(str) && VanyaWon(str)) || (VanyaWon(str) && (countX > countO) ) || (PetyaWon(str) && countX == countO)){
        cout << "Incorrect.\n";
    }
    else {
        if(PetyaWon(str)) cout << "Petya won.\n";
        else if(VanyaWon(str) && (countO == countX)) cout << "Vanya won.\n";
        else cout << "Nobody.\n";
    }

    return 0;
}
