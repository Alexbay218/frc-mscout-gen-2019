#include "data_gen.h"

data_gen::data_gen() {
    srand(time(NULL));
}

std::string data_gen::gen_data(int rangeStart, int rangeEnd) {
    std::stringstream res;
    int a = 0;
    res << (rand() % 4999 + 1) << ";";
    res << (rand() % (rangeEnd - rangeStart + 1) + rangeStart) << ";";
    res << (1546318 + rand() % 31536) << "800000;";
    res << "T;" << (rand() % 119 + 1) << ";:";
    res << "cargoCount,1;hatchCount,0;:";
    a = rand() % 3;
    if(a == 0) {
        res << "a," << (rand() % 10) << "." << (rand() % 99) << ";";
    }
    else if(a == 1) {
        res << "b," << (rand() % 10) << "." << (rand() % 99) << ";";
    }
    a = 0;
    float currTime = 10;
    float r = 0;
    bool hasSomething = true;
    while(currTime < 135) {
        r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        currTime += r * 10;
        if(!hasSomething) {
            a = rand() % 2;
            if(a == 0) {
                res << "c," << currTime << ";";
            }
            else {
                res << "e," << currTime << ";";
            }
            hasSomething = true;
        }
        else {
            a = rand() % 9;
            if(a == 0) {
                if(rand() % 2 == 0) {
                    res << "d," << currTime << ";";
                }
                else {
                    res << "f," << currTime << ";";
                }
            }
            if(a == 1) {res << "g," << currTime << ";";}
            if(a == 2) {res << "h," << currTime << ";";}
            if(a == 3) {res << "i," << currTime << ";";}
            if(a == 4) {res << "j," << currTime << ";";}
            if(a == 5) {res << "k," << currTime << ";";}
            if(a == 6) {res << "l," << currTime << ";";}
            if(a == 7) {res << "m," << currTime << ";";}
            if(a == 8) {res << "n," << currTime << ";";}
            hasSomething = false;
        }
        if(rand() % 10 == 0) {
            r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            currTime += r * 5;
            if(rand() % 2 == 0) {
                res << "s," << currTime << ";";
            }
            else {
                res << "t," << currTime << ";";
            }
        }
    }
    r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    currTime += r * 10;
    while(currTime < 150) {
        r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        a = rand() % 4;
        if(a == 0) {res << "o," << currTime << ";";}
        if(a == 1) {res << "p," << currTime << ";";}
        if(a == 2) {res << "q," << currTime << ";";}
        if(a == 3) {res << "r," << currTime << ";";}
        currTime += r * 10;
    }
    res << "This comment has random number of " << rand() % 999;
    return res.str();
}

data_gen::~data_gen()
{
    //dtor
}
