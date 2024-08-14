int __ashrsi3(int a, int b) {
    int result = a;

    if (a >= 0) {
        for (int i = 0; i < b; i++)
        {
            result = result / 2;
        }
    } 
    
    else {
        for (int i = 0; i < b; i++)
        {
            result = result / 2;
        }

        if (a % result != 0) {
            result -= 1;
        }

        return result;
    }
}
