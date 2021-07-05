#include<iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#include "AvlTreeExt.h"
#include "data.h"
//#include "index.h"
//#include "node.h"
#include "invertedIndex.h"

int main() {

	int choice = 1;
	string filename;

	while (choice !=0){
        cout << "---------------------------------------------------------" << endl;
        cout << "Choose one of the following options:" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl << "LEARN:" << endl;
	    cout << "1. Learn index dictionary from a file" << endl;//invertedIndex.h
        cout << "2. Learn index dictionary from multiple files" << endl;//invertedIndex.h
        cout << "3. Load dictionary from a file" << endl; //invertedIndex.h
        cout << endl << "OUTPUT:" << endl;
        cout << "4. Print the index dictionary" << endl;//invertedIndex.h
        cout << "5. Print AVL tree of the dictionary" << endl;//AVL_ADT.h
        cout << "6. Output dictionary to text file" << endl;//invertedIndex.h
        cout << endl << "DELETE" << endl;
        cout << "7. Delete low frequency words from dictionary" << endl << endl;//AvlTreeExt.h
        cout << "0. Quit" << endl;
        cout << "---------------------------------------------------------" << endl;

        cin >> choice;

        switch (choice) {
            default:
                cout << "No valid option was chosen. Exiting program.";
                break;
            case 1:
                cout << "Enter a text file to read (article.txt): ";
                cin >> filename;
                learnOneFile(filename);
                break;
            case 2: learnMulFiles();
                break;
            case 3:
                learnFromFile();
                break;
            case 4: printDic();
                break;
            case 5: printAVL();
                break;
            case 6:
                cout << "Enter a text file to output to (invertedIndex.txt): ";
                cin >> filename;
                outToFile(filename);
                break;
            case 7:deleteNodes();
                break;
            case 0: return 0;
        }

    }
}
