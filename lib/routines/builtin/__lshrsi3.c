int __lshrsi3(int a, int b) {
    int result = a;

    for (int i = 0; i < b; i++)
    {
        result = result / 2;
    }

    return result;
}
