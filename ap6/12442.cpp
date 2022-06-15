#include <stdio.h>
#include <string.h>

typedef struct
{
    char texto[3000];
} string;

void ordena(string *palavras, unsigned tam);

int main()
{
    char entrada[3000];
    int casos, i, j, k;

    scanf("%d", &casos);
    string palavras[60];

    while (casos--)
    {

        memset(palavras, 0, sizeof(palavras));
        memset(entrada, 0, sizeof(entrada));
        scanf(" %[^\n]", entrada);

        i = j = k = 0;
        while (true)
        {
            while (entrada[i] != ' ')
            {
                if (entrada[i] == '\0')
                    break;
                else
                    palavras[j].texto[k++] = entrada[i++];
            }
            palavras[j].texto[k] = '\0';
            if (entrada[i] == '\0')
                break;
            i++;
            j++;
            k = 0;
        }
        j++;
        int i = 1, tamanho;
        string pivo;

        while (i < j)
        {
            tamanho = i - 1;
            pivo = palavras[i];

            while (tamanho >= 0 && strlen(palavras[tamanho].texto) < strlen(pivo.texto))
            {

                palavras[tamanho + 1] = palavras[tamanho];
                tamanho--;
            }

            palavras[tamanho + 1] = pivo;
            i++;
        }

        for (i = 0; i < j; i++)
        {
            if (i != j && i != 0)
                printf(" ");
            printf("%s", palavras[i].texto);
        }
        printf("\n");
    }
    return 0;
}