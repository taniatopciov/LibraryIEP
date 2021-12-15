#include "src/Person/src/Author.hpp"
#include "src/Person/src/Reader.hpp"
#include "src/Book/src/Book.hpp"
#include "src/Book/src/Novel.hpp"
#include "src/Book/src/Encyclopedia.hpp"
#include "src/Book/src/Textbook.hpp"
#include "src/Library/src/Library.hpp"
#include "src/Lock/src/Lock.hpp"

#include <iostream>
#include <mutex>
#include <memory>
#include <thread>

using namespace std;

mutex m;

void example_unique_ptr()
{
    char title1[25] = "Zuleiha deschide ochii";
    char literary_movement1[12] = "modernism";
    unique_ptr<Author> author1 = make_unique<Author>("Author 1", 45, 3);

    Novel *pNovel = new Novel(400, title1, author1.get(), literary_movement1);

    char name2[20] = "Tania";
    Reader tania(name2, 22);

    char name3[20] = "Ana";
    Reader ana(name3, 23);
    Reader *pReader = &ana;

    // tania.readBookAndShare(pNovel, pReader);

    tania.readBookAndTransfer(pNovel, pReader);
}

void example1_shared_ptr()
{
    char title1[25] = "Enciclopedia Britanica";
    char references1[200] = "History of Encyclopædia Britannica and Britannica Online. Encyclopædia Britannica, Inc. Archived from the original on 20 October 2006. Retrieved 31 May 2019.";
    shared_ptr<Encyclopedia> pEnc1 = make_shared<Encyclopedia>(1200, title1, references1);

    Author *a1 = new Author("Author1", 45, 3);

    a1->writeInCollaboration(pEnc1.get());
    cout << pEnc1.get()->getText() << endl;
    cout << pEnc1.use_count() << endl;

    Author *a2 = new Author("Author2", 28, 7);

    {
        shared_ptr<Encyclopedia> pEnc2(pEnc1);

        a2->writeInCollaboration(pEnc2.get());
        cout << pEnc2.get()->getText() << endl;
        cout << pEnc2.use_count() << endl;
    }

    cout << pEnc1.use_count() << endl;

    Author *a3 = new Author("Author3", 44, 21);

    shared_ptr<Encyclopedia> pEnc3(pEnc1);

    a3->writeInCollaboration(pEnc3.get());
    cout << pEnc3.get()->getText() << endl;
    cout << pEnc3.use_count() << endl;

    pEnc1.reset();
    cout << pEnc3.use_count() << endl;
}

void writing_phase1(shared_ptr<Author> a, shared_ptr<Encyclopedia> e)
{
    cout << "Author1 use count: " << a.use_count() << endl;

    cout << "Encyclopedia use count: " << e.use_count() << endl;

    a->writeInCollaboration(e.get());

    cout << e->getText() << endl;
}

void writing_phase2(shared_ptr<Author> a, shared_ptr<Author> b, shared_ptr<Encyclopedia> e)
{
    cout << "Author1 use count: " << a.use_count() << endl;

    cout << "Author2 use count: " << b.use_count() << endl;

    shared_ptr<Encyclopedia> enc(e);
    cout << "Encyclopedia use count: " << enc.use_count() << endl;

    a->writeInCollaboration(enc.get());
    cout << enc->getText() << endl;

    b->writeInCollaboration(enc.get());
    cout << enc->getText() << endl;
}

void example2_shared_ptr()
{
    char title1[25] = "Enciclopedia Britanica";
    char references1[200] = "History of Encyclopædia Britannica and Britannica Online. Encyclopædia Britannica, Inc. Archived from the original on 20 October 2006. Retrieved 31 May 2019.";
    shared_ptr<Encyclopedia> pEnc = make_shared<Encyclopedia>(1200, title1, references1);
    cout << "Encyclopedia use count: " << pEnc.use_count() << endl;

    shared_ptr<Author> a1 = make_shared<Author>("Author 1", 45, 3);
    cout << "Author1 use count: " << a1.use_count() << endl;

    shared_ptr<Author> a2 = make_shared<Author>("Author 2", 28, 7);
    cout << "Author2 use count: " << a2.use_count() << endl;

    writing_phase1(a1, pEnc);

    writing_phase2(a1, a2, pEnc);
}

void writeInTextbook(Author *author, Textbook *tb)
{
    Lock lock1(&m);

    author->writeInCollaboration(tb);
    cout << "Updated textbook content: " << tb->getText() << endl;
}

void example_mutex()
{
    char title1[15] = "Effective C++";
    char subject1[15] = "Programming";
    unique_ptr<Textbook> pTB = make_unique<Textbook>(180, title1, subject1);

    unique_ptr<Author> author1 = make_unique<Author>("Author 1", 45, 3);

    unique_ptr<Author> author2 = make_unique<Author>("Author 2", 28, 7);

    unique_ptr<Author> author3 = make_unique<Author>("Author 3", 44, 21);

    cout << "Initial textbook content: " << pTB.get()->getText() << endl;

    thread thread_author1(writeInTextbook, author1.get(), pTB.get());

    thread thread_author2(writeInTextbook, author2.get(), pTB.get());

    thread thread_author3(writeInTextbook, author3.get(), pTB.get());

    thread_author1.join();

    thread_author2.join();

    thread_author3.join();
}

int main()
{
    cout << "\nEXAMPLE - UNIQUE_PTR\n"
         << endl;
    example_unique_ptr();

    cout << "\n\nEXAMPLE - SHARED_PTR\n"
         << endl;
    example1_shared_ptr();

    cout << "\n\nSECOND EXAMPLE - SHARED_PTR\n"
         << endl;
    example2_shared_ptr();

    cout << "\n\nEXAMPLE - MUTEX\n"
         << endl;
    example_mutex();

    return 0;
}