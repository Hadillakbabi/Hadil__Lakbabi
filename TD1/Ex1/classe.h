#ifndef CLASSE_H
#define CLASSE_H

#include <string>
using namespace std;

class My_class {
    
private:
    string variable;

public:

    My_class();
    My_class(string var);
    void print_my_element();
};

#endif