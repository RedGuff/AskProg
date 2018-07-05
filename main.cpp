#include <fstream>
#include <iostream>
using namespace std;
/*
string inputText(string ask) // Pas certain que ce soit utile.
{
    string text="";
    cout << ask << endl;
        cin >> text;
    return text;
}
*/
int main()
{
    cout << "I will help You to start your program!" << endl;
    string name = "";
    string preprog = "#include <iostream> \n using namespace std; \n int main() \n \{ \n";
    string postprog = " \n return 0; \n }";
    bool random = false;
    do
    {
        cout << "What is the name of your program?" << endl;
        cout << "I will add .cpp at the end, if needed." << endl;
        // cout << "Do NOT use _temp_ in the name, please!" << endl;
        // cout << "Do NOT use _temp1_ in the name, please!" << endl;
        // cout << "Do NOT use _temp2_ in the name, please!" << endl;
        // cout << "Do NOT use _temp3_ in the name, please!" << endl;
        cin >> name;
    }
    while (name == "");
    if (name.size() < 4) // If not .cpp ?
    {
        name = name + ".cpp";
    }
    if (name.substr(name.size() - 4) != ".cpp") // If not .cpp ?
    {
        name = name + ".cpp";
    }

    clog << name << endl;
    ofstream myfile;
    myfile.open (name.c_str(),ios::app);
    if (!myfile.is_open()) // Error file.
    {
        cerr << "Unable to open file!";
        return 2; // Error file.
    }
    else // File ok.
    {
        myfile << preprog;
        string choice = "0";
        do
        {
         // input and " " makes problems.

            cout << "What do You want?" << endl;
            cout <<"1: Display text."<< endl;

            cout <<"2: Create value."<< endl;
            /* cout <<"2: Input value (TO DO)"<< endl;
             cout <<"3: Display value (TO DO)"<< endl;
             cout <<"4: Calculate value (TO DO)"<< endl;
             cout <<"5: Choice (TO DO)"<< endl;
             cout <<"6: Random value (TO DO)"<< endl;
             cout <<"7: Fichier (TO DO)"<< endl;
             cout <<"8: Fichier (TO DO)"<< endl;
            poser un label, un goto, aller au label, code direct, remarque.

             cout <<"9: Sauver (TO DO)"<< endl;
             */
            cout <<"0: Quit"<< endl;
            cin >> choice;
            // If, instead of switch, to have letters.
            if (choice == "1")
            {


                cout << "Your text?" << endl;
                string text = "";
                cin >> text; // Espace => problem.
                myfile << "cout << \""<< text << "\" << endl; \n";
            }
            else if (choice == "2")
            {
                 cout << "The type of your variable?" << endl;
                string type = "";
cin >> type;

                cout << "The name of your variable?" << endl;
                string nameVar = "";
                cin >> nameVar;

                cout << "The initial value of your variable?" << endl;
                string valueVariable = ""; // No problem if number coded as string.
                cin >> valueVariable;
                myfile << type << " " << nameVar << " = " << valueVariable << "; \n"<< endl;
            }


        }
        while ( choice != "0");
    }
    myfile << postprog;

    myfile.close();
    return 0;
}
