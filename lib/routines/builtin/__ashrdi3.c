long __ashrdi3(long a, long b) {
    long result = a;

    if (a >= 0) {
        for (long i = 0; i < b; i++)
        {
            result = result / 2;
        }
    } 
    
    else {
        for (long i = 0; i < b; i++)
        {
            result = result / 2;
        }

        if (a % result != 0) {
            result -= 1;
        }

        return result;
    }
}
