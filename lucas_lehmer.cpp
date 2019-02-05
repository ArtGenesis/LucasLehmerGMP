#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <gmp.h>
#include <gmpxx.h>
#include <math.h>
using namespace std;

int main(int argc, char * argv[]){
    mpz_t ppower;
    
    mpz_t ppowermin;
    mpz_t two;
    mpz_t one;
    mpz_t s;
    mpz_t k;
    mpz_t m;
    mpz_t zero;
    mpz_t smuls ;
    mpz_t smulsmin;
    mpz_init(smuls);
    mpz_init(smulsmin);
    mpz_init(ppowermin);
    mpz_init(m);
    mpz_init(k);
    mpz_init(s);
    mpz_init(zero);
    mpz_init(two);
    mpz_init(one);
    mpz_init(ppower);
    unsigned  int pow2 = atoi(argv[1]);
    
    mpz_set_str(ppower, argv[1],10);
    mpz_set_str(two,"2",10);
    mpz_set_str(one,"1",10);
    mpz_set_str(s,"4",10);
    mpz_set_str(k,"1",10);
    mpz_set_str(zero,"0",10);
    mpz_sub(ppowermin, ppower, one); 
    mpz_pow_ui(m, two, pow2);
    mpz_sub(m, m, one);
    while (mpz_cmp(k , ppowermin) != 0 )
    {
      mpz_mul(smuls, s, s);
      mpz_sub(smulsmin ,smuls, two);
      mpz_mod(s, smulsmin, m);
      mpz_add(k, k, one);
      //gmp_printf("%Zd\n", k);
      }
    if (mpz_cmp(s, zero) == 0){
        gmp_printf("%Zd\n", ppower);
    }
    mpz_clear(s);
    mpz_clear(k);
    mpz_clear(smuls);
    mpz_clear(smulsmin);
    mpz_clear(ppowermin);
    mpz_clear(m);
    return 0;
    }
