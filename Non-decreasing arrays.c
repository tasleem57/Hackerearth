 #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>
    #define pcx putchar_unlocked
    #define gcx getchar_unlocked
     
    typedef int32_t ichar; 
    typedef int_fast64_t fint; 
     
    static inline fint getfi () {
        ichar c = gcx();
        while (!isdigit (c)) c = gcx();
        fint n = 0;
        while (isdigit (c)) {
            n = n * 10 + c - '0';
            c = gcx();
        }
        return n;
    }
    static inline void putfi (fint n, char lc) {
        if (0 == n) {
            pcx ('0');
            if (lc) pcx (lc);
            return;
        }
        char s[24];
        fint rdi = 0;
        while (n) {
            s[rdi++] = '0' + n % 10;
            n /= 10;
        }
        while (rdi) pcx (s[--rdi]);
        if (lc) pcx (lc);
    }
     
    int main () {
        fint T = getfi() + 1;
        while (--T) {
            fint N = getfi() + 1;
            fint B = 0;
            while (--N) {
                fint X = getfi();
                if (B) {
                    if (B % X) //remainder
                        B += X - (B % X);
                } else
                    B = X;
                putfi(B, ' ');
            }
            pcx('\n');
        }
        return 0;
    }
