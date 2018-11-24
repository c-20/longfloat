#include "code.h"
#include "lf.h"

#define test main

IN test($) {
  LF one = { 1111111111, 111111111100000 };
  double onedouble = 1111111111.000001111111111;
  WI (one.frac NQ 0) { // full 36+ digit range
W1("%31.18f", onedouble); Ms("^2"); Wc('=');
    double resultdouble = onedouble * onedouble;
M1("%39.18f", resultdouble); _s(" ");
    onedouble /= 10.0;
Clfn(one, 13);
  IF (totaldigits(one.frac) < 18) {
    CH pad[8];
    sprintf(pad, "%%%ds", 18 - totaldigits(one.frac));
    printf(pad, " "); // last char is param
  }
Ys("^2"); Wc('=');
    LF result = lfmultiply(one, one);
Glfn(result, 23); _;
    one = lfscaledown(one, 1);
  }

  LF tot = { 0, 0 };
  LF x = { 0, 555 };
  IN lim = 1000000;
Ylf(x); Wc('*'); Ci(lim); Wc('=');
  IN i = -1;
  WI (++i < lim) {
    tot = lfadd(tot, x);
  }
Clf(tot);
  RT 0;
}
