long long __lshrti3(long long a, int b) {
    long long result = a;

    for (int i = 0; i < b; i++)
    {
        result = result / 2;
    }

    return result;
}
