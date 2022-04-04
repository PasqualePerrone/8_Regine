//Problema delle 8 regine:
//Piazzare 8 regine su una scacchiera affinchè esse non possano mangiarsi l'un l'altra in una sola mossa
//Il programma seguente fa un tentativo stile bruteforcesco
//Realizzato nel 2018 da Pasquale Perrone come esercizio di programmazione speciale assegnato in classe
#include <iostream>
using namespace std;
char mat[8][8]; int i,j,k,t = 1,queenY[8], q = 0, lastQ = -1;
void displayBoard(){
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
          cout << mat[i][j] << "  ";
        cout << "\n\n";
    }
}
int findQueenY(int x){
    for(i=0;i<8;i++) if(mat[x][i] == 'Q') return i;
}
void placeQueen(int x){
    int y = queenY[x];
    for(i=0;i<8;i++){
            if(mat[x][i] != 'Q') mat[x][i] = 'X';
            if(mat[i][y] != 'Q') mat[i][y] = 'X';
            if(mat[i][y+(x-i)] != 'Q' and y+(x-i) < 8 and y+(x-i) >= 0) mat[i][y+(x-i)] = 'X';
            if(mat[i][y-(x-i)] != 'Q' and y-(x-i) < 8 and y-(x-i) >= 0) mat[i][y-(x-i)] = 'X';
        }
}
void removeQueen(int x,int y){
    q--;
    mat[x][y] = '+';
    lastQ = y;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
            if(mat[i][j] != 'Q') mat[i][j] = '+';
    }
    displayBoard();
    for(k=0;k<q;k++){
        placeQueen(k);
    }
}
int nextPosition(int x,int y){
   if(mat[x][y] == '+' and y > lastQ){
        cout << "Position "<<x<<", "<<y<<"\n";
        mat[x][y] = 'Q';
        queenY[x] = y;
        placeQueen(x);
        lastQ = -1;
        q++;
        cout << "Queens: "<<q<<"\n";
        displayBoard();
        return 1;
    }
    else return 0;
}
int main() {
    int x,y,addq = 0;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            mat[i][j] = '+';
    for(x = 0;x<8;x++){
                  cout << "\nJumping to next row, x: "<<x<<"\n\n";
                for(y = 0;y<8;y++){
                    if(!addq) addq = nextPosition(x,y);
                }
                if(addq == 0){
                    removeQueen(x-1,findQueenY(x-1));
                    x = x-2;
                }
                addq = 0;
            }
    cout << "\n\n\nSolution found: \n";
    displayBoard();
    cout << "\n\n\n";
    return 0;
}