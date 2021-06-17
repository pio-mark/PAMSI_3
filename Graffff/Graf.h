//
// Created by Piotrek on 15.06.2021.
//

#ifndef GRAFFFF_GRAF_H
#define GRAFFFF_GRAF_H

#include <vector>
#include <random>
#include <iostream>
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
    vector<vector<int> > list;
    vector<vector<int> > wage;
    int vertex; //wierzcholek
    float density; //gestosc
    int connections; //poloczenie

public:
    graph(); //konstrukotr
    graph(int vert, float dens); //konstruktor z parametrem
    void fill(); //wypelnienie grafu
    void removeAll(); // usuniecie wszt
    void add(int i, int j, int w);  //dodajemy element
    void add(int i, int j) ; //dodajemy element
    void remove(int i, int j); //usuwamy element
    void show(); //pokazuje graf
    void saveName(char *name); //zapisujemy do pliku o nazwie
    void addVert(); // dodajemy wierzcholek
    void removeVert(int i); //usuwamy wierzcholek
    void visited(vector<bool> &vis, int i);
    bool isCompleted(); //sprawdzamy czy spojny
    bool isConnected(int one, int two); //sprawdzamy czy wierzcholki sa polaczone
    /*
     * Alogrytm Quicksorta
     */
    void quicksort(int row, int first, int last);
    void sort();
    void quicksortNode(vector<node> &tab, int first, int last);
    void sortNode(vector<node> &tab);

    void kruskal(); //Alogrytm Kruskla
    void prim(); // Algorytm Prima
};

void show_menu(); //menu
void menu(graph &graf); //funkcja zarzadajaca menu w zaleznosci od grafu


#endif //GRAFFFF_GRAF_H