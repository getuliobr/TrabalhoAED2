#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Tipos.h"

int fsize(FILE *fp) {
  int prev = ftell(fp);
  fseek(fp, 0L, SEEK_END);
  int sz = ftell(fp);
  fseek(fp, prev, SEEK_SET); // volta o ponteiro pro inicio
  return sz;
}