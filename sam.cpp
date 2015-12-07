#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "trie.cpp"
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include "LinkedList.cpp"
using namespace std;

struct Piece{
    char theChar;
    int letterProp;
    int wordProp;
    Piece(){
        letterProp = 1; //1 is default, 2 is double, 3 is triple
        wordProp = 1; //1 is default, 2 is double, 3 is triple
    }
    ~Piece(){};
};

struct Move{
    string wordSoFar;
    int x;
    int y;
    int leftSpace;
    int rightSpace;
    string direction;
    int score;
    Move(){};
    ~Move(){};
};

class Board{
    private:
    
    int numLetters;
    //Trie theTrie;
    //map<char,int> rack;
    
    public:
    map<char,int> rack;
    Trie theTrie;
    Piece board[15][15];
    Board(){
        numLetters = 0;
    }
    //Board(Piece pieces[][15]){
      //  numLetters = 0;
    //    board = pieces;
    //}
    ~Board(){};
    bool isEmpty(){
        return numLetters == 0;
    }
    // void findMoves(Move* answer){
    //     //Move answer[225];
    //     int index = 0;
    //     Move a;
    //     a.direction = "right";
    //     int spaces = 0;
    //     for (int i = 0; i < 15; i++){
    //         a.wordSoFar = "";
    //         a.x = 0;
    //         a.y = 0;
    //         a.leftSpace = 0;
    //         a.rightSpace = 0;
    //         spaces = 0;
    //         for (int j = 0; j < 15; j++){
    //             if (!(board[i][j].theChar >= 97 &&
    //             board[i][j].theChar <= 122)){
    //             if (a.wordSoFar != ""){
    //                     answer[index] = a;
    //                     if (index > 0){
    //                         if (answer[index - 1].x == a.x){
    //                         answer[index - 1].rightSpace = a.leftSpace;
    //                         }
    //                     }
    //                     index++;
                    
    //                 a.wordSoFar = "";
    //                 spaces = 0;
    //                 spaces++;
    //             }
    //             else {
    //                 spaces++;
    //             }
    //             }
                
    //             else if (board[i][j].theChar >= 97 &&
    //             board[i][j].theChar <= 122 && a.wordSoFar == ""){
    //                 a.x = i;
    //                 a.y = j;
    //                 a.wordSoFar = a.wordSoFar + board[i][j].theChar;
    //                 a.leftSpace = spaces;
    //                 spaces = 0;
    //             }
    //             else {
    //                 a.wordSoFar = a.wordSoFar + board[i][j].theChar;
    //             }
    //         }
    //         if (answer[index - 1].rightSpace == 0){
    //           answer[index - 1].rightSpace = spaces;
    //     }
    // }
    // }
    
    int findMoves(Move* answer, int i){
        //Move answer[225];
        int index = 0;
        Move a;
        a.direction = "right";
        int spaces = 0;
        a.wordSoFar = "";
        a.x = 0;
        a.y = 0;
        a.leftSpace = 0;
        a.rightSpace = 0;
        spaces = 0;
            for (int j = 0; j < 15; j++){
                if (!(board[i][j].theChar >= 97 &&
                board[i][j].theChar <= 122)){
                if (a.wordSoFar != ""){
                        answer[index] = a;
                        if (index > 0){
                            if (answer[index - 1].x == a.x){
                            answer[index - 1].rightSpace = a.leftSpace;
                            }
                        }
                        index++;
                    
                    a.wordSoFar = "";
                    spaces = 0;
                    spaces++;
                }
                else {
                    spaces++;
                }
                }
                
                else if (board[i][j].theChar >= 97 &&
                board[i][j].theChar <= 122 && a.wordSoFar == ""){
                    a.x = i;
                    a.y = j;
                    a.wordSoFar = a.wordSoFar + board[i][j].theChar;
                    a.leftSpace = spaces;
                    spaces = 0;
                }
                else {
                    a.wordSoFar = a.wordSoFar + board[i][j].theChar;
                }
            }
            if (answer[index - 1].rightSpace == 0){
              answer[index - 1].rightSpace = spaces;
        }
        return index;
    }

    
    // void findMovesDown(Move* answer){
    //     int index = 0;
    //     Move a;
    //     a.direction = "down";
    //     int spaces = 0;
    //     for (int i = 0; i < 15; i++){
    //         a.wordSoFar = "";
    //         a.x = 0;
    //         a.y = 0;
    //         a.leftSpace = 0;
    //         a.rightSpace = 0;
    //         spaces = 0;
    //         for (int j = 0; j < 15; j++){
    //             if (!(board[j][i].theChar >= 97 &&
    //             board[j][i].theChar <= 122)){
    //             if (a.wordSoFar != ""){
    //                     answer[index] = a;
    //                     if (index > 0){
    //                         if (answer[index - 1].x == a.x){
    //                         answer[index - 1].rightSpace = a.leftSpace;
    //                         }
    //                     }
    //                     index++;
                    
    //                 a.wordSoFar = "";
    //                 spaces = 0;
    //                 spaces++;
    //             }
    //             else {
    //                 spaces++;
    //             }
    //             }
                
    //             else if (board[j][i].theChar >= 97 &&
    //             board[j][i].theChar <= 122 && a.wordSoFar == ""){
    //                 a.x = i;
    //                 a.y = j;
    //                 a.wordSoFar = a.wordSoFar + board[j][i].theChar;
    //                 a.leftSpace = spaces;
    //                 spaces = 0;
    //             }
    //             else {
    //                 a.wordSoFar = a.wordSoFar + board[j][i].theChar;
    //             }
    //         }
    //         if (answer[index - 1].rightSpace == 0){
    //           answer[index - 1].rightSpace = spaces;
    //     }
    // }
    // }
    
    int findMovesDown(Move* answer, int i){
        int index = 0;
        Move a;
        a.direction = "down";
        int spaces = 0;
            a.wordSoFar = "";
            a.x = 0;
            a.y = 0;
            a.leftSpace = 0;
            a.rightSpace = 0;
            spaces = 0;
            for (int j = 0; j < 15; j++){
                if (!(board[j][i].theChar >= 97 &&
                board[j][i].theChar <= 122)){
                if (a.wordSoFar != ""){
                        answer[index] = a;
                        if (index > 0){
                            if (answer[index - 1].x == a.x){
                            answer[index - 1].rightSpace = a.leftSpace;
                            }
                        }
                        index++;
                    
                    a.wordSoFar = "";
                    spaces = 0;
                    spaces++;
                }
                else {
                    spaces++;
                }
                }
                
                else if (board[j][i].theChar >= 97 &&
                board[j][i].theChar <= 122 && a.wordSoFar == ""){
                    a.x = i;
                    a.y = j;
                    a.wordSoFar = a.wordSoFar + board[j][i].theChar;
                    a.leftSpace = spaces;
                    spaces = 0;
                }
                else {
                    a.wordSoFar = a.wordSoFar + board[j][i].theChar;
                }
            }
            if (answer[index - 1].rightSpace == 0){
              answer[index - 1].rightSpace = spaces;
        }
        return index;
    }
    
    
    Move isValid(Move* input, int size, string word){
        Move answer;
        answer.score = -1;
        answer.wordSoFar = word;
        int prevIndex = 0;
        int prevSize;
        int index;
        for (int i = 0; i < size; i++){
            index = word.find(input[i].wordSoFar, prevIndex);
            if (answer.score < 0){
                if (index < word.size() && (index >= 0)){
                if (input[i].leftSpace >= index &&
                ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) < 
                input[i].rightSpace){
                    if (input[i].direction == "right"){
                        answer.score = 1;
                        answer.x = input[i].x;
                        answer.y = input[i].y - index;
                        answer.direction = "right";
                      
                    return answer;
                }
                else {
                    answer.score = 1;
                    answer.x = input[i].x - index;
                    answer.y = input[i].y;
                    answer.direction = "down";
                    return answer;
                }
                }
                else if (input[i].leftSpace >= index &&
                ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) == 
                input[i].rightSpace){
                    if (input[i].direction == "right"){
                        if (i == size - 1){
                        answer.score = 1;
                        answer.x = input[i].x;
                        answer.y = input[i].y - index;
                        answer.direction = "right";
                         
                        return answer;
                }
                else {
                        answer.score = -1;
                        answer.x = input[i].x;
                        answer.y = input[i].y - index;
                        answer.direction = "right";
                         
                        return answer;
                }
                    }
                else {
                    if (i == size - 1){
                    answer.score = 1;
                    answer.x = input[i].x - index;
                    answer.y = input[i].y;
                    answer.direction = "down";
                    return answer;
                }
                else {
                    answer.score = -1;
                    answer.x = input[i].x - index;
                    answer.y = input[i].y;
                    answer.direction = "down";
                    return answer;
                }
                    }
                    }
                else if (input[i].leftSpace >= index &&
                ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) > 
                input[i].rightSpace){
                    if (input[i].direction == "right"){
                        answer.score = 1;
                        answer.x = input[i].x;
                        answer.y = input[i].y - index;
                        answer.direction = "right";
                        prevIndex = index;
                        prevSize = input[i].wordSoFar.size();
                        if (i == size - 1){
                            answer.score = -1;
                            return answer;
                        }
                        else continue;
                    }
                    else {
                        answer.score = 1;
                        answer.y = input[i].y;
                        answer.x = input[i].x - index;
                        answer.direction = "down";
                        prevIndex = index;
                        prevSize = input[i].wordSoFar.size();
                        if (i == size - 1){
                            answer.score = -1;
                            return answer;
                        }
                        else continue;
                    }
                }
                }
                }
            else if (answer.score >= 0){
                if (index > word.size() || (index < 0)){
                    answer.score = -1;
                    return answer;
                }
                else if (index < word.size() && (index >= 0)){
                if (((index - (prevIndex + (prevSize - 1))) - 1) != input[i].leftSpace){
                    answer.score = -1;
                    return answer;
                }
                if (input[i].leftSpace >= (index - (prevIndex + prevSize)) &&
                ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) < 
                input[i].rightSpace){
                    return answer;
                }
                
                else if (input[i].leftSpace >= (index - (prevIndex + prevSize)) &&
                ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) == 
                input[i].rightSpace){
                    if (input[i].direction == "right"){
                        if (i == size - 1){
                        answer.score = 1;
                        return answer;
                }
                else {
                        answer.score = -1;
                        return answer;
                }
                    }
                else {
                    if (i == size - 1){
                    answer.score = 1;
                    return answer;
                }
                else {
                    answer.score = -1;
                    return answer;
                }
                    }
                    }
                else if (input[i].leftSpace >= (index - (prevIndex + prevSize)) &&
                ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) > 
                input[i].rightSpace){
                    if (i == size - 1){
                        answer.score = -1;
                        return answer;
                    }
                    else{
                    if (input[i].direction == "right"){
                        answer.score = 1;
                        prevIndex = index;
                        prevSize = input[i].wordSoFar.size();
                        continue;
                    }
                    else {
                        answer.score = 1;
                        prevIndex = index;
                        prevSize = input[i].wordSoFar.size();
                        continue;
                    }
                }
                }
                prevIndex = index;
                prevSize = input[i].wordSoFar.size();
            }
    }
    }
    return answer;
    }
    
    Move findScoreAcross(Move m, map<char,int> map){
        Move move;
        bool shouldDouble;
        bool shouldTriple;
        for (int j = m.y, i = m.x, k = 0; j < m.y + m.wordSoFar.size(); j++, k++){
                if (board[i][j].theChar >= 97 &&
                board[i][j].theChar <= 122){
                    if (board[i][j].wordProp == 2){
                        shouldDouble = true;
                    }
                    if (board[i][j].wordProp == 3){
                        shouldTriple = true;
                    }
                    if (board[i][j].wordProp == 1){
                        
                    }
                    m.score = m.score + (board[i][j].letterProp * map.find(m.wordSoFar.at(k))->second);
                     
                }
            }
            if (shouldDouble == true){
                m.score = m.score * 2;
            }
            if (shouldTriple == true){
                m.score = m.score * 3;
            }
            move = m;
        return move;
    }
    
    Move findScoreDown(Move m, map<char,int> map){
        Move move;
        bool shouldDouble;
        bool shouldTriple;
        for (int i = m.x, j = m.y, k = 0; i < m.x + m.wordSoFar.size(); i++, k++){
                if (board[i][j].theChar >= 97 &&
                board[i][j].theChar <= 122){
                    if (board[i][j].wordProp == 2){
                        shouldDouble = true;
                    }
                    if (board[i][j].wordProp == 3){
                        shouldTriple = true;
                    }
                    if (board[i][j].wordProp == 1){
                        
                    }
                    m.score = m.score + (board[i][j].letterProp * map.find(m.wordSoFar.at(k))->second);
                     
                }
            }
            if (shouldDouble == true){
                m.score = m.score * 2;
            }
            if (shouldTriple == true){
                m.score = m.score * 3;
            }
            move = m;
            return move;
    }
    
    Move checkCrossesAcc(Move m, map<char,int> map){
        Move move;
        bool shouldDouble;
        bool shouldTriple;
        m.score = 0;
            for (int j = m.y, i = m.x, k = 0 ; j < m.y + m.wordSoFar.size(); j++, k++){
            string newWord = "";
            while (i >= 0 && (board[i][j].theChar >= 97 &&
                board[i][j].theChar <= 122)){
                i--;
            }
            while (i < 15 && (board[i][j].theChar >= 97 &&
                board[i][j].theChar <= 122)){
                    newWord = newWord + board[i][j].theChar;
                    m.score = m.score + (board[i][j].letterProp * map.find(m.wordSoFar.at(k))->second);
                    if (board[i][j].wordProp == 2){
                        shouldDouble = true;
                    }
                    if (board[i][j].wordProp == 3){
                        shouldTriple = true;
                    }
                }
            if (theTrie.hasWord(&*newWord.begin(), newWord.size())){
                if (shouldDouble == true){
                    m.score = m.score * 2;
                }
                if (shouldTriple == true){
                    m.score = m.score * 3;
                }
                move = m;
                return move;
            }
            else {
                m.score = -1;
                move = m;
                return move;
            }
            }
    }
    
    Move checkCrossesDown(Move m, map<char,int> map){
        Move move;
        bool shouldDouble;
        bool shouldTriple;
       m.score = 0;
            for (int j = m.y, i = m.x, k = 0; i < m.x + m.wordSoFar.size(); i++, k++){
            string newWord = "";
            while (j >= 0 && (board[i][j].theChar >= 97 &&
                board[i][j].theChar <= 122)){
                j--;
            }
            while (j < 15 && (board[i][j].theChar >= 97 &&
                board[i][j].theChar <= 122)){
                    newWord = newWord + board[i][j].theChar;
                    m.score = m.score + (board[i][j].letterProp * map.find(m.wordSoFar.at(k))->second);
                    if (board[i][j].wordProp == 2){
                        shouldDouble = true;
                    }
                    if (board[i][j].wordProp == 3){
                        shouldTriple = true;
                    }
                }
            if (theTrie.hasWord(&*newWord.begin(), newWord.size())){
                if (shouldDouble == true){
                    m.score = m.score * 2;
                }
                if (shouldTriple == true){
                    m.score = m.score * 3;
                }
                move = m;
            return move;
            }
            else {
                m.score = -1;
                move = m;
                return move;
            }
            }
    }
    
    
};

int main(){
    map<char, int> letter_value;

letter_value['a'] = 1;
letter_value['b'] = 3;
letter_value['c'] = 3;
letter_value['d'] = 2;
letter_value['e'] = 1;
letter_value['f'] = 4;
letter_value['g'] = 2;
letter_value['h'] = 2;
letter_value['i'] = 1;
letter_value['j'] = 8;
letter_value['k'] = 5;
letter_value['l'] = 1;
letter_value['m'] = 3;
letter_value['n'] = 1;
letter_value['o'] = 1;
letter_value['p'] = 3;
letter_value['q'] = 10;
letter_value['r'] = 1;
letter_value['s'] = 1;
letter_value['t'] = 1;
letter_value['u'] = 1;
letter_value['v'] = 4;
letter_value['w'] = 4;
letter_value['x'] = 8;
letter_value['y'] = 4;
letter_value['z'] = 10;
letter_value['*'] = 0;

    
    Board b;
    map<char,int> myRack;
    Move answer[225];
    Move answers[225];
    
    ifstream infile("board.txt");
    string aword;
    getline(infile, aword);
    for (int l = 0; l < aword.size(); l++){
        if (aword.at(l) == '*'){
            if (myRack.find('*') == myRack.end()){
                myRack.insert(std::pair<char,int>('*', 1));
            }
            else {
                myRack.find('*')->second = myRack.find('*')->second + 1;
            }
        }
        else {
            char achar = aword.at(l) + 32;
            if (myRack.find(achar) == myRack.end()){
                myRack.insert(std::pair<char,int>(achar, 1));
            }
            else{
                myRack.find(achar)->second = myRack.find(achar)->second + 1;
            }
        }
    }
    b.rack = myRack;
    for (int i = 0; i < 15; i++){
        getline(infile, aword);
        for (int j = 0; j < 15; j++){
            if (aword.at(j) == 45){
                b.board[i][j].theChar = 0;
            }
            else if (aword.at(j) >= 65 &&
                    aword.at(j) <= 90){
                b.board[i][j].theChar = aword.at(j) + 32;
        }
        else {
            b.board[i][j].theChar = 0;
            if ((aword.at(j) - '0') > 3){
                b.board[i][j].wordProp = sqrt(aword.at(j) - '0');
            }
            else b.board[i][j].letterProp = aword.at(j) - '0';
        }
    }
    }
    infile.close();
    
    Trie root;
    string temp = "";
    vector<string> results;
    infile.open("dictionary.txt");
    string word;
    while (getline(infile, word)){
        root.insert(&*word.begin(), word.length());
    }
    infile.close();
    
    b.theTrie = root;
    LinkedList ll;
    
    for (int k = 0; k < 15; k++){
        Move answer[50];
        int z = b.findMoves(answer, k);
        for (int m = 0; m < z; m++){
            string s = answer[m].wordSoFar;
            for (int n = 0; n < s.size(); n++){
                char ac = s.at(n);
                if (b.rack.find(ac) == b.rack.end()){
                    b.rack.insert(std::pair<char,int>(ac, 1));
                }
                else{
                    b.rack.find(ac)->second = b.rack.find(ac)->second + 1;
            }
            }
            vector<string> results;
            b.theTrie.getRackWords(temp, b.rack, results);
            for(vector<string>::iterator it = results.begin(); it!= results.end(); it++){
                Move m = b.isValid(answer, z, *it);
                if (m.score == -1){
                    continue;
                }
                //cout << "across" << m.score << endl;
                //cout << "across" << m.score << endl;
                m = b.checkCrossesAcc(m, letter_value);
                //cout << "across" << m.score << endl;
                m = b.findScoreAcross(m, letter_value);
                //cout << "across" << m.score << endl;
                if (m.score != -1){
                    ll.insert(m.wordSoFar, m.score, m.x, m.y, m.direction);
                }
        }
           for (int p = 0; p < s.size(); p++){
               char aa = s.at(p);
               if (b.rack.find(aa)->second == 1){
                   b.rack.erase(aa);
               }
               else {
                   b.rack.find(aa)->second = b.rack.find(aa)->second - 1;
               }
           } 
        }
        
    }
    
    for (int q = 0; q < 15; q++){
        Move answers[50];
        int y = b.findMovesDown(answers, q);
        for (int r = 0; r < y; r++){
            string t = answers[r].wordSoFar;
            for (int u = 0; u < t.size(); u++){
                char ab = t.at(u);
                if (b.rack.find(ab) == b.rack.end()){
                    b.rack.insert(std::pair<char,int>(ab, 1));
                }
                else{
                    b.rack.find(ab)->second = b.rack.find(ab)->second + 1;
            }
            }
            vector<string> results;
            b.theTrie.getRackWords(temp, b.rack, results);
            for(vector<string>::iterator it = results.begin(); it!= results.end(); it++){
                Move mv = b.isValid(answers, y, *it);
                if (mv.score == -1){
                    continue;
                }
                //cout << "mv.score " << mv.score << endl;
                mv = b.checkCrossesDown(mv, letter_value);
                //cout << "mv.score " << mv.score << endl;
                mv = b.findScoreDown(mv, letter_value);
                //cout << "mv.score " << mv.score << endl;
                if (mv.score != -1){
                    //cout << "mv.wordSoFar " << mv.wordSoFar << endl;
                    //cout << "mv.score " << mv.score << endl;
                    //cout << "mv.x " << mv.x << endl;
                    //cout << "mv.y " << mv.y << endl;
                    //cout << "mv.direction " << mv.direction << endl;
                    ll.insert(mv.wordSoFar, mv.score, mv.x, mv.y, mv.direction);
                }
        }
           for (int v = 0; v < t.size(); v++){
               char abc = t.at(v);
               if (b.rack.find(abc)->second == 1){
                   b.rack.erase(abc);
               }
               else {
                   b.rack.find(abc)->second = b.rack.find(abc)->second - 1;
               }
           } 
        }
        
    }
    ll.toString();
    
    cout << "hey" << endl;
    //b.findMoves(answer);
    //b.findMovesDown(answers);
    //cout << answer[2].leftSpace << endl;
    //Move m = b.isValid(answers, 1, "b");
    //cout << m.score << endl;
    
}