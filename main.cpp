#include "src/Person/src/Author.hpp"

#include <iostream>
using namespace std;

int main()
{
    char *numeAutor;
    numeAutor = new char[20];
    strcpy(numeAutor, "Ioana Pirvulescu");
    Author author1(numeAutor, 61, 30);
    author1.printPresentation();

    return 0;
}