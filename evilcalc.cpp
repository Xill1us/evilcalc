#include <iostream>
#include <limits>
#include <ctime>

/// vars

int evilness = 0;
int maxEvilness = 10;
int diff = 2;

/// functions

int add (int a, int b){
    int random = rand() % maxEvilness;
    if (random <= evilness){
        std::cout << "event happened!: send (int add) returning -1" << std::endl;
        std::cout << "debug: rolled " << random << "evilness " << evilness << "diff " << diff << std::endl;
        evilness = 0;
        return -1;
    }
    else{
        std::cout << evilness << " " << random << std::endl;
        return a+b;
    }
}

/// main

int main(int argc, char const *argv[])
{
    srand(time(nullptr)); // dude stop rolling 3
    std::string selection;
    std::cout << "totally not evil calculator" << std::endl;
    std::cout << "select difficulty:" << std::endl;
    std::cout << "[1] - easy (max 15 evilness)" << std::endl << "[2] - normal (max 10 evilness)" << std::endl << "[3] - hard (max 5 evilness)" << std::endl << "selection (default: 2): ";
    std::cin >> selection;
    try{
        if (std::stoi(selection) > 0 && std::stoi(selection) < 4){
            diff = std::stoi(selection);
            if (diff == 1) maxEvilness = 15;
            else if (diff == 2) maxEvilness = 10;
            else maxEvilness = 5;
        }
        else{
            diff = 2;
            maxEvilness = 10;
        }
    }
    catch(std::exception ex){
        std::cout << "dude what i told u to put a number there" << std::endl << "exception: " << ex.what() << std::endl << "i will now close thanks man have a GREAT dayyy"; return -1;
    }

    std::string math;
    clearenv;
    std::cout << "math thingy: ";
    std::cin >> math;

    // this sucks
    char thing;
    int thingPos;
    int a;
    std::string aStr;
    int b;
    std::string bStr;
    for (int i = 0; i < math.length(); i++){
        if (math[i] == '+'){
            thing = '+'; thingPos = i; break;
        }
    }
    for (int i = 0; i < thingPos; i++){
        aStr += math[i];
    }
    a = std::stoi(aStr);
    for (int i = thingPos+1; i < math.length(); i++){
        bStr += math[i];
    }
    b = std::stoi(bStr);

    if (thing = '+'){
        evilness += 1;
        if (evilness > maxEvilness){
            evilness = maxEvilness;
        }
        int answr = add(a, b);
        std::cout << answr << std::endl;
    }
    
    // why does this thing even exist
    return 0;
}
