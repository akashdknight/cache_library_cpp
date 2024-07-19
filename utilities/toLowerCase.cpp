#include <iostream>

#include "toLowerCase.h"

using namespace std;

void toLowerCase(string &targetString){
    for(auto &character : targetString){
        character = (char)tolower(character);
    }
}