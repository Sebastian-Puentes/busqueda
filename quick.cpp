#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void mostrarArreglo(int b[], int tamaño) {
    for (int i = 0; i < tamaño; i++)
        cout << b[i] << " ";
    cout << endl;
}
void Quicksort(int mostrarArreglo[], int izq, int der) {
    int i = izq, j = der, tmp;
    int piv = mostrarArreglo[(izq + der) / 2];
    while (i <= j) {
        while (mostrarArreglo[i] < piv)
            i++;
        while (mostrarArreglo[j] > piv)
            j--;
        if (i <= j) {
            tmp = mostrarArreglo[i];
            mostrarArreglo[i] = mostrarArreglo[j];
            mostrarArreglo[j] = tmp;
            i++;
            j--;
        }
    }
    if (izq < j)
        Quicksort(mostrarArreglo, izq, j);
    if (i < der)
        Quicksort(mostrarArreglo, i, der);
}
int main() {
    const int tamaño = 20;
    int a[tamaño];
    for (int i = 0; i < tamaño; i++)
        a[i] = i + 1;
    srand(time(0));
    random_shuffle(a, a + tamaño);
    cout << "Arreglo antes de QuickSort" << endl;
    mostrarArreglo(a, tamaño);
    Quicksort(a, 0, tamaño - 1);
    cout << "Arreglo despues de QuickSort" << endl;
    mostrarArreglo(a, tamaño);
    system("Pause");
    return 0;
}
