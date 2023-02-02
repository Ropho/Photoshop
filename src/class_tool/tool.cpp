#include "tool.hpp"


void get_all_tools (vector <Tool *> &tools) {

    Tool *pencil = new Pencil (TL::TOOLS::PENCIL);
    tools.push_back (pencil);


}
