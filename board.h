#include <string>
#include <map>
#include <iostream>
using namespace std;

struct Piece{
    char theChar;
    int letterProp;
    int wordProp;
    Piece();
    ~Piece();
};

struct Move{
    string wordSoFar;
    int x;
    int y;
    int leftSpace;
    int rightSpace;
    Move();
    ~Move();
};

class Board{
    private:
    Piece[15][15] board;
    int numLetters;
    Trie theTrie;
    map<char,int> rack;
    
    public:
    Board();
    ~Board();
    isEmpty();
    Move* findMoves();
    }
}