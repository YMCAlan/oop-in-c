#include <oop.h>

void draw_shape(struct shape *s) {
  s->sops->draw(s);
  return;
};

int main(int args, char *argv[]) {
  struct triangle *t = new_tri(5, 3, 2);
  struct square *s = new_squ(5);

  draw_shape(&(t->base));
  draw_shape(&(s->base));

  free_tri(t);
  free_squ(s);
  return 0;
}
