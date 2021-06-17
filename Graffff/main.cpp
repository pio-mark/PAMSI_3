#include <iostream>
#include "Graf.h"
#include <chrono>

using namespace std;
using namespace std::chrono;


int main() {

    //Program do obslugi ręcznej
    /*
    int vertex = 100;
    float density = 0.5;
    graph graf(vertex, density);
    menu(graf);
   */

    /*
     * Kod testujacy
     */

    float dens[4] = {0.25, 0.5, 0.75, 1};
    int vert[5] = {50, 100, 200, 300, 500};

    /*
     * Dwie petle dla kazdego wierzcholka tworzony jest graf o roznej gestosci
     */
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {

            graph graf(vert[i], dens[j]);
            graf.fill();
            auto start = high_resolution_clock::now();

            graf.kruskal();
            //graf.prim();
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Wierzcholki \t" << vert[i] << "; \tGestosc \t" << dens[j] << "; \tCzas \t" << duration.count()
                 << endl;

        }
    }
    system("pause");
}
