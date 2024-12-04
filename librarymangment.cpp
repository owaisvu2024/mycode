#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class temp
{
    string bookname, bookcode, author, searchcode;
    fstream file;

public:
    void banner();
    void addbook();
    void showbook();
    void extract();

} obj;
int main()
{

    char choice;
    obj.banner();
    cout << "1 ADD BOOK " << endl;
    cout << "2 SHOWBOOK " << endl;
    cout << "3 EXTRACT " << endl;

    cout << "ENTER THE CHOICE " << endl;

    cin >> choice;
    switch (choice)
    {
    case '1':
        obj.addbook();
        break;

    case '2':
        obj.showbook();
        break;
    case '3':
        obj.extract();
        break;

    default:
        cout << " invalid selection " << endl;
        break;
    }

    return 0;
}
void temp::banner()
{
    cout << "! ----------------------------------------------------------------- !" << endl;
    cout << "! --------------------THE HOUSE OF BOOKS LIBRARYS------------ !" << endl;
    cout << "! ----------------------------------------------------------------- !" << endl;
}
void temp::addbook()
{
    system("cls");
    obj.banner();
    cin.ignore();
    cout << "ENTER THE ADD BOOK :: ";
    getline(cin, bookname);
    cout << "ENTER THE  BOOK CODE :: ";
    getline(cin, bookcode);
    cout << "ENTER THE ADD AUTHOR NAME :: ";
    getline(cin, author);
    char save;
    cout << "SAVE (Y/N)" << endl;
    cin >> save;

    if (save == 'y')
    {
        file.open("library.txt", ios::out | ios::app);
        file << bookname << "*" << bookcode << "*" << author << endl;
        file.close();
    }
    char more;
    cout << "ADD MORE BOOKS " << endl;
    cin >> more;
    if (more == 'y')
    {
        addbook();
    }

    else
    {
        cout << " !-----YOUR BOOKS IS ADDED SUCCESSFULLY------! " << endl;
    }
}
void temp::showbook()
{
    system("cls");
    void banner();
    file.open("library.txt", ios::in);
    if (!file)
    {
        cout << "NOT FILE AVAILABLE HERE " << endl;
        return;
    }

    bool found = false;
    cout << " CODE\tBOOK NAME\tAUTHOR NAME \n ";
    while (getline(file, bookname, '*') && getline(file, bookcode, '*') && getline(file, author))
    {
        cout << bookcode << "\t" << bookname << "\t" << author << "\n";
        found = true;
    }
    if (!found)
    {
        cout << "FILE ERRORS \n";
    }

    file.close();
}
void temp::extract()
{
    system("cls");
    obj.banner();
    cin.ignore();
    cout << "ENTER THE BOOKCODE " << endl;
    getline(cin, searchcode);
    file.open("library.txt", ios::in);
    if (!file)
    {
        cout << "NO INPUT FILE AVAILABLE HERE " << endl;
        return;
    }

    bool found = false;
    cout << "CODE\tBOOK NAME\tAUYHOR NAME\n";
    while (getline(file, bookname, '*') && getline(file, bookcode, '*') && getline(file, author))
    {
        if (bookcode == searchcode)
        {
            cout << bookcode << "\t" << bookname << "\t\t" << author << endl;
        }
        found = true;
    }
    char exist;
    cout << "exist (y/n)" << endl;
    cin >> exist;
    if (exist == 'y')
    {
        addbook();
    }

    if (!found)
    {
        cout << "INVALID SELECTION " << endl;
    }
    file.close();
}