#include <iostream>

using namespace std;

namespace X{
    int var;
    void print();
}

namespace Y{
    int var;
    void print();
}

namespace Z{
    int var;
    void print();
}


int main(){

    X::var = 7;
    X::print(); // print X's var
    using namespace Y;
    var = 9;
    print();    // print Y's var
    {
    using Z::var;
    using Z::print;
    var = 11;
    print(); // print Z's var
    }
    print();    // print Y's var again
    X::print(); // print X's var again

    return 0;
}

void X::print(){
    cout << var << '\n';
}

void Y::print(){
    cout << var << '\n';
}

void Z::print(){
    cout << var << '\n';
}