#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <stdlib.h>
#include "trie.cpp"

using namespace std;


int main(){
    Trie root;
    string temp = "";
    vector<string> results;
    ifstream infile("dictonary.txt");
    string word;
    while(getline(infile, word)){
        root.insert(&*word.begin(), word.length());
    }
    infile.close();
    map<char, int> rack;
    rack['r'] = 1;
    rack['e'] = 1;
    rack['t'] = 2;
    rack['i'] = 1;
    rack['n'] = 1;
    rack['a'] = 1;
    
    root.getRackWords(temp, rack, results);
    cout << results.size() << endl;
    for(vector<string>::iterator it = results.begin(); it!= results.end(); it++){
        cout << *it << endl;
    }

}