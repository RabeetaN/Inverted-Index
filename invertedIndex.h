//
// Created by Rabeeta Nasir on 21/05/2021.
//

#ifndef AVL_TREE_INVERTEDINDEX_H
#define AVL_TREE_INVERTEDINDEX_H

#endif //AVL_TREE_INVERTEDINDEX_H

#include<iomanip>
#include <algorithm>
#include <string>

using namespace std;

AvlTreeExt<DATA, string> tree;

void print(DATA ss) {
    cout << setw(15) << ss.key <<  " | " << setw(3) << ss.info.freq << " | " << setw(10) << ss.info.freq/tree.AVL_Count() * 1000 << " ptw | ";
    for(auto & i : ss.info.docloc){
        cout << "(" << i.first << ", " << i.second << ") ";
    }
    cout << endl;
}

void printToFile(DATA ss, ofstream &index) {
    index << setw(15) << ss.key <<  " | " << setw(3) << ss.info.freq << " | "<< setw(10) << ss.info.freq/tree.AVL_Count() * 1000 << " ptw | ";
    for(auto & i : ss.info.docloc){
        index << "(" << i.first << ", " << i.second << ") ";
    }
    index << endl;
}

void editString(string &s) { //O(n)
    s.erase(remove_if(s.begin(), s.end(), [](char i) { return !isalpha(i) ; }), s.end());
    for_each(s.begin(), s.end(), [](char & c){
        c = ::tolower(c);
    });

}

void learnOneFile(string fn){ //O(n)
    ifstream file (fn);
    ofstream dicFile("dictionary.txt");
    int pos = 0;
    string input;
    DATA * Item;

    if (!file.is_open()){
        cout << "Error: file cannot be opened." << endl;
        return;
    }
    cout << "Learning from file: " << fn << endl;
    while (file >> input){ //  TOTAL: O(n)
        pos++;
        editString(input); // O(n)
        if (!input.empty()) { // TOTAL: O(1)
            if (tree.AVL_Retrieve(input, Item)) { //O(log n)
                Item->info.freq++;
                Item->info.docloc.emplace_back(fn, pos);
            } else {
                DATA newItem;
                newItem.key = input;
                newItem.info.freq = 1;
                newItem.info.docloc.emplace_back(fn, pos);
                tree.AVL_Insert(newItem); //O(log n)
            }
            dicFile << input << "\n";
        }
    }
    cout << "Total words of the dictionary: " << tree.AVL_Count() << endl << endl;

}

void learnMulFiles(){
    learnOneFile("MulFiles/article1.txt");
    learnOneFile("MulFiles/article2.txt");
    learnOneFile("MulFiles/article3.txt");
    learnOneFile("MulFiles/article4.txt");
    learnOneFile("MulFiles/article5.txt");
}

void learnFromFile(){
    ifstream file ("invertedIndex.txt");
    string line;
    while (getline(file, line)){
        cout << line << endl;
    }
}

void printDic(){
    cout << "The Inverted Index contains:" << endl;
    tree.AVL_Traverse(print);
    cout << endl;
}

void printAVL(){
    tree.AVL_Print();
 }

void outToFile(string fn){
    ofstream index (fn);
    if (index.is_open()){
        tree.AVL_Traverse(printToFile, index);
    }
    else
        cout << "Error: file could not be opened." << endl << endl;
}

void deleteNodes(){
    tree.AVL_DeleteLowFreq();
}