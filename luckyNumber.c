

int main()
{

    int num = 1299;

    while(num > 10) {
        int tmp = num;
        int sum = 0;
        while(tmp) {
            sum += tmp%10;
            tmp = tmp/10;
        }

        num = sum;
        printf("%d \n", num);
    }
}
