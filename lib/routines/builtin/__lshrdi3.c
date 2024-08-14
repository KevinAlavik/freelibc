long __lshrdi3(long a, int b) {
    long result = a;

    for (int i = 0; i < b; i++)
    {
        result = result / 2;
    }

    return result;
}
