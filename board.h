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
    Move(){};
    ~Move(){};
};

class Board{
    private:
    Piece[15][15] board;
    int numLetters;
    Trie theTrie;
    map<char,int> rack;
    
    public:
    Board(){
        numLetters = 0;
    }
    ~Board(){};
    isEmpty(){
        return numLetters == 0;
    }
    Move* findMoves(){
        Move answer[225];
        int index = 0;
        for (int i = 0; i < 15; i++){
            Move a;
            a.string = "";
            int spaces = 0;
            for (int j = 0; j < 15; j++){
                if (!(board[i][j].theChar >= 65 &&
                board[i][j].theChar <= 90)){
                //if (j == 14){
                  //  answer[index - 1].rightSpace = spaces + 1;
                //}
                if (a.string != ""){
                        answer[index] = a;
                        if (index > 0){
                            answer[index - 1].rightSpace = a.leftSpace;
                        }
                        index++;
                    }
                    a.string = "";
                    spaces++;
                }
                else if (board[i][j].theChar >= 65 &&
                board[i][j].theChar <= 90 && a.string == ""){
                    a.x = i;
                    a.y = j;
                    a.string = a.string + board[i][j].theChar;
                    a.leftSpace = spaces;
                    spaces = 0;
                }
                else {
                    a.string = a.string + board[i][j].theChar;
                }
            }
        }
    }
    
    
}