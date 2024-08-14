int __ashrsi3(int a, int b) {
    int result = a;

    result /= (1 << b);
    if (a < 0 && a % (1 << b) != 0) {
        result -= 1;
    }

    return result;
}
