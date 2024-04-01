#include <math.h>
#include <oop.h>
#include <stdlib.h>
#include <string.h>

void draw_tri(struct shape *s) {
  struct triangle *this = container_of(s, struct triangle, base);
  printf("draw a %s: %d\t%d\t%d\n", s->name, this->a, this->b, this->c);
}

void draw_squ(struct shape *s) {
  struct square *this = container_of(s, struct square, base);
  printf("draw a %s: %d\n", s->name, this->a);
}

static struct shape_op tri_op = {
    .draw = draw_tri,
};

static struct shape_op squ_op = {
    .draw = draw_squ,
};

struct triangle *new_tri(int a, int b, int c) {
  struct triangle *t = (struct triangle *)malloc(sizeof(struct triangle));
  if (!t) {
    return NULL;
  }

  t->a = a;
  t->b = b;
  t->c = c;
  t->base.name = "triangle";
  t->base.sops = &tri_op;
  return t;
}

struct square *new_squ(int a) {
  struct square *s = (struct square *)malloc(sizeof(struct square));
  if (!s) {
    return NULL;
  }
  s->a = a;
  s->base.name = "square";
  s->base.sops = &squ_op;
  return s;
}

void free_tri(struct triangle *tri) {
  free(tri);
  tri = NULL;
  return;
}

void free_squ(struct square *squ) {
  free(squ);
  squ = NULL;
  return;
}
