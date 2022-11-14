#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char cards[52][3] = {"AS","2S","3S","4S","5S","6S","7S","8S","9S","10S","JS","QS","KS",
    "AH","2H","3H","4H","5H","6H","7H","8H","9H","10H","JH","QH","KH",
    "AD","2D","3D","4D","5D","6D","7D","8D","9D","10D","JD","QD","KD",
    "AC","2C","3C","4C","5C","6C","7C","8C","9C","10C","JC","QC","KC"};
    printf("                         CONCENTRATION\n               CREATIVE COMPUTING MORRISTOWN NEW JERSEY\n\n\n");  
    //-- SHUFFLE AND DEAL
    char card[1][3];
    for(int i=0;i<52;i++){
        for(int j=0;j<3;j++){
            card[0][j] = cards[i][j];
        }
        int l = rand() % (52-i);
        for(int j=0;j<3;j++){
            cards[i][j] = cards[l][j]; 
            cards[l][j] = card[0][j];
        } 
    }
    //-- START TO PLAY
    int U;
    int W;
    int x = 1;
    for(int i = 0;i<26;i++){
        while(x == 1){
            printf("FIRST CARD");
            scanf("%d", U);
            if(U>0 && U<52){
                if(cards[U][0] == 0){
                    printf("YOU HAVE ALREADY MATCHED THAT CARD.");
                } else{x = 0;}
            } else {
                printf("THERE ARE ONLY 52 CARDS IN THE DECK, NOT ", U);
            }
        }
        while(x == 0)
        {
            printf("SECOND CARD");
            scanf("%d", W);
            if(W>0 && W<52){
                if(cards[W][0] == 0){
                    printf("YOU HAVE ALREADY MATCHED THAT CARD.");
                }else{x = 1;}
            } else 
            {
                printf("THERE ARE ONLY 52 CARDS IN THE DECK, NOT ", U);
            }
        }
    }    
    return 0;
}