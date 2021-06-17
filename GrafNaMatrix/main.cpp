#include <iostream>
#include <chrono>
#include "GrafNaM.h"

using namespace std::chrono;

int main() {
/*
  //Reczne dzialanie programu
  int vertex = 5;
  float density = 0.8;
  graph graf(vertex, density);
  menu(graf);
*/

/*
 * Kod do obslugi testow
 */
    float dens[4] = {0.25, 0.5, 0.75, 1};
    int vert[5] = {10, 25, 50, 75, 100};

    /*
     * Dwie petle dla kazdego wierzcholka tworzony jest graf o roznej gestosci
     */
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            graph graf(vert[i], dens[j]);
            graf.fill();
            auto start = high_resolution_clock::now();

            //graf.kruskal();
            //graf.prim();
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);

            cout << "Wierzcholki \t" << vert[i] << "; \tGestosc \t" << dens[j] << "; \tCzas \t" << duration.count()
                 << endl;
        }
    }
    system("pause");

}
