#include <fstream>
//#include <boost/algorithm/string.hpp>
#include<cmath>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

string tolow(string a) // https://stackoverflow.com/questions/11635/case-insensitive-string-comparison-in-c
{
    for(unsigned int i=0; i<a.length(); i++)
    {
        a[i]=tolower(a[i]);
    }
    return a;
}

string toupp(string a) // https://stackoverflow.com/questions/11635/case-insensitive-string-comparison-in-c
{
    for(unsigned int i=0; i<a.length(); i++)
    {
        a[i]=toupper(a[i]);
    }
    return a;
}


int main()
{
    cout << "I will help You to start your program!" << endl << endl;
    // TODO : dessin !

    string name = "";
    string preprog1 = "#include <iostream> \n using namespace std; \n ";
    string preprog2 = " \n int main() \n \{ \n";
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
        getline(cin,name); // Accepte l'espace ! DANGER.
    }
    while (name == "");
    if (name.size() < 4) // If not .cpp ? // I need to check the size of the string, in order to be able to do the next test.
    {
        name = name + ".cpp";
    }
    if (name.substr(name.size() - 4) != ".cpp") // If not .cpp ?
    {
        name = name + ".cpp";
    }

    clog << name << endl;
    ofstream myfile;
    myfile.open (name.c_str(),ios::app); // If exists: not now.
    if (!myfile.is_open()) // Error file.
    {
        cerr << "Unable to open file!";
        return 2; // Error file.
    }
    else // File ok.
    {
        myfile << preprog1;
        myfile << preprog2;
        string choice = "0";
        do
        {

            cout << "What do You want?" << endl;
            cout <<"1: Display line of text."<< endl;

            cout <<"2: Create value."<< endl;
            cout <<"C: Line of raw C++ code."<< endl;
            /* cout <<"2: Input value (TO DO)"<< endl;
             cout <<"3: Display value (TO DO)"<< endl;
             cout <<"4: Calculate value (TO DO)"<< endl;
             cout <<"5: Choice (TO DO)"<< endl;
             cout <<"6: Random value (TO DO)"<< endl;
             cout <<"7: Fichier (TO DO)"<< endl;
             cout <<"8: Fichier (TO DO)"<< endl;
            Label,
            Goto,
            => label,
            rem.

             cout <<"9: Sauver (TO DO)"<< endl;
             */
            cout <<"0: Quit"<< endl;
            getline(cin,choice);
            // If, instead of switch, to have letters.
            if (choice == "1")
            {
                cout << "Your text?" << endl;
                string text = "";
                getline(cin,text);
                myfile << "cout << \""<< text << "\" << endl; \n";
            }
            else if (choice == "2")
            {
                cout << "The type of your variable?" << endl;
                string type = "";
                getline(cin,type);
                type=tolow(type);
                cout << "The name of your variable?" << endl;
                string nameVar = "";
                getline(cin,nameVar);
                cout << "The initial value of your variable?" << endl;
                string valueVariable = ""; // No problem if number coded as string.
                getline(cin,valueVariable);

                if ((type) != "string")
                {
                    myfile << type << " " << nameVar << " = \"" << valueVariable << "\"; \n"<< endl;

                }
                else
                {
                    myfile << type << " " << nameVar << " = " << valueVariable << "; \n"<< endl;
                }
            }
            else   if ((choice == "C") or (choice == "c"))
            {
                cout << "Your code?" << endl;
                string text = "";
                getline(cin,text);
                myfile <<  text <<  "\n";
            }
        }
        while ( choice != "0");
    }
    myfile << postprog;
    myfile.close();
    return 0;
}
