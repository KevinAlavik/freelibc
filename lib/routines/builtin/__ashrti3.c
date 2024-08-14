long long __ashrsi3(long long a, long long b) {
    long long result = a;

    result /= (1 << b);
    if (a < 0 && a % (1 << b) != 0) {
        result -= 1;
    }

    return result;
}
