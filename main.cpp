#include "src/Person/src/Author.hpp"
#include "src/Book/src/Book.hpp"
#include "src/Book/src/Novel.hpp"
#include "src/Library/src/Library.hpp"

#include <iostream>
using namespace std;

int main()
{
    char name1[20] = "Gustave Flaubert";
    Author author1(name1, 59, 28);

    cout << endl;

    char name2[20] = "Émile Zola";
    Author author2(name2, 62, 43);

    cout << endl;

    char title1[15] = "Madame Bovary";
    char literary_movement1[12] = "Realism";

    Author *a1;
    a1 = &author1;

    Novel novel1(400, title1, a1, literary_movement1);

    novel1.printDetails();

    Novel novel2;

    cout << endl;

    novel2.printDetails();

    Novel novel3;

    cout << endl;

    novel3.printDetails();

    cout << endl;

    // item 10 - Have assignment operators return a reference to *this
    novel3 = novel2 = novel1;

    cout << endl;

    novel2.printDetails();

    cout << endl;

    novel3.printDetails();

    cout << endl;
    // item 11 - Handle assignment to self in operator=
    novel2 = novel2;

    cout << endl;

    Author *a2;
    a2 = &author2;

    char title2[10] = "Germinal";
    char literary_movement2[20] = "Naturalism";

    Novel novel4(350, title2, a2, literary_movement2);

    novel4.printDetails();

    cout << endl;

    // item 12 - Copy all parts of an object
    novel1 = novel4;

    cout << endl;

    novel1.printDetails();

    cout << endl;

    return 0;
}