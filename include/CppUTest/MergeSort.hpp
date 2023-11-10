#include <iostream>
class MergeSort{

    void scal(int* tab, int rozmiar, int lewy, int srodek, int prawy)
    {
        int* pom = new int[rozmiar];
        int i = lewy, j = srodek + 1;

        // kopiujemy lew¹ i praw¹ czêœæ tablicy do tablicy pomocniczej
        for (int i = lewy; i <= prawy; i++)
            pom[i] = tab[i];

        // scalenie dwóch podtablic pomocniczych i zapisanie ich
        // we w³asciwej tablicy
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
    // gdy mamy jeden element, to jest on ju¿ posortowany
    if (prawy <= lewy)
        return;

    // znajdujemy srodek podtablicy
    int srodek = (prawy + lewy) / 2;

    // dzielimy tablice na czêsæ lew¹ i prawa
    sortowanie_przez_scalanie(tab, rozmiar, lewy, srodek);
    sortowanie_przez_scalanie(tab, rozmiar, srodek + 1, prawy);

    // scalamy dwie ju¿ posortowane tablice
    scal(tab, rozmiar, lewy, srodek, prawy);
}
MergeSort() = default;

};