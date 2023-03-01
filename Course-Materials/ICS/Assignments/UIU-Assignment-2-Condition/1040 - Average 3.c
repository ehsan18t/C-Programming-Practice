#include <stdio.h>

int main(){
    double a, b, c, d, e, avg, avg2;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    avg = ((a*2)+(b*3)+(c*4)+(d*1))/10.0;
    printf("Media: %.1lf\n",avg);
    if(avg >= 7){
        printf("Aluno aprovado.\n");
    } else if(avg >= 5 && avg <= 6.9){
        printf("Aluno em exame.\n");
        scanf("%lf", &e);
        avg2 = (avg+e)/2.0;
        printf("Nota do exame: %.1lf\n",e);
        if(avg2 >= 5)
            printf("Aluno aprovado.\n");
        else
            printf("Aluno reprovado.\n");
        printf("Media final: %.1lf\n",avg2);
   } else
        printf("Aluno reprovado.\n");
    return 0;
}
