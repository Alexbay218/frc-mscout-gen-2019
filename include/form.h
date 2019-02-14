#ifndef FORM_H
#define FORM_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nana/gui/wvl.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/label.hpp>
#include "data_gen.h"
#include "file_writer.h"

class form {
    public:
        form();
        virtual ~form();

    protected:
    private:
        data_gen dg;
        file_writer fw;
        std::string initPath;
        std::string matchNum;
        std::string rangeStart;
        std::string rangeEnd;

        std::string writeData(std::vector<std::string> input);
};

#endif // FORM_H
