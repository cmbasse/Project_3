#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <stdlib.h>
#include "trie.cpp"
#include "LinkedList.h"
#include <algorithm>

using namespace std;

LinkedList getMoves(string temp, map<char, int> rack, vector<string> results, int offset){
    LinkedList wordList;
    Trie root;
    ifstream infile("dictionary.txt");
    string word;
    while(getline(infile, word)){
        std::transform(word.begin(), word.end(),word.begin(), ::toupper);
        root.insert(&*word.begin(), word.length());
    }
    infile.close();
    map<char, int> letter_value;
    
    letter_value['A'] = 1;
    letter_value['B'] = 3;
    letter_value['C'] = 3;
    letter_value['D'] = 2;
    letter_value['E'] = 1;
    letter_value['F'] = 4;
    letter_value['G'] = 2;
    letter_value['H'] = 2;
    letter_value['I'] = 1;
    letter_value['J'] = 8;
    letter_value['K'] = 5;
    letter_value['L'] = 1;
    letter_value['M'] = 3;
    letter_value['N'] = 1;
    letter_value['O'] = 1;
    letter_value['P'] = 3;
    letter_value['Q'] = 10;
    letter_value['R'] = 1;
    letter_value['S'] = 1;
    letter_value['T'] = 1;
    letter_value['U'] = 1;
    letter_value['V'] = 4;
    letter_value['W'] = 4;
    letter_value['X'] = 8;
    letter_value['Y'] = 4;
    letter_value['Z'] = 10;
    letter_value['*'] = 0;
    
    root.getRackWords(temp, rack, results);
    cout << results.size() << endl;
    for(vector<string>::iterator it = results.begin(); it!= results.end(); it++){
        string tmp = *it;
        int len = tmp.size();
        int val = (len == 7)?50:0;
        for(int i = 0; i < len; i++){
            val += letter_value[tmp[i]]; 
        }
        if(len < 5){
            val -= offset;
            wordList.insert(tmp, val, 8, 8, "RIGHT");
        }else{
            LinkedList shifts;
            int shift = len - 4;
            int fxLoc = 4;
            int bxLoc = 8;
            //Front shift
            for(int i = 0; i < shift; i++){
                int front_val = val + letter_value[tmp[i]] - offset;
                shifts.insert(tmp, front_val, fxLoc, 8, "RIGHT");
                fxLoc -= 1; 
            }
            //Back shift
            for(int i = 0; i < shift; i++){
                int bi = tmp.size() - 1 - i;
                int back_val = val + letter_value[tmp[bi]] - offset;
                shifts.insert(tmp, back_val, bxLoc, 8, "RIGHT");
                bxLoc -= 1; 
            }
            
            wordList.insert(shifts.best_move());
        }
        
    }
    return wordList;
}

int main(){
    
    map<char, int> letter_value;
    
    letter_value['A'] = 1;
    letter_value['B'] = 3;
    letter_value['C'] = 3;
    letter_value['D'] = 2;
    letter_value['E'] = 1;
    letter_value['F'] = 4;
    letter_value['G'] = 2;
    letter_value['H'] = 2;
    letter_value['I'] = 1;
    letter_value['J'] = 8;
    letter_value['K'] = 5;
    letter_value['L'] = 1;
    letter_value['M'] = 3;
    letter_value['N'] = 1;
    letter_value['O'] = 1;
    letter_value['P'] = 3;
    letter_value['Q'] = 10;
    letter_value['R'] = 1;
    letter_value['S'] = 1;
    letter_value['T'] = 1;
    letter_value['U'] = 1;
    letter_value['V'] = 4;
    letter_value['W'] = 4;
    letter_value['X'] = 8;
    letter_value['Y'] = 4;
    letter_value['Z'] = 10;
    letter_value['*'] = 0;
    
   
    string temp = "";
    vector<string> results;
    bool wildcard = false;
    
    map<char, int> rack;
    rack['R'] = 1;
    rack['E'] = 1;
    rack['T'] = 1;
    rack['I'] = 1;
    rack['N'] = 1;
    rack['A'] = 1;
    rack['S'] = 1;
    
    
    LinkedList moveList = getMoves(temp, rack, results, 0);
    
    for(auto& itr : rack)  {
        if (itr.first == '*'){
            wildcard = true;
        }
    }
    
    // if(wildcard){
        
    //     int pt = 0;
    //     for(auto& itm : letter_value)  {
    //         char tmp = itm.first;
    //         pt = letter_value[tmp];
            
    //         map<char,int>::iterator itb;
    //         itb = rack.find(tmp);
    //         if (itb != rack.end()){
    //             rack[tmp] += 1;
    //         }else{
    //             rack[tmp] = 1;
    //         }
            
    //         LinkedList moveList = getMoves(temp, rack, results, pt);
            
    //         if(rack[tmp] == 1){
    //             map<char,int>::iterator ite;
    //             ite = rack.find(tmp);
    //             rack.erase(ite);
    //         }else{
    //             rack[tmp] -= 1;
    //         }
    //     }
    // }
    
    
    moveList.toString();
}