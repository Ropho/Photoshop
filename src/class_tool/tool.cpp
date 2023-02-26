#include "tool.hpp"


void get_all_tools (vector <Tool *> &tools, Widget *parent) {

    Tool *pencil = new Pencil (GLUT::TOOLS::PENCIL, parent);
    tools.push_back (pencil);

}
