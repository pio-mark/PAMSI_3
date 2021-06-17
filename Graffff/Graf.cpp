//
// Created by Piotrek on 15.06.2021.
//

#include "Graf.h"
using namespace std;

/*
 * Konstrukotr z prametrami
 */
graph::graph(int vert, float dens) {
    vertex = vert;
    density = dens;
    connections = density * vertex * (vertex - 1) / 2;
    vector<int> temp;

    for (int i = 0; i < vertex; i++)
        wage.push_back(temp);

    for (int i = 0; i < vertex; i++)
        list.push_back(temp);
}
/*
 * Konstruktor bez prametrów
 */
graph::graph(){
    vertex = 0;
    density = 0;
    connections = 0;
}

/*
 * Wyswiwetlamy graf
 */
void graph::show() {
    std::cout << "Graf" << endl;
    cout << vertex << " wierzcholkow" << endl;
    cout << density << " wypelnienia" << endl;
    cout << connections << " polaczen" << endl;

    cout << " Lista polaczen: " << endl;
    for (unsigned int i = 0; i < list.size(); i++) {
        cout << i << "|  ";
        for (unsigned int j = 0; j < list[i].size(); j++) {
            cout << list[i][j] << " \t";
        }
        cout << "\n";
    }

    cout << " Lista wag: " << endl;
    for (unsigned int i = 0; i < wage.size(); i++) {
        cout << i << "|  ";
        for (unsigned int j = 0; j < wage[i].size(); j++) {
            cout << wage[i][j] << " \t";
        }
        cout << "\n";
    }
}
/*
 * Usuwamy element
 */
void graph::remove(int i, int j) {
    for (unsigned int k = 0; k < list[i].size(); k++) {
        if (list[i][k] == j) {
            list[i].erase(list[i].begin() + k);
            wage[i].erase(wage[i].begin() + k);
        }
    }
    for (unsigned int k = 0; k < list[j].size(); k++) {
        if (list[j][k] == i) {
            list[j].erase(list[j].begin() + k);
            wage[j].erase(wage[j].begin() + k);
        }
    }
}

/*
 * Wypelniamy graf
 */
void graph::fill() {

    int temp = connections, **matrix;
    matrix = new int *[list.size()];
    for (int i = 0; i < vertex; i++)
        matrix[i] = new int[vertex]{0};

    if (density < 1) {
        while (temp) {
            int i = rand() % vertex;
            int j = rand() % vertex;
            if (i != j) {
                if (j > i && !matrix[i][j]) {
                    temp--;
                    matrix[i][j] = 1 + rand() % 500;
                } else if (i > j && !matrix[j][i]) {
                    temp--;
                    matrix[j][i] = 1 + rand() % 500;
                }
            }
        }
    } else {
        for (int i = 0; i < vertex; i++)
            for (int j = 0; j < vertex; j++)
                if (j > i)
                    matrix[i][j] = 1 + rand() % 500;
    }

    int con_new = 0;
    for (int i = 0; i < vertex; i++)
        for (int j = 0; j < vertex; j++) {
            if (matrix[i][j]) {
                con_new++;
                list[i].push_back(j);
                list[j].push_back(i);
                wage[i].push_back(matrix[i][j]);
                wage[j].push_back(matrix[i][j]);
            }
        }
    connections = con_new;
    for (int i = 0; i < vertex; i++)
        delete matrix[i];

    delete matrix;
}
/*
 * Czyscimy graf
 */
void graph::removeAll() {
    for (unsigned int i = 0; i < list.size(); i++) {
        list[i].clear();
        wage[i].clear();
    }
}

/*
 * Dodajemy element
 */
void graph::add(int i, int j, int w) {

    if (vertex >= i && vertex >= j) {
        bool exist = false;
        for (unsigned int k = 0; k < list[i].size(); k++)
            if (list[i][k] == j)
                exist = true;

        if (!exist) {
            connections++;
            list[i].push_back(j);
            wage[i].push_back(w);

            list[j].push_back(i);
            wage[j].push_back(w);
        }
    }
}
/*
 * Dodajey element
 */
void graph::add(int i, int j) {
    if (vertex >= i && vertex >= j) {
        bool exist = false;
        for (unsigned int k = 0; k < list[i].size(); k++)
            if (list[i][k] == j)
                exist = true;

        if (!exist) {
            connections++;
            list[i].push_back(j);
            wage[i].push_back(1 + (rand() % 500));
        }
    }
}



/*
 * Zapis danych do pliku o nazwie
 */
void graph::saveName(char *name) {
    fstream plik;
    plik.open(name, ios::out);
    if (plik.good()) {
        for (int i = 0; i < vertex; i++) {
            for (unsigned int j = 0; j < list[i].size(); j++) {
                plik << i << " " << list[i][j] << " " << wage[i][j] << endl;
            }
        }

       //cout << "Zapisano pomyslnie!" << endl;
    } else
        cout << "Blad zapisu!" << endl;

    plik.close();
}

void graph::visited(vector<bool> &vis, int i) {
    vis[i] = true;
    for (unsigned int j = 0; j < list[i].size(); j++) {
        if (!vis[list[i][j]])
            visited(vis, list[i][j]);
    }
}

/*
 * Sprawdzamy spojnosc
 */
bool graph::isCompleted() {
    bool result = true;
    vector<bool> vis;
    for (int i = 0; i < vertex; i++)
        vis.push_back(false);
    visited(vis, 0);

    for (int i = 0; i < vertex; i++)
        result &= vis[i];

    return result;
}

/*
 * Sprawdzamy czy dwa wierzcholki sa polaczone
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
/**
 * Alogorytm Qicksorta z proj 2
 */
void graph::quicksort(int row, int first, int last) {
    int i = first, j = last, temp;
    int pivot = wage[row][(first + last) / 2];

    do {
        while (wage[row][i] < pivot)
            i++;

        while (wage[row][j] > pivot)
            j--;

        if (i <= j) {
            temp = list[row][i];
            list[row][i] = list[row][j];
            list[row][j] = temp;

            temp = wage[row][i];
            wage[row][i] = wage[row][j];
            wage[row][j] = temp;

            i++;
            j--;
        }
    } while (i <= j);

    if (first < j)
        quicksort(row, first, j);
    if (i < last)
        quicksort(row, i, last);
}

void graph::sort() {
    for (int i = 0; i < vertex; i++)
        if (list[i].size())
            quicksort(i, 0, list[i].size() - 1);
}

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

            i++;
            j--;
        }
    } while (i <= j);

    if (first < j)
        quicksortNode(tab, first, j);
    if (i < last)
        quicksortNode(tab, i, last);
}

void graph::sortNode(vector<node> &tab) {
    if (tab.size())
        quicksortNode(tab, 0, tab.size() - 1);
}

/*
 *
 */
void graph::removeVert(int i) {
    list[i].clear();
    list.erase(list.begin() + i);

    wage[i].clear();
    wage.erase(list.begin() + i);

    for (unsigned int j = 0; j < list.size(); j++)
        for (unsigned int k = 0; k < list[j].size(); k++)
            if (list[j][k] == i) {
                list[j].erase(list[j].begin() + k);
                wage[j].erase(wage[j].begin() + k);
            }

    for (unsigned int j = 0; j < list.size(); j++)
        for (unsigned int k = 0; k < list[j].size(); k++)
            if (list[j][k] > i)
                list[j][k]--;

}
/*
 * dodajemy wierzcholek
 */
void graph::addVert() {
    vertex++;
    vector<int> v;
    list.push_back(v);
    wage.push_back(v);
}

/**
 * Algorytm kruskala
 */
void graph::kruskal() {
    graph tree(list.size(), 0); //puste drzewo
    vector<node> edges; // zbior ze wszystkimi krawedziami
    node temp;

    //Zbieramy wierzchołki
    for (unsigned int i = 0; i < list.size(); i++)
        for (unsigned int j = 0; j < list[i].size(); j++) {
            if ((int)i < list[i][j]) {
                temp.nr1 = i;
                temp.nr2 = list[i][j];
                temp.len = wage[i][j];
                edges.push_back(temp);
            }
        }

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
    //tree.saveName(const_cast<char *>("kruskal_list.txt"));
}

/**
 * Alogrytm prima
 */
void graph::prim() {
    graph tree(list.size(), 0); //  puste drzewo
    bool *done;
    done = new bool[list.size()];
    for (unsigned int i = 0; i < list.size(); i++)
        done[i] = false;
    done[0] = true;


    vector<node> prior; //kolejka priorytetowa
    node temp;

    // wpisanie polczen z pierwszego wierzcholka
    for (unsigned int k = 0; k < list[0].size(); k++) {
        temp.nr1 = 0;
        temp.nr2 = list[0][k];
        temp.len = wage[0][k];
        prior.push_back(temp);
    }
    // Gotowa kolejka dla 1 wierzchołka
    do {
        sortNode(prior);
        // Dodajemy perwszy element do grafu
        if (!done[prior[0].nr2]) {
            tree.add(prior[0].nr1, prior[0].nr2, prior[0].len);
            done[prior[0].nr2] = true;
            // Uzupełniamy kolejke
            for (unsigned int k = 0; k < list[prior[0].nr2].size(); k++) {
                temp.nr1 = prior[0].nr2;
                temp.nr2 = list[prior[0].nr2][k];
                temp.len = wage[prior[0].nr2][k];
                prior.push_back(temp);
            }
        }
        // usuwamy polaczenie
        prior.erase(prior.begin());
    } while (prior.size());
    //zapisanie wyniku do pliku
    //tree.saveName(const_cast<char *>("prim_list.txt"));
    delete[] done;
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




