void separate_bases(int number, short parts[2]) 
{
    int result;
    int rem;

    // Divide the number successively by 65536 and store the remainders
    for (int i = 0; i < 2; ++i) 
    {
        // x86_div64_32(number, 65536, &result, &rem);
        
        result = number / 65536;
        rem = number % 65536;

        parts[i] = (short)(rem);
        number = result;
    }
}

short multiply(short a, short n)
{
    short result = 0;

    for (short i = 0; i < n; i++)
    {
        result = result + a;
    }

    return result;
}

int __mulsi3(int a, int b) {
    short first_factor_digits[2];
    short second_factor_digits[2];

    short m_digits[2];
    short c_digits[2];

    int M = 0;
    int C = 0;

    separate_bases(a, first_factor_digits);
    separate_bases(b, second_factor_digits);

    for (short i = 0; i < 2; i++)
    {
        M = first_factor_digits[0] * second_factor_digits[0] + C;

        int rem;
        //x86_div64_32(M, 65536, &C, &rem);
        
        rem = M % 65536;

        c_digits[i] = (short)rem;
    }

    return M;
}
