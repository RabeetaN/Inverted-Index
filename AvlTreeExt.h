//
// Created by Rabeeta Nasir on 21/05/2021.
//

#ifndef AVL_TREE_AVLTREEEXT_H
#define AVL_TREE_AVLTREEEXT_H

#endif //AVL_TREE_AVLTREEEXT_H

using namespace std;
#include <queue>
#include "AVL_ADT.h"
#include <regex>



template <class TYPE, class KTYPE>
class AvlTreeExt : public AvlTree<TYPE, KTYPE>{
private:
    //queue <KTYPE> search; // queue for bfs
protected:
    void  _traversal  (void (*process)(TYPE dataProc, ofstream& index),
                       NODE<TYPE>    *root, ofstream& index)
    {
//	Statements
            if (root) {
                _traversal(process, root->left, index);
                 process(root->data, index);
                _traversal(process, root->right, index);
            } //  if
    }	//  _traversal;

public:
    using AvlTree<TYPE, KTYPE>::AVL_Traverse;
    using AvlTree<TYPE, KTYPE>::AVL_Count;
    using AvlTree<TYPE, KTYPE>::AVL_Delete;

    void  AVL_Traverse (void (*process)(TYPE  dataProc, ofstream& index), ofstream& index){
//	Statements
        _traversal (process, this->tree, index);
    }	// end AVL_Traverse

    void bfs(int min, vector<string> &td){
        queue<NODE<TYPE>*> search;
        search.push(this->tree);
        NODE<TYPE>* current;
        while (!search.empty()) {
            current = search.front();
            if (current != NULL) {
                double ptw = current->data.info.freq / AVL_Count() * 1000; // per thousand word
                if (ptw < min) { // test current node
                    td.push_back(current->data.key); // add node to delete
                }
                search.push(current->left);
                search.push(current->right);
            }
            search.pop();
        }
    }

    void AVL_DeleteLowFreq(){
        vector<string> toDelete;
        double minFreq;
        cout << "Enter minimum frequency (per thousand words): ";
        cin >> minFreq; // asks user for minimum per-thousand-word
        bfs(minFreq, toDelete);
        while(!toDelete.empty()){
            AVL_Delete(toDelete.front());
            toDelete.erase(toDelete.begin());
        }
    }
};