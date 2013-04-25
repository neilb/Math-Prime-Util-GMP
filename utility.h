#ifndef MPU_UTILITY_H
#define MPU_UTILITY_H

#include <gmp.h>
#ifndef STANDALONE
#include "ptypes.h"
#endif

/* tdiv_r is faster, but we'd need to guarantee in the input is positive */
#define mpz_mulmod(r, a, b, n, t)  \
  do { mpz_mul(t, a, b); mpz_mod(r, t, n); } while (0)

/* s = sqrt(a) mod p */
extern int sqrtmod(mpz_t s, mpz_t a, mpz_t p,
                   mpz_t t, mpz_t t2, mpz_t b, mpz_t g); /* 4 temp variables */

extern unsigned long modinverse(unsigned long a, unsigned long p);

extern UV mpz_order_ui(UV r, mpz_t n, UV limit);

extern void poly_mod_mul(mpz_t* px, mpz_t* py, UV r, mpz_t mod, mpz_t t1, mpz_t t2, mpz_t t3);
extern void poly_mod_pow(mpz_t *pres, mpz_t *pn, mpz_t power, UV r, mpz_t mod);

/* Solve x^2 + |D|y^2 = p */
extern int cornacchia(mpz_t x, mpz_t y, mpz_t D, mpz_t p);
/* Solve x^2 + |D|y^2 = 4p */
extern int modified_cornacchia(mpz_t x, mpz_t y, mpz_t D, mpz_t p);

/* return a Hilbert poly */
extern UV poly_hilbert(IV D, mpz_t**T);

#endif
