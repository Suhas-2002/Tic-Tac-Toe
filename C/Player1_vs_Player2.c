#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Logic(char a[3][3], char *p1, char *p2)
{
    int D1 = 0, D2 = 0, d1 = 0, d2 = 0;
    for (int i = 0; i < 3; i++)
    {
        int r1 = 0, r2 = 0, c1 = 0, c2 = 0;
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 'X') r1++;
            else if (a[i][j] == 'O') r2++;
            if (a[j][i] == 'X') c1++;
            else if (a[j][i] == 'O') c2++;

            if (i == j){
                if (a[i][j] == 'X') D1++;
                else if (a[i][j] == 'O') D2++;
            }

            if (i + j == 2){
                if (a[i][j] == 'X') d1++;
                else if (a[i][j] == 'O') d2++;
            }
        }

        if (r1 == 3 || c1 == 3){
            printf("Game Finished!\nCongratulations %s, you won!", p1);
            return 1;
        }
        else if (r2 == 3 || c2 == 3){
            printf("Game Finished!\nCongratulations p2, you won!", p2);
            return 1;
        }
        else if (D1 == 3 || d1 == 3){
            printf("Game Finished!\nCongratulations %s, you won!", p1);
            return 1;
        }
        else if (D2 == 3 || d2 == 3){
            printf("Game Finished!\nCongratulations p2, you won!", p2);
            return 1;
        }
    }
}

void Print_Matrix(char a[3][3]){
    int r = 0;
    for (int i = 0; i < 3; i++){
        int r1 = 0, r2 = 0, c1 = 0, c2 = 0;
        for (int j = 0; j < 3; j++){
            if (j % 2 != 0) printf("|");
            printf(" %c ", a[i][j]);
            if (j % 2 != 0) printf("|");
        }
        printf("\n");
        if (i != 2){
            printf("----------");
            printf("\n");
        }
    }
    printf("\n");
}

void Player_input(char a[3][3], int n, int i){
    switch (n){
    case 1:
        if (i % 2 == 0) a[0][0] = 'X';
        else a[0][0] = 'O';
        break;

    case 2:
        if (i % 2 == 0)  a[0][1] = 'X';
        else  a[0][1] = 'O';
        break;

    case 3:
        if (i % 2 == 0) a[0][2] = 'X';
        else a[0][2] = 'O';
        break;

    case 4:
        if (i % 2 == 0) a[1][0] = 'X';
        else a[1][0] = 'O';
        break;

    case 5:
        if (i % 2 == 0) a[1][1] = 'X';
        else  a[1][1] = 'O';
        break;

    case 6:
        if (i % 2 == 0)  a[1][2] = 'X';
        else  a[1][2] = 'O';
        break;

    case 7:
        if (i % 2 == 0)  a[2][0] = 'X';
        else  a[2][0] = 'O';
        break;

    case 8:
        if (i % 2 == 0)  a[2][1] = 'X';
        else a[2][1] = 'O';
        break;

    case 9:
        if (i % 2 == 0) a[2][2] = 'X';
        else a[2][2] = 'O';
        break;

    default:
        break;
    }
    Print_Matrix(a);
}

int main(){
    int n, f;
    char p1[20], p2[20], ans[10];
    printf("\nEnter Player1's name : ");
    gets(p1);
    printf("Enter Player2's name : ");
    gets(p2);
    do{
        char a[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        printf("\nYour game board\n");
        printf("\n");
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (j % 2 != 0) printf("|");
                printf(" %c ", a[i][j]);
                if (j % 2 != 0) printf("|");
            }
            printf("\n");
            if (i != 2){
                printf("----------");
                printf("\n");
            }
        }
        printf("\n");
        printf("Enter (1 to 9) to access the position : ");
        printf("\n");
        for (int i = 0; i < 9; i++){
            if (i % 2 == 0)  printf("%s's turn : ", p1);
            else if (i % 2 != 0) printf("%s's turn : ", p2);
            scanf("%d", &n);
            printf("\n");
            Player_input(a, n, i);
            f = Logic(a, p1, p2);
            if (f == 1) break;
        }
        if (f != 1)  printf("OMG! It's a Draw. Hahahahahahah.");
        printf("\n");
        printf("\nWanna Play Again?\nPress 'Y' to play again or 'N' to end game :)\n");
        scanf("%s", &ans);
    } while (strcmp(ans, "Y") == 0);
    printf("Thanks for playing :)");
    return 0;
}
