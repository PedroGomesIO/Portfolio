#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void PrintBoard(int board[3][3]) {

    for(int i = 0; i < 3; i++) {

        for(int u = 0; u < 3; u++) {

            if(board[i][u] == 1)
                printf("[o]");
            else if(board[i][u] == -1)
                printf("[x]");
            else
                printf("[ ]");

        }

        printf("\n");

    }

}

int CheckResults(int board[3][3]) {

    int lSum[3] = {0}, cSum[3] = {0}, dSum[2] = {0};

    for(int i = 0; i < 3; i++) {

        for(int u = 0; u < 3; u++) {

            lSum[i] += board[i][u];
            cSum[u] += board[i][u];

            if(i == u)
                dSum[0] += board[i][u];
            
            if(i + u == 2)
                dSum[1] += board[i][u];

        }

    }

     for(int i = 0; i < 3; i++) {

         if(lSum[i] == 3 || cSum[i] == 3 || dSum[0] == 3 || dSum[1] == 3)
            return 1;
         else if(lSum[i] == -3 || cSum[i] == -3 || dSum[0] == -3 || dSum[1] == -3)
            return 2;

     }

     return 0;

}

int main() {

    int board[3][3] = {0};
    int line, column;
    bool play;

    for(int i = 0; i < 9; i++) {

        play = true;
        do {

            system("cls");
            PrintBoard(board);

            if(i % 2 == 0){

                printf("\nJogador 1 [o]\n");

                printf("Linha: ");
                scanf("%d", &line);

                printf("\nColuna: ");
                scanf("%d", &column);

                if(board[line-1][column-1] == 0) {

                    board[line-1][column-1] = 1;
                    play = false;

                }

            }
            else {

                printf("\nJogador 2 [x]\n");

                printf("Line: ");
                scanf("%d", &line);

                printf("\nColumn: ");
                scanf("%d", &column);

                if(board[line-1][column-1] == 0) {

                    board[line-1][column-1] = -1;
                    play = false;

                }

            }

            if(CheckResults(board) == 1) {

                system("cls");
                PrintBoard(board);
                printf("Player 1 won.\n");

                system("PAUSE");
                return 0;

            }
            else if(CheckResults(board) == 2) {

                system("cls");
                PrintBoard(board);
                printf("Player 2 won.\n");

                system("PAUSE");
                return 0;

            }

        } while(play == true);

    }

    system("cls");
    PrintBoard(board);
    printf("Draw!\n");

    system("PAUSE");

    return 0;

}
