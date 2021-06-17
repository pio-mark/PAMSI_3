//
// Created by Piotrek on 16.06.2021.
//

#include "GrafNaM.h"


/*
 * Konstrukotr z prametrami
 */
graph::graph(int vert, float dens) {
    vertex = vert;
    density = dens;
    connections = density * vertex * (vertex - 1) / 2;

    matrix = new int *[vertex];
    for (int i = 0; i < vertex; i++)
        matrix[i] = new int[vertex];

    for (int i = 0; i < vertex; i++)
        for (int j = 0; j < vertex; j++)
            matrix[i][j] = 0;
}
/*
 * Konstruktor bez prametrów
 */
graph::graph() {
    vertex = 0;
    density = 0;
    connections = 0;
}
/*
 * Wypełniamy graf losowymi cyframi
 */
void graph::fill() {

    int temp = connections;
    if (density < 1) {
        while (temp) {
            int i = rand() % vertex , j = rand() % vertex;
            if (j > i && !matrix[i][j]) {
                temp--; matrix[i][j] = 1 + rand() % 500;
            }
            else if (i > j && !matrix[j][i]) {
                temp--; matrix[j][i] = 1 + rand() % 500;
            }
        }
    }
    else {
        for (int i = 0; i < vertex; i++)
            for (int j = 0; j < vertex; j++)
                if (j > i)
                    matrix[i][j] = 1 + rand() % 500;
    }

    int connectionNew = 0;
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            if (matrix[i][j] != 0)
                connectionNew++;
        }
    }
    connections = connectionNew;
}

/*
 * Usuwamy wszystko z grafu
 */
void graph::removeAll() {
    for (int i = 0; i < vertex; i++)
        for (int j = 0; j < vertex; j++)
            matrix[i][j] = 0;
}

/*
 * Dodajemy element do grafu
 */
void graph::add(int i, int j, int w) {
    if (!matrix[i][j])
        connections++;
    if (j > i)
        matrix[i][j] = w;
    else
        matrix[j][i] = w;
}

/*
 * Dodajemy element do grafu
 */
void graph::add(int i, int j) {
    if (!matrix[i][j])
        connections++;
    if (j > i)
        matrix[i][j] = 1 + rand() % 500;
    else
        matrix[j][i] = 1 + rand() % 500;
}

/*
 * Usuwamy z grafu
 */
void graph::remove(int i, int j) {
    if (matrix[i][j])
        connections--;

    if (j > i)
        matrix[i][j] = 0;
    else
        matrix[j][i] = 0;
}
/*
 * Pokazuje budowe grafu
 */
void graph::show() {
    cout << "Graf:" << endl;
    cout << vertex << " wierzcholkow" << endl;
    cout << density << " wypelnienia" << endl;
    cout << connections << " polaczen" << endl;

    cout << "Macierz wag polaczen: " << endl;
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << matrix[i][j] << " \t";
        }
        cout << "\n";
    }
}


void graph::visited(vector<bool> &vis, int i) {
    vis[i] = true;
    for (int j = 0; j < vertex; j++)
        if (matrix[i][j] && !vis[j])
            visited(vis, j);
}


bool graph::isCompleted() {
    bool result = true; vector<bool> vis;

    for (int i = 0; i < vertex; i++)
        vis.push_back(false);
    visited(vis, 0);

    for (int i = 0; i < vertex; i++)
        result &= vis[i];

    return result;
}
/*
 * Spr czy wierzcholki sa polaczone
 */
bool graph::isConnected(int one, int two) {
    if (one > two) {
        int temp = one;
        one = two;
        two = temp;
    }
    vector<bool> vis;
    for (int i = 0; i < vertex; i++)
        vis.push_back(false);

    visited(vis, one);

    return vis[two];
}
/*
 * Zapis do pliku o danej nazwie
 */
void graph::saveName(char *name) {
    fstream plik;
    plik.open(name, ios::out);
    if (plik.good()) {
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++) {
                plik << matrix[i][j] << " ";
            }
            plik << "\n";
        }
        // std::cout << "Zapisano pomyslnie!" << std::endl;
    } else
        std::cout << "Blad zapisu!" << std::endl;

    plik.close();
}


/*
 * Quicksort jak dla projektu 2
 */
void graph::quicksortNode(vector<node> &tab, int first, int last) {
    int i = first, j = last, temp;
    int pivot = tab[(first + last) / 2].len;

    do {
        while (tab[i].len < pivot)
            i++;

        while (tab[j].len > pivot)
            j--;

        if (i <= j) {
            temp = tab[i].nr1;
            tab[i].nr1 = tab[j].nr1;
            tab[j].nr1 = temp;

            temp = tab[i].nr2;
            tab[i].nr2 = tab[j].nr2;
            tab[j].nr2 = temp;

            temp = tab[i].len;
            tab[i].len = tab[j].len;
            tab[j].len = temp;

            i++; j--;
        }
    } while (i <= j);

    if (first < j)
        quicksortNode(tab, first, j);
    if (i < last)
        quicksortNode(tab, i, last);
}
/*
 * Sort galezi
 */
void graph::sortNode(vector<node> &tab) {
    if (tab.size())
        quicksortNode(tab, 0, tab.size() - 1);
}

/**
 * Algorytm kruskala
 */
void graph::kruskal() {

    graph tree(vertex, 0); //puste drzewo
    vector<node> edges; // zbior ze wszystkimi krawedziami
    node temp;
    //Zbieramy wierzchołki
    for (int i = 0; i < vertex; i++)
        for (int j = 0; j < vertex; j++) {
            if (matrix[i][j]) {
                temp.nr1 = i;
                temp.nr2 = j;
                temp.len = matrix[i][j];
                edges.push_back(temp);
            }
        }

    //Sortujemy wzgledem wagi
    sortNode(edges);

    do {
        // sprawdzamy czy pierwsza krawedz laczy rozne drzewa
        if (!tree.isConnected(edges[0].nr1, edges[0].nr2)) {
            tree.add(edges[0].nr1, edges[0].nr2, edges[0].len);
        }
        // usuwamy pierwsza
        edges.erase(edges.begin());
    } while (edges.size() && !tree.isCompleted());

    //zapis wyniku do pliku
    //tree.saveName(const_cast<char *>("kruskal_matrix.txt"));
}

/**
 * Alogrytm prima
 */
void graph::prim() {
    graph tree(vertex, 0);//  puste drzewo
    bool *done; done = new bool[vertex];
    for (int i = 0; i < vertex; i++)
        done[i] = false;
    done[0] = true;

    vector<node> prior; // kolejka priorytetowa
    node temp;
    // wpisanie polczen z pierwszego wierzcholka
    for (int i = 0; i < vertex; i++) {
        if (matrix[0][i]) {
            temp.nr1 = 0;
            temp.nr2 = i;
            temp.len = matrix[0][i];
            prior.push_back(temp);
        }
    }
    // Gotowa kolejka dla 1 wierzchołka
    do {
        sortNode(prior);
        // Dodajemy perwszy element do grafu
        if (!done[prior[0].nr2]) {
            tree.add(prior[0].nr1, prior[0].nr2, prior[0].len);
            done[prior[0].nr2] = true;

            // Uzupełniamy kolejke
            for (int j = 0; j < vertex; j++) {
                if (matrix[prior[0].nr2][j]) {
                    temp.nr1 = prior[0].nr2;
                    temp.nr2 = j;
                    temp.len = matrix[prior[0].nr2][j];
                    prior.push_back(temp);
                }
            }
        }
        // usuwamy polaczenie
        prior.erase(prior.begin());
    } while (prior.size());

    //zapisanie wyniku do pliku
    //tree.saveName(const_cast<char *>("prim_matrix.txt"));
    delete[] done;
}
/*
 * Usuwa wierzcholek
 */
void graph::removeVert(int i) {
    for (int j = 0; j < vertex; j++) {
        matrix[j][i] = 0;
        matrix[i][j] = 0;
    }
}

void menu(graph &graf){
    int option, i, j, w;
    show_menu();
    do {
        cout << "Wybor> : ";
        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Jakie polaczenie dodac?" << endl;
                cin >> i;
                cin >> j;
                if (i == j) {
                    cout << "Nie ma takiego polaczenia" << endl;
                    break;
                }
                cout << endl << "O jakiej wadze? ";
                cin >> w;
                graf.add(i, j, w);
                break;
            case 2:
                cout << "Ktore chcesz usunac?" << endl;
                cin >> i;
                cin >> j;
                cout << "\n";
                graf.remove(i, j);
                break;
            case 4:
                cout << "Ktory wierzcholek? ";
                cin >> i;
                graf.removeVert(i);
                break;
            case 5:
                cout << "Graf jest: " << graf.isCompleted() << endl;
                break;
            case 6:
                graf.show();
                break;
            case 7:
                graf.removeAll();
                graf.fill();
                break;
            case 8:
                graf.removeAll();
                break;
            case 9:
                show_menu();
                break;
            case 10:
                int one, two;
                cout << "Ktore wierzcholki?" << endl;
                cin >> one;
                cin >> two;
                graf.isConnected(one, two);
                break;
            case 11:
                graf.kruskal();
                break;
            case 12:
                graf.prim();
                break;
            default:
                break;
        }
    } while (option != 0);
}

void show_menu() {
    cout <<endl<<"0. Zakoncz" << endl;
    cout << "1. Dodaj polaczenie" << endl;
    cout << "2. Usun polczenie" << endl;
    cout << "3. Dodaj wierzcholek" << endl;
    cout << "4. Usun polaczenia z wierzcholkiem" << endl;
    cout << "5. Sprawdz spojnosc" << endl;
    cout << "6. Wyswietl parametry" << endl;
    cout << "7. Wypelnij graf" << endl;
    cout << "8. Usun zawartosc" << endl;
    cout << "9. Wyswietl menu" << endl;
    cout << "10. Sprawdz czy dwa wierzcholki sa polaczone" << endl;
    cout << "11. Kruskal" << endl;
    cout << "12. Prim" << endl;
}


