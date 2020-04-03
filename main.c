#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
extern float f1(float x);
extern float f2(float x);
extern float f3(float x);
char str[32];
float eps=0.0, x1, x2, x3, s1, s2, s3;
int n1, n2, n3, k=1;

float root(float (*f)(float), float (*g)(float), float a, float b, float eps1){
    float lsta=-2;
    while(fabs(lsta-a)>=eps1){
        if(k==1) n1++;
        if(k==2) n2++;
        if(k==3) n3++;
        lsta=a;
        a=a-(f(a)-g(a))*(a-b)/((f(a)-g(a))-(f(b)-g(b)));
    }
    k++;
    return a;
}

float integral(float (*f)(float), float a, float b, float eps2){
    float h,k,i,n=(1/eps2),i2=0,i4=0;
    h=(b-a)/n;
    i4=f(a+h);
    for(k=2;k<n;k+=2){
        i4+=f(a+(k+1)*h);
        i2+=f(a+k*h);
    }
    i=f(a)+f(b)+4*i4+2*i2;
    i*=h/3;
    return i;
}

int main(){
    printf("Task number 6. Assembly of multimodular programs\n");
    printf("f(x)=exp(-x)+3; g(x)=2x-2; h(x)=1/x\n");
    printf("Enter [-help] for help\n");
    printf("Created by using SASM and Microsoft Visual Studio\n\n");
    while(1){
        scanf("%s", str);
        if(strcmp (str, "-help")==0){
            printf("\nList of the commands:\n");
            printf("[-start] - calculate points of intersection and the area\n");
            printf("[-end] - close the program\n");
            continue;
        }
        if(strcmp (str, "-start")==0){
            printf("\nProgram will find root between (0; 4]\nEnter epsilon for root: ");
            scanf("%f", &eps);
            x1=root(f1, f2, 0.1, 4, eps);
            x2=root(f1, f3, 4, 0.1, eps);
            x3=root(f2, f3, 0.1, 4, eps);
            printf("\nRoot for f(x)=exp(-x)+3 and g(x)=2x-2: x1=%f, n=%i\n", x1, n1);
            printf("Root for f(x)=exp(-x)+3 and h(x)=1/x: x2=%f, n=%i\n", x2, n2);
            printf("Root for g(x)=2x-2 and h(x)=1/x: x3=%f, n=%i\n", x3, n3);
            printf("\nProgram will find square between functions.\nEnter epsilon for integrals: ");
            scanf("%f", &eps);
            s1=integral(f1, x2, x1, eps); // exp
            s2=integral(f3, x2, x3, eps); // 1/x
            s3=integral(f2, x3, x1, eps); // 2x-2
            printf("\nSquare between functions: S=%f", s1-s2-s3);
            continue;
        }
        if(strcmp (str, "-exit")==0){
            exit(1);
            continue;
        }
        else{
            printf("Use [-help] for show list of commands\n");
        }
    }
    return 0;
}
