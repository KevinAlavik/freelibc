long long __ashrti3(long long a, long long b) {
    long long result = a;

    if (a >= 0) {
        for (long long i = 0; i < b; i++)
        {
            result = result / 2;
        }
    } 
    
    else {
        for (long long i = 0; i < b; i++)
        {
            result = result / 2;
        }

        if (a % result != 0) {
            result -= 1;
        }

        return result;
    }
}
