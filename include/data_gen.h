#ifndef DATA_GEN_H
#define DATA_GEN_H
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class data_gen {
    public:
        data_gen();
        virtual ~data_gen();
        std::string gen_data(int rangeStart, int rangeEnd);

    protected:

    private:
};

#endif // DATA_GEN_H
