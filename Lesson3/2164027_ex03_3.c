#include <stdio.h>
#include <math.h>


typedef struct {
    double x, y, z;
} Vector;

double getInnerProduct(Vector a, Vector b);

Vector ask_for_input();

double length(Vector v);

int main() {
    printf("INPUT FIRST VECTOR...\n");
    Vector a = ask_for_input();
    printf("INPUT SECOND VECTOR...\n");
    Vector b = ask_for_input();

    double innerProduct = getInnerProduct(a, b);
    printf("%lf", acos(innerProduct / (length(a) * length(b))) * 180 / M_PI);
}

Vector ask_for_input() {
    Vector v;
    printf("x:");
    scanf("%lf", &v.x);
    printf("y:");
    scanf("%lf", &v.y);
    printf("z:");
    scanf("%lf", &v.z);
    return v;
}

double getInnerProduct(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double length(Vector v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
