//
// Created by Piotrek on 16.06.2021.
//

#ifndef GRAFNAMATRIX_GRAFNAM_H
#define GRAFNAMATRIX_GRAFNAM_H
#include <iostream>
#include <random>
#include <vector>
#include <fstream>
using namespace std;

/**
 * Klasa wezel
 */
class node {
public:
    int nr1;
    int nr2;
    int len;
};
/**
 * Klasa graf
 */
class graph {
    int **matrix; //macierz
    int vertex;//wierzcholek
    float density; // gestsc
    int connections; //polaczenia

public:

    graph(); //Konstruktor bez prametrow
    graph(int vert, float dens); // Konstruktor z parametrami
    void fill(); //Metoda wypełniajaca graf rand cyframi
    void removeAll(); //Metoda usuwajaca
    void add(int i, int j, int w); //dodajemy element
    void add(int i, int j);  //dodajemy element
    void remove(int i, int j); //usuwamy element
    void removeVert(int i); //dodajemy wierzcholek
    void show(); //pokazuje graf
    void visited(vector<bool> &vis, int i);
    bool isCompleted(); //spr spojnosc
    bool isConnected(int one, int two); //sprawdzamy czy wirzcholki sa polaczone
    void saveName(char *name); //zapisujemy do pliku o nazwie

    void quicksortNode(vector<node> &tab, int first, int last); //Alogrytm Quicsorta
    void sortNode(vector<node> &tab);

    void kruskal(); //Algorytm kruskala
    void prim();    //Algorytm prima

};

void show_menu(); //menu
void menu(graph &graf); //funkcja zarzadajaca menu w zaleznosci od grafu


#endif //GRAFNAMATRIX_GRAFNAM_H
