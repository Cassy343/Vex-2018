#ifndef _UTIL_H_
#define _UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

int abs(int);
float absf(float);
int map(int, int, int, int, int);
int constrain(int, int, int);
int threshold(int, int);

#ifdef __cplusplus
}
#endif

#endif
