#include "util.h"

int abs(int a) {
  return a < 0 ? -a : a;
}

float absf(float a) {
  return a < 0.0F ? -a : a;
}

int map(int n, int oldMin, int oldMax, int newMin, int newMax) {
  return ((((float)n) - oldMin) / (oldMax - oldMin)) * (newMax - newMin) + newMin;
}

int constrain(int n, int min, int max) {
  return n < min ? min : (n > max ? max : n);
}

int threshold(int n, int t) {
  return abs(n) < t ? 0 : n;
}
