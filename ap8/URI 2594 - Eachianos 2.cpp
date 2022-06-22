#include <iostream>
#include <string>

using namespace std;

struct ap8
{
    string palavra;
    int tam;
};

int main()
{
    int qFrases;
    cin >> qFrases;
    for (int l = 0; l < qFrases; l++)
    {
        string palavraBuscada = " ";
        string frase = " ";

        cin.ignore();
        getline(cin, frase);
        cin >> palavraBuscada;
        ap8 palavras[50];
        int tamanhoVetor = 0;

        int tamanho = frase.size();
        string texto = "";
        int localInsere = 0;
        int j;
        for (j = 0; j < tamanho; j++)
        {
            if (frase[j] == ' ')
            {
                int tam = texto.size();
                palavras[localInsere].palavra = texto;
                palavras[localInsere].tam = tam;
                tamanhoVetor++;
                texto = "";
                localInsere++;
            }
            else
            {
                texto += frase[j];
            }
        }
        int tam = j - texto.size();
        palavras[localInsere].palavra = texto;
        palavras[localInsere].tam = tam;
        tamanhoVetor++;
        texto = "";

        int k = 0;
        while (palavras[k].palavra != palavraBuscada & k < tamanhoVetor)
        {
            k++;
        }
        int it = k;
        if (it == tamanhoVetor)
        {
            cout << "-1";
        }
        else
        {
            int posicao = 0;
            for (int i = 0; i < it; i++)
            {
                posicao += palavras[i].tam;
                posicao += 1;
            }
            cout << posicao;
        }

        while (k != tamanhoVetor)
        {
            k = it + 1;
            while (palavras[k].palavra != palavraBuscada & k < tamanhoVetor)
            {
                k++;
            }
            it = k;

            if (k != tamanhoVetor)
            {
                int posicao = 0;
                for (int i = 0; i < it; i++)
                {
                    posicao += palavras[i].tam;
                    posicao += 1;
                }
                cout << " " << posicao;
            }
        }
        cout << endl;
    }
    return 0;
}
