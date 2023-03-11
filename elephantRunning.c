#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printRow(int row[]);

int space = 0;
int isTimeToRun = 1;

int row1[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0};
int row2[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 3, 4, 4, 4, 2, 0, 0, 3, 0};
int row3[21] = {0, 0, 0, 5, 6, 6, 6, 6, 7, 0, 0, 0, 0, 0, 8, 0, 8, 0, 0, 0, 9};
int row4[21] = {0, 0, 2, 0, 0, 0, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 1, 1, 2, 0};
int row5[21] = {0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 3, 0, 0, 10, 7, 0, 0, 0};
int row6[21] = {11, 0, 3, 0, 0, 0, 2, 1, 1, 1, 3, 0, 0, 2, 3, 0, 10, 0, 0, 0, 0};
int row7[21] = {0, 0, 0, 10, 1, 1, 10, 0, 0, 0, 10, 1, 1, 10, 6, 12, 0, 0, 0, 0, 0};

int _row6[21] = {11, 0, 3, 0, 0, 2, 0, 2, 1, 1, 3, 0, 0, 2, 3, 0, 10, 0, 0, 0, 0};
int _row7[21] = {0, 0, 2, 1, 2, 3, 1, 3, 0, 0, 2, 1, 2, 3, 1, 3, 12, 0, 0, 0, 0};

int _row6_[21] = {11, 0, 3, 0, 3, 0, 0, 2, 1, 1, 3, 0, 3, 0, 3, 0, 10, 0, 0, 0, 0};   

int microS = 1000;  

int main(void)
{
    int i = 0;
    int j = 0;
    getchar(); //для старта ввести любой символ
    system("clear");
    while(isTimeToRun){
        printRow(row1);
        printRow(row2);
        printRow(row3);
        printRow(row4);
        printRow(row5);
        switch(i){
            case 0:
                printRow(_row6_);
                printRow(_row7);
                break;
            case 1:
                printRow(row6);
                printRow(row7);
                break;
            case 2:
                printRow(_row6);
                printRow(_row7);
                break;
            case 3:
                printRow(row6);
                printRow(row7);
                break;
        }
        
        
        usleep(40*microS);
        i++;
        
        if (i == 4) i = 0; j++;
        space++; 
            
        if (j == 24) isTimeToRun = 0;
        if (isTimeToRun) system("clear");
    }  
    return 0;
}



void printRow(int row[])
{
    for (int i = 0; i < space; i++){
        printf(" ");
    }
    for (int i = 0; i < 21; i++){
        switch (row[i]){
            case 0: printf(" "); break;
            case 1: printf("_"); break;
            case 2: printf("/"); break;
            case 3: printf("\\"); break;
            case 4: printf("~"); break;
            case 5: printf(","); break;
            case 6: printf("-"); break;
            case 7: printf("("); break;
            case 8: printf("*"); break;
            case 9: printf(")"); break;
            case 10: printf("|"); break;
            case 11: printf("^"); break;
            case 12: printf("\""); break;
        }
    }
    printf("\n");
}