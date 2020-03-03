#include <stdio.h>

#if __EMSCRIPTEN__
    #include <emscripten.h>
    int main() {
        printf("WebAssembly module is loaded!");
        return 0;
    }
#else
    #include <time.h>
    #define EMSCRIPTEN_KEEPALIVE
    unsigned int wa_find_nth_prime(unsigned int n);
    int main() {
        printf("Let's just use pure compilation!\n");
        clock_t t = clock();
        unsigned int result = wa_find_nth_prime(10000);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC*1000;
        printf("Time difference = %ims\n", (unsigned int)time_taken);
        return 0;
    }
#endif


unsigned int wa_is_prime(unsigned int n) {
    for(unsigned int i=2; i<n-1; i++)
        if(n%i == 0)
            return 0;
    return 1;
}

unsigned int EMSCRIPTEN_KEEPALIVE wa_find_nth_prime(unsigned int n) {
    unsigned int prime_found = 0;
    unsigned int current = 2;
    unsigned int prime = 0;
    while(prime_found < n) {
        if (wa_is_prime(current)) {
            prime_found++;
            prime = current;
        }
        current++;
    }
    return prime;
}
