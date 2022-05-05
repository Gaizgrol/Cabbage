#include <iostream>
#include "main.hh"

int main( int argc, char** argv )
{
    using namespace std;

    Teste t("Oi, Cabbage!");

    cout << t.fetch() << '\n';

    return 0;
}