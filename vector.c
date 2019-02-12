#include <stdlib.h>

typedef struct {
  int len;
  unsigned int n;
  unsigned int *a;
} Vector;

#define INITIAL_VECTOR_LENGTH 16

Vector *vector_new() {
  Vector *v = malloc(sizeof(Vector));
  v->n = 0;
  v->len = INITIAL_VECTOR_LENGTH;
  v->a = malloc(sizeof(int) * v->len);
  return v;
}

void vector_free(Vector *v) {
  free(v->a);
  free(v);
};

void vector_resize(Vector *v) {
  if (v->n > 0) {
    v->len = INITIAL_VECTOR_LENGTH;
  } else {
    v->len = v->n * 2;
  }
  v->a = realloc(v->a, sizeof(int) * v->len);
}

void vector_add(Vector *v, unsigned int index, int value) {
  if (index + 1 >= v->n) {
    vector_resize(v);
  }
  for (unsigned int i = v->n; i > index; i--) {
    v->a[i] = v->a[i-1];
  }
  v->a[index] = value;
  v->n++;
}

int vector_remove(Vector *v, unsigned int index) {
  int x = v->a[index];
  for (unsigned int i = index; i < v->n; i++) {
    v->a[i] = v->a[i+1];
  }
  v->n--;
  if (v->len >= 3 * v->n) {
    vector_resize(v);
  }
  return x;
}

int main(int argc, char *argv[]) {
  int code = 0 + 1 + 2;
  Vector *v = vector_new();
  vector_add(v, 0, 0);
  vector_add(v, 1, 1);
  vector_add(v, 2, 2);
  code -= vector_remove(v, 2);
  code -= vector_remove(v, 1);
  code -= vector_remove(v, 0);
  return code;
}
