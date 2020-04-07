
int printf(const char *format, ...);

int main()
{
    int n = printf("hello, world\n");
    printf("total chars printed: %d\n", n);
}
