
int main() {
    int n =10;


    for(int i=0; i<n; i++) {
        printf("%2.d :", i);
        for(int sp=n-i; sp>=0; sp--) printf(" ");
        for(int j=0; j<=i; j++) printf("mdram     ");
        printf("\n");
    }
    printf("\n\n");
    
    return 0;
}
