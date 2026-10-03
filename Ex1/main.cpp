# include <iostream>
# include "printer.h"
# include "classe.h"


using namespace std;

void printer(string Message){
    cout << Message;
}

int main(){

    // EX 1 Q 1et2et3

    string Mess = "Hello World!";
    printer(Mess);

    // EX 1 Q 4
    My_class obj1;
    My_class obj2("Hadil");

    obj1.print_my_element();
    obj2.print_my_element();

    return 0 ;
}

