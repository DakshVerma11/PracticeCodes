#include <stdio.h>


int main(){
    int hardness,tensile, score=0,grade=0;
    float carbon;

    printf("Enter Hardness , cabon content and Tensile strength of Steel: \n");
    scanf("%d %f %d",&hardness,&carbon,&tensile);
    if (hardness>50) score+=5;
    if (carbon<0.7) score+=3;
    if (tensile>5600) score+=1;

    switch (score)
    {
        case 9:
            grade=10;
            break;
        case 8:
            grade=9;
            break;

        case 4:
            grade=8;
            break;

        case 6:
            grade=7;
            break;

        case 1:
        case 3:
        case 5:
            grade=6;
            break;

        case 0:
            grade=5;
            break;
    }

printf("Grade = %d\n\n",grade);


return 0;

}