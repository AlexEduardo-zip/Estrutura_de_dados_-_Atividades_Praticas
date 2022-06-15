#include <stdio.h>
#include <string.h>
int main()
{
    char linha[3000], palavras[51][51],
        aux[22];
    int j = 0;
    int k = 0;
    int contador[50] = {0};
    fgets(linha, 2501, stdin);
    int tamanho = strlen(linha);
    for (int i = 0; i < tamanho; i++)
    {
        if (linha[i] != ' ' & linha[i] != '\n')
        {
            palavras[j][k] = linha[i];
            k++;
            contador[j]++;
        }
        else
        {
            palavras[j][k] = '\0';
            j++;
            k = 0;
        };
    };
    tamanho = j;
    for (int i = 0; i < tamanho; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            if (contador[i] < contador[j])
            {
                int auxilia = contador[i];
                contador[i] = contador[j];
                contador[j] = auxilia;
                strcpy(aux, palavras[i]);
                strcpy(palavras[i], palavras[j]);
                strcpy(palavras[j], aux);
            };
        };
    };
    for (int i = 0; i < j; i++)
        printf("%s ", palavras[i]);
    printf("\n");
    return 0;
}