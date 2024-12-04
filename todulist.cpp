#include <iostream>
#include <fstream>
using namespace std;
struct todulist
{
    int id;
    string task;
};
int id = 0;
void banner();
void addtask();
void showtask();
int searchtask();
void deletetask();
int getlastid();
// void updatetask();
int main()
{
    id = getlastid();
    system("cls");
    banner();
    while (true)
    {
        cout << "1 ADD TASK " << endl;
        cout << "2 SHOW TASK " << endl;
        cout << "3 SEARCH TASK " << endl;
        cout << "4 DELTE TASK " << endl;
        cout << "5 UPDATE TASK " << endl;
        int choice;
        cout << " ENTER THE CHOICE  " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            addtask();
            break;
        case 2:
            showtask();
            break;
        case 3:
            searchtask();
            break;

        case 4:
            deletetask();
            break;

        default:
            cout << " INVALID SELECTION " << endl;
            break;
        }

        return 0;
    }
}

void banner()
{
    cout << "-----------------------------------------------------" << endl;
    cout << "--------------TODO LIST-------------------------------" << endl;
    cout << "-----------------------------------------------------" << endl;
}
void addtask()
{
    system("cls");
    banner();

    todulist tudo;
    cout << "ENTER THE TASK " << endl;
    cin.ignore();
    getline(cin, tudo.task);
    char save;
    cout << "SAVE ! (Y/N)" << endl;
    cin >> save;
    if (save == 'y')
    {
        id++;
        ofstream file;
        file.open("tudo.txt", ios::app);
        file << id << " :" << tudo.task << endl;
        file.close();
    }

    char more;
    cout << "ADD MORE TASK " << endl;
    cin >> more;
    if (more == 'y')
    {
        addtask();
    }
    else
    {
        system("cls");
        cout << " ADDED SUCCESSFULLY " << endl;
        return;
    }

    system("cls");
}
void showtask()
{
    system("cls");
    banner();
    todulist tudo;
    ifstream file;
    file.open("tudo.txt");
    cout << " TASK " << endl;
    while (file >> tudo.id)
    {

        file.ignore();

        getline(file, tudo.task);
        if (tudo.task != "")
        {
            cout << tudo.id << ": " << tudo.task << endl;
        }

        else
        {
            cout << "EMPTY ! " << endl;
        }
    }
}

int searchtask()
{
    system("cls");
    banner();
    int searchid;
    cout << "ENTER THE SEARCH ID " << endl;
    cin >> searchid;
    todulist tudo;
    ifstream file;
    file.open("tudo.txt");

    while (!file.eof())
    {
        file >> tudo.id;
        file.ignore();
        getline(file, tudo.task);
        if (tudo.id == searchid)
        {
            system("cls");
            cout << tudo.id << ": " << tudo.task << endl;

            return tudo.id;
        }
    }

    system("cls");
    cout << "NO ID AVAILABLE " << endl;

    file.close();
}

void deletetask()
{
    system("cls");
    int delid = searchtask();
    if (delid != 0)
    {
        char del;
        cout << "delete task (y/n)" << endl;
        cin >> del;
        if (del == 'y')
        {
            todulist tudo;
            ofstream tempfile;
            tempfile.open("tempfile.txt");
            ifstream file;
            file.open("tudo.txt");
            while (file >> tudo.id)
            {
                file.ignore();
                getline(file, tudo.task);

                if (tudo.id != delid)
                {
                    tempfile << tudo.id << " : " << tudo.task << endl;
                }
            }
            file.close();
            tempfile.close();
            remove("tudo.txt");
            rename("tempfile.txt", "tudo.txt");
            system("cls");
            cout << " DELETE SUCCESSFULLY " << endl;
        }
        else
        {
            cout << "DELETE NOT SUCCESSFULLY" << endl;
        }
    }
}
int getlastid()
{
    int lastid = 0;
    todulist tudo;
    ifstream file;
    file.open("tudo.txt");
    while (file >> tudo.id)
    {
        file.ignore();
        getline(file, tudo.task);
        lastid = tudo.id;
    }

    file.close();
    return lastid;
}