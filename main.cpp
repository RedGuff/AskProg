#include <fstream>
#include <cmath>
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
    cout << "I will help You to start your program in C++, a recommended language!" << endl;
    cout << "Prepare your algorithm on a paper, and just answer the questions!" << endl << endl;
    // TODO : dessin !

    string name = "";
    string preprog1 = "#include <iostream> \n using namespace std; \n ";
    string preprog2 = " \n int main() \n \{ \n";
    string postprog = " \n return 0; \n }";
    bool random = false;
    bool displayDisplay = false;
    do
    {
        cout << "What is the name of your program?" << endl;
        cout << "I will add .cpp at the end, if needed." << endl;
        // cout << "Do NOT use _temp_ in the name, please!" << endl;
        // cout << "Do NOT use _temp1_ in the name, please!" << endl;
        // cout << "Do NOT use _temp2_ in the name, please!" << endl;
        // cout << "Do NOT use _temp3_ in the name, please!" << endl;
        getline(cin, name); // Not cin >> name >> endl; to accept space(s).
    }
    while (name == "");
    if (name.size() < 4) // If not .cpp ? // I need to check the size of the string, in order to be able to do the next test.
    {
        name = name + ".cpp";
    }
    if (name.substr(name.size() - 4) != ".cpp") // If not .cpp ? The string is long enough to count to 5.
    {
        name = name + ".cpp";
    }

//   clog << name << endl; // Test ok.
//   clog <<  ( name.substr(0, name.size() - 4)) << endl; // Test ok.
    ofstream myfile;
    myfile.open (name.c_str(),ios::app); // If exists: not tested now.
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
            // D, no D : display.
            cout <<"1: Display line of text (usual)."<< endl;
            cout <<"7: Display control line of text."<< endl;
            cout <<"8: Display error line of text."<< endl;
            cout <<"2: Create value."<< endl;
            cout <<"C: Line of raw C++ code."<< endl;
            cout <<"3: Line of comment."<< endl;

            cout <<"4: Display value (usual)."<< endl;
            cout <<"5: Display control value."<< endl;
            cout <<"6: Display error value."<< endl;
            cout <<"G: Add a goto. (It's dangerous!)"<< endl;
            cout <<"L: Add label. (For the goto of to go to it!)"<< endl;
            /* cout <<"2: Input value (TO DO)"<< endl; // Autodetection of the nature of the string! Ask it do not exists!
             cout <<"4: Calculate value (TO DO)"<< endl; // ?
             cout <<"5: Choice (TO DO)"<< endl;
             cout <<"6: Random value (TO DO)"<< endl;
             cout <<"7: Fichier (TO DO)"<< endl;
             cout <<"8: Fichier (TO DO)"<< endl;
             cout <<"F: Functions (TO DO)"<< endl;


            Goto,
            => label,


             cout <<"9: Sauver (TO DO)"<< endl;
             */
            cout <<"0: Quit"<< endl;
            getline(cin, choice);
            // If, instead of switch, to have letters.
            if (choice == "1")
            {
                cout << "Your text?" << endl;
                string text = "";
                getline(cin, text);
                myfile << "cout << \""<< text << "\" << endl; \n";
            }
            else if (choice == "7")
            {
                cout << "Your control text?" << endl;
                string text = "";
                getline(cin, text);
                myfile << "clog << \""<< text << "\" << endl; \n";
            }
            else if ((choice == "G") or (choice == "g"))
            {
                cout << "The name of label to \"go to\"?" << endl;
                string text = "";
                getline(cin, text);
                myfile << "goto " << text << "; // Sorry! \n";
            }
                else if ((choice == "L") or (choice == "l"))
            {
                cout << "The name of your label?" << endl;
                string text = "";
                getline(cin, text);
                myfile << text << ": \n";
            }
            else if (choice == "8")
            {
                cout << "Your error text?" << endl;
                string text = "";
                getline(cin, text);
                myfile << "cerr << \""<< text << "\" << endl; \n";
            }
            else if (choice == "2")
            {
                cout << "The type of your variable?" << endl;
                string type = "";
                getline(cin, type);
                type=tolow(type);
                cout << "The name of your variable?" << endl;
                string nameVar = "";
                getline(cin, nameVar);
                cout << "The initial value of your variable?" << endl;
                string valueVariable = ""; // No problem if number coded as string.
                getline(cin, valueVariable);

                if ((type) == "string")
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
                getline(cin, text);
                myfile << text <<  "\n";
            }
            else   if ((choice == "D") or (choice == "d"))
            {
                displayDisplay = !displayDisplay;
            }
            else if (choice == "3")
            {
                cout << "Your line of comment?" << endl;
                string text = "";
                getline(cin, text);
                myfile << "\\\\ " << text <<  "\n";
            }
        }
        while ( choice != "0");
    }
    myfile << postprog;
    myfile.close();
    cout << "Ok." << endl;
    cout << "make " << name.substr(0, name.size() - 4) <<  endl;
    cout << "./" << name.substr(0, name.size() - 4) << endl;

    return 0;
}
