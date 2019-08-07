#include <stdio.h>
#include <string.h>


typedef struct DANE
{
    char* imie;
    char* nazwisko;
    int* rok;
}Dane;

typedef struct OSOBY Osoba;
struct OSOBY
{
    Dane dane;
    Osoba* next;
};

void odczyt_z_pliku(Osoba **head){
    FILE *wczytaj = NULL;
    char nazwa_pliku[] = "in.txt";
    char bufor[30 + 1]; //nie wiem czemu tyle, gdzieś znalazłem i działa XD
    int bufor2[30 + 1];
    Osoba *tmp, *pom;
    
    wczytaj = fopen(nazwa_pliku, "r");
    if (wczytaj == NULL)
        printf("Blad otwarcia pliku");
    else
    {
        while (fscanf(wczytaj, "%s", bufor) != EOF)
        {
            //alokowanie pamieci na nowy element
            tmp = (Osoba*)malloc(sizeof(Osoba));
            tmp->next = NULL;
            //wczytywanie imienia
            tmp->dane.imie = (char*)malloc(sizeof(char)* (strlen(bufor) + 1));
            strcpy(tmp->dane.imie, bufor);
            //wczytywanie nazwiska
            fscanf(wczytaj, "%s", bufor);
            tmp->dane.nazwisko = (char*)malloc(sizeof(char)* (strlen(bufor) + 1));
            strcpy(tmp->dane.nazwisko, bufor);
            //wczytywanie roku
            fscanf(wczytaj, "%d", bufor2);
            tmp->dane.rok = (int*)malloc(sizeof(int)* (strlen(bufor2)));
            strcpy(tmp->dane.rok, bufor2);
            if (*head == NULL)
                *head = tmp;
            else
            {
                pom = *head;
                while (pom->next != NULL)
                    pom = pom->next;
                pom->next = tmp;
            }
        }
        printf("Plik zostal wczytany\n");
    }
    fclose(wczytaj);
}
void zapisz_do_pliku(Osoba *head)
{
    FILE *zapisz = NULL;
    Osoba *tmp;
    char nazwa_pliku[] = "out.txt";
    
    if (head == NULL)
        printf("Nie ma elementow do zapisania");
    else
    {
        zapisz = fopen(nazwa_pliku, "w");
        if (zapisz == NULL)
            printf("Blad otwarcia pliku");
        else
        {
            tmp = head;
            while (tmp != NULL)
            {
                fprintf(zapisz, "%s  ", tmp->dane.imie);
                fprintf(zapisz, "%s  ", tmp->dane.nazwisko);
                fprintf(zapisz, "%d\n", *tmp->dane.rok);
                tmp = tmp->next;
            }
            printf("Lista zostala zapisana\n");
        }
        fclose(zapisz);
    }
}
//wyswietla liste
void wyswietlanie_listy(Osoba *head){
    Osoba *tmp;
    
    tmp = head;
    if (tmp == NULL)
        printf("Brak elementow");
    else
    {
        while (tmp != NULL)
        {
            printf("%s %s %d\n", tmp->dane.imie, tmp->dane.nazwisko, *tmp->dane.rok);
            tmp = tmp->next;
        }
    }
    getchar();
}

//Program główny
int main()
{
    Osoba *head = NULL;
    odczyt_z_pliku(&head);
    wyswietlanie_listy(head);
    zapisz_do_pliku(head);
    return 0;
}
