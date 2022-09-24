#include <iostream>
using namespace std;

void print(int(*a)[3][3], int b) {
    for (int(*i)[3][3] = a; i < a + b; i++) {
        for (int(*j)[3] = *i; j < *(i + 1); j++) {
            for (int* k = *j; k < *(j + 1); k++) {
                cout << *k << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void multiplicacion(int(*a)[3][3], int b) {
    int* P_impares = **a;
    int(*P_sol)[3] = a[2];

    for (int(*aux)[3] = P_sol; aux < P_sol + b; ++aux) {
        int* P_pares = *a[1];
        for (int i = 0; i < 3; i++, ++P_impares) {
            for (int* obj_cell = *aux; obj_cell < *(aux + 1); ++obj_cell, ++P_pares) {
                *obj_cell += (*P_impares) * (*P_pares);
            }
        }
    }
}

int main(){
    int a[3][3][3] = { {{1,3,5},{7,9,11},{13,15,17}},{{2,4,6},{8,10,12},{14,16,18}},{{0,0,0},{0,0,0},{0,0,0}} };

    multiplicacion(a, 3);
    print(a, 3);
}