# longfloat
long float is a way to represent rational decimal numbers.

#define int64   long long
//#define int128   long long long .....
typedef struct _LF {
  int64 numb, frac;
} LF;

double A = 1.0001;
LF A = 1.0001; <---- ant. in c-20 (2020) gc-c
LF A = { 1, 1000 }; // scale 0s below
