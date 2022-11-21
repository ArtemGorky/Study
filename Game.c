#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *cards[] = {"AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS",
                     "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH",
                     "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD",
                     "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"};
    printf("                         CONCENTRATION\n               CREATIVE COMPUTING MORRISTOWN NEW JERSEY\n\n\n");
    //-- SHUFFLE AND DEAL
    int end = 0;
    while (end == 0)
    {
        char *card[] = {};
        for (int z = 0; z < 52; z++)
        {
            card[0] = cards[z];
            int l = rand() % (52 - z);
            cards[z] = cards[l];
            cards[l] = card[0];
        }
        for (int i = 0; i < 52; i++)
        {
            printf("%s ", cards[i]);
        }
        printf("\n");
        //-- START TO PLAY
        int U = 0;
        int W = 0;
        int s = 0;
        for (int i = 0; i < 26; i++)
        {
            int next = 0;
            while (next == 0)
            {
                while (1)
                {
                    printf("FIRST CARD ");
                    scanf("%d", &U);
                    U--;
                    if (U >= 0 && U < 51)
                    {
                        if (cards[U] == " ")
                        {
                            printf("YOU HAVE ALREADY MATCHED THAT CARD.\n");
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        printf("THERE ARE ONLY 52 CARDS IN THE DECK, NOT %d \n", U);
                    }
                }
                while (1)
                {
                    printf("SECOND CARD ");
                    scanf("%d", &W);
                    W--;
                    if (W >= 0 && W < 51)
                    {
                        if (cards[W] == " ")
                        {
                            printf("YOU HAVE ALREADY MATCHED THAT CARD.\n");
                        }
                        else
                        {
                            if (W != U)
                            {
                                char value_U = *cards[U];
                                char value_W = *cards[W];
                                if (value_U == value_W)
                                {
                                    printf("THAT'S A MATCH --%s            %s\n", cards[U], cards[W]);
                                    cards[U] = " ";
                                    cards[W] = " ";
                                    s++;
                                    printf("YOUR SCORE IS NOW %d YOU HAVE HAD %d PICKS.\n", s, i + 1);
                                    next = 1;
                                    break;
                                }
                                else
                                {
                                    printf("#%d IS %s #%d IS %s", U+1, cards[U], W+1, cards[W]);
                                    for (int j = 0; j < 50; j++)
                                    {
                                        printf("\n");
                                    }
                                    printf("\rHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH");
                                    printf("\rIIIIIIIIIIIIIIIIIIIIIIIIIIIIII");
                                    printf("\rXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
                                    next = 1;
                                    break;
                                }
                            }
                            else
                            {
                                printf("YOU CAN'T PICK THE SAME CARD TWICE!\n");
                            }
                        }
                    }
                    else
                    {
                        printf("THERE ARE ONLY 52 CARDS IN THE DECK, NOT %d \n", U);
                    }
                }
            }
        }
        // -- THE RESULTS
        int s1;
        s1 = s / (26 / 4);
        s1 = s1 + 1.5;
        printf("YOU SCORED %d OUT OF %d THAT IS ", s, 26);
        switch (s1)
        {
        case 1:
            printf("POOR.");
            break;
        case 2:
            printf("FAIR.");
            break;
        case 3:
            printf("GOOD.");
            break;
        case 4:
            printf("EXCELLENT ! ! !");
            break;
        case 5:
            printf(". . . AAAH . . . UH....YOU MUST HAVE CHEATED!");
            break;
        }
        printf("\nDO YOU WANT TO PLAY AGAIN");
        char again[3] = {};
        scanf("%c%c%c", &again[0], &again[1], &again[2]);
        if (again[0] == 'Y' && again[1] == 'E' && again[2] == 'S')
        {
        }
        else
        {
            printf("\nCOME BACK AGAIN!!");
            end = 1;
        }

        return 0;
    }
}