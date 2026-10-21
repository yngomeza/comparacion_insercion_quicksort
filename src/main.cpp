#include <iostream>
#include <vector>
using namespace std;

void insercion(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int aux = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = aux;
    }
}

void quickSort(vector<int>& v, int inicio, int fin) {
    if (inicio >= fin) return;

    int pivote = v[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (v[j] < pivote) {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[fin]);
    int p = i + 1;

    quickSort(v, inicio, p - 1);
    quickSort(v, p + 1, fin);
}

int main() {
    vector<int> datos = {8, 3, 6, 1, 5};

    vector<int> a = datos;
    vector<int> b = datos;

    insercion(a);
    quickSort(b, 0, b.size() - 1);

    cout << "Insercion: ";
    for (int x : a) cout << x << " ";

    cout << "\nQuickSort: ";
    for (int x : b) cout << x << " ";

    return 0;
}
