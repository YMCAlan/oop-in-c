#include <stdio.h>
#include <stdlib.h>

struct shape {
  const char *name;
  struct shape_op *sops;
};

struct shape_op {
  void (*draw)(struct shape *);
};

struct triangle {
  int a, b, c;
  struct shape base;
};

struct square {
  int a;
  struct shape base;
};

void draw_tri(struct shape *s);
void draw_squ(struct shape *s);

struct triangle *new_tri(int a, int b, int c);

struct square *new_squ(int a);

void free_tri(struct triangle *tri);
void free_squ(struct square *squ);
