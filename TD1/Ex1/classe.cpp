# include <iostream>
# include "classe.h"


My_class::My_class() {
    variable = "default";
}

My_class::My_class(string var) {
    variable = var;
}

void My_class::print_my_element() {
    cout << endl << variable;
}
