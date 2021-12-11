#include "Encyclopedia.hpp"

Encyclopedia::Encyclopedia() : Book()
{
    int i;
    this->numberOfAuthors = 0;

    for (i = 0; i < MAX_AUTHORS; i++)
    {
        this->authors[i] = NULL;
    }

    this->text = new char[strlen("") + 1];
    strcpy(this->text, "");
}

Encyclopedia::Encyclopedia(int numberOfPages, char *title, int numberOfAuthors, Author *authors[MAX_AUTHORS], char *text)
    : Book(numberOfPages, title),
      numberOfAuthors(numberOfAuthors)
{
    int i, size;

    if (numberOfAuthors > 5)
    {
        size = 5;
    }
    else
    {
        size = numberOfAuthors;
    }

    for (i = 0; i < size; i++)
    {
        this->authors[i] = authors[i];
    }

    this->text = new char[strlen(text) + 1];
    strcpy(this->text, text);
}

Encyclopedia::Encyclopedia(const Encyclopedia &encyclopedia)
    : Book(encyclopedia)
{
    int i;

    this->numberOfAuthors = encyclopedia.numberOfAuthors;

    for (i = 0; i < encyclopedia.numberOfAuthors; i++)
    {
        this->authors[i] = encyclopedia.authors[i];
    }

    this->text = new char[strlen(encyclopedia.text) + 1];
    strcpy(this->text, encyclopedia.text);

    logCall("Encyclopedia copy constructor");
}

Encyclopedia::~Encyclopedia()
{
    if ((this->text, "") != 0)
    {
        delete[] text;
    }

    logCall("Encyclopedia destructor");
}

Encyclopedia &Encyclopedia::operator=(const Encyclopedia &encyclopedia)
{
    if (this == &encyclopedia)
    {
        logCall("Encyclopedia copy assignment operator - self assignment");
        return *this;
    }

    Book::operator=(encyclopedia);

    int i;

    this->numberOfAuthors = encyclopedia.numberOfAuthors;

    for (i = 0; i < encyclopedia.numberOfAuthors; i++)
    {
        this->authors[i] = encyclopedia.authors[i];
    }

    char *oldText = this->text;
    this->text = new char[strlen(encyclopedia.text) + 1];
    strcpy(this->text, encyclopedia.text);
    delete[] oldText;

    logCall("Encyclopedia copy assignment operator");

    return *this;
}

void Encyclopedia::printDetails()
{
    Book::printDetails();

    int i;

    if (this->numberOfAuthors != 0 && strcmp(this->text, "") != 0)
    {
        for (i = 0; i < this->numberOfAuthors; i++)
        {
            cout << "Author " << i << ": " << (this->authors[i])->getAuthorName() << endl;
        }

        cout << "Text: " << this->text << endl;
    }
    else
    {
        cout << "This novel has no other details to show" << endl;
    }
}

void Encyclopedia::writeInCollaboration(char *additionalText)
{
    char *oldText = this->text;
    this->text = new char[strlen(this->text) + strlen(additionalText) + 1];
    strcpy(this->text, oldText);
    strcat(this->text, additionalText);
    delete[] oldText;
}