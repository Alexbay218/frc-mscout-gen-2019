#include "form.h"

form::form() {
    initPath = fs::current_path().string() + "\\data";
    matchNum = "100";

    file_writer fw;
    data_gen dg;

    nana::form fm(nana::rectangle(20,20,500,200));
    fm.caption("FRC MScout Gen 2019");

    nana::label lb_pathstring(fm, nana::rectangle(10,10,70,25));
    lb_pathstring.caption("Folder Path:");
    nana::textbox tb_pathstring(fm, nana::rectangle(80,10,410,25));
    tb_pathstring.caption(initPath);

    nana::label lb_matchnum(fm, nana::rectangle(10,50,130,25));
    lb_matchnum.caption("Number of Matches:");
    nana::textbox tb_matchnum(fm, nana::rectangle(125,50,365,25));
    tb_matchnum.caption(matchNum);

    nana::label lb_rangestart(fm, nana::rectangle(10,90,130,25));
    lb_rangestart.caption("Team Range Start:");
    nana::textbox tb_rangestart(fm, nana::rectangle(125,90,365,25));
    tb_rangestart.caption(rangeStart);

    nana::label lb_rangeend(fm, nana::rectangle(10,120,130,25));
    lb_rangeend.caption("Team Range End:");
    nana::textbox tb_rangeend(fm, nana::rectangle(125,120,365,25));
    tb_rangeend.caption(rangeEnd);

    nana::button bt_start(fm, nana::rectangle(10,150,480,50));
    bt_start.caption("Start Generating");
    bt_start.events().click([&](){
        for(int i = 0;i < tb_matchnum.to_int();i++) {
            fw.writeFile(dg.gen_data(tb_rangestart.to_int(), tb_rangeend.to_int()), initPath);
        }
    });

    fm.show();
    nana::exec();
}

form::~form() {
    //dtor
}
