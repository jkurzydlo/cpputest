#include <iostream>
class MergeSort{

    void scal(int* tab, int rozmiar, int lewy, int srodek, int prawy)
    {
        int* pom = new int[rozmiar];
        int i = lewy, j = srodek + 1;

        // kopiujemy lew� i praw� cz�� tablicy do tablicy pomocniczej
        for (int i = lewy; i <= prawy; i++)
            pom[i] = tab[i];

        // scalenie dw�ch podtablic pomocniczych i zapisanie ich
        // we w�asciwej tablicy
        for (int k = lewy; k <= prawy; k++)
            if (i <= srodek)
                if (j <= prawy)
                    if (pom[j] < pom[i])
                        tab[k] = pom[j++];
                    else
                        tab[k] = pom[i++];
                else
                    tab[k] = pom[i++];
            else
                tab[k] = pom[j++];

        delete[] pom;
    }

public:
void sortowanie_przez_scalanie(int* tab, int rozmiar, int lewy, int prawy)
{
    // gdy mamy jeden element, to jest on ju� posortowany
    if (prawy <= lewy)
        return;

    // znajdujemy srodek podtablicy
    int srodek = (prawy + lewy) / 2;

    // dzielimy tablice na cz�s� lew� i prawa
    sortowanie_przez_scalanie(tab, rozmiar, lewy, srodek);
    sortowanie_przez_scalanie(tab, rozmiar, srodek + 1, prawy);

    // scalamy dwie ju� posortowane tablice
    scal(tab, rozmiar, lewy, srodek, prawy);
}
MergeSort() = default;

};