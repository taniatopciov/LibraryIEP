#include "src/Person/src/Author.hpp"
#include "src/Person/src/Reader.hpp"
#include "src/Book/src/Book.hpp"
#include "src/Book/src/Novel.hpp"
#include "src/Book/src/Encyclopedia.hpp"
#include "src/Library/src/Library.hpp"
#include "src/Lock/src/Lock.hpp"

#include <iostream>
#include <mutex>
#include <memory>

using namespace std;

void example_use_of_unique_ptr()
{
    char name1[20] = "Guzel Iahina";
    Author guzel(name1, 45, 3);

    Author *a1;
    a1 = &guzel;

    char title1[25] = "Zuleiha deschide ochii";
    char literary_movement1[12] = "modernism";

    Novel *pNovel = new Novel(400, title1, a1, literary_movement1);

    char name2[20] = "Tania";
    Reader tania(name2, 22);

    char name3[20] = "Ana";
    Reader ana(name3, 23);
    Reader *pReader = &ana;

    // tania.readBookAndShare(pNovel, pReader);

    tania.readBookAndTransfer(pNovel, pReader);
}

void example_use_of_shared_ptr()
{
    char title1[25] = "Enciclopedia Britanica";
    char text1[2] = "";
    shared_ptr<Encyclopedia> pEnc1 = make_shared<Encyclopedia>(1200, title1, text1);

    char name1[20] = "Author 1";
    Author author1(name1, 45, 3);
    Author *a1;
    a1 = &author1;

    a1->writeInCollaboration(pEnc1.get());
    cout << pEnc1.get()->getText() << endl;
    cout << pEnc1.use_count() << endl;

    char name2[20] = "Author 2";
    Author author2(name2, 28, 7);
    Author *a2;
    a2 = &author2;

    {
        shared_ptr<Encyclopedia> pEnc2(pEnc1);

        a2->writeInCollaboration(pEnc2.get());
        cout << pEnc2.get()->getText() << endl;
        cout << pEnc2.use_count() << endl;
    }

    cout << pEnc1.use_count() << endl;

    char name3[20] = "Author 3";
    Author author3(name3, 44, 21);
    Author *a3;
    a3 = &author3;

    shared_ptr<Encyclopedia> pEnc3(pEnc1);

    a3->writeInCollaboration(pEnc3.get());
    cout << pEnc3.get()->getText() << endl;
    cout << pEnc3.use_count() << endl;

    pEnc1.reset();
    cout << pEnc3.use_count() << endl;
}

void example_mutex()
{
    char title1[25] = "Enciclopedia Britanica";
    char text1[2] = "";
    unique_ptr<Encyclopedia> pEnc = make_unique<Encyclopedia>(1200, title1, text1);

    cout << "Initial encyclopedia content: " << pEnc.get()->getText() << endl;

    char name1[20] = "Author 1";
    Author author1(name1, 45, 3);
    Author *a1;
    a1 = &author1;

    char name2[20] = "Author 2";
    Author author2(name2, 28, 7);
    Author *a2;
    a2 = &author2;

    char name3[20] = "Author 3";
    Author author3(name3, 44, 21);
    Author *a3;
    a3 = &author3;

    mutex m;

    {
        Lock lock1(&m);

        a1->writeInCollaboration(pEnc.get());
        cout << "Updated encyclopedia content: " << pEnc.get()->getText() << endl;
    }

    {
        Lock lock2(&m);

        a2->writeInCollaboration(pEnc.get());
        cout << "Updated encyclopedia content: " << pEnc.get()->getText() << endl;
    }

    {
        Lock lock3(&m);

        a3->writeInCollaboration(pEnc.get());
        cout << "Updated encyclopedia content: " << pEnc.get()->getText() << endl;
    }
}

int main()
{
    cout << "USAGE EXAMPLE FOR UNIQUE_PTR" << endl;
    example_use_of_unique_ptr();

    cout << "USAGE EXAMPLE FOR SHARED_PTR" << endl;
    example_use_of_shared_ptr();

    cout << "EXAMPLE MUTEX" << endl;
    example_mutex();

    return 0;
}