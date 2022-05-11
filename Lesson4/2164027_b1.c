#include <stdio.h>

typedef struct {
    double x, y, z;
} Vector;

Vector ask_for_input();

Vector getCrossProduct(Vector a, Vector b);

int main() {
    printf("Vector A:\n");
    Vector v = ask_for_input();
    printf("Vector B:\n");
    Vector v1 = ask_for_input();
    printf("Cross Product of A and B is...\n");
    Vector r = getCrossProduct(v, v1);
    printf("x: %lf, ", r.x);
    printf("y: %lf, ", r.y);
    printf("z: %lf, ", r.z);
}

Vector ask_for_input() {
    Vector v;
    printf("  x: ");
    scanf("%lf", &v.x);
    printf("  y: ");
    scanf("%lf", &v.y);
    printf("  z: ");
    scanf("%lf", &v.z);
    return v;
}

Vector getCrossProduct(Vector a, Vector b) {
    Vector v = {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
    return v;
}

