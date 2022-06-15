#include <iostream>
#include <strings.h>
#include <string.h>
#include <math.h>

using namespace std;

struct no
{
    string nome;
    struct no *proximo = nullptr;
} typedef no;

class lista_circular
{
private:
    no *head = nullptr;
    no *end = nullptr;

public:
    lista_circular(string);
    no *insertNodeEnd(string);
    void printNodes();
};

lista_circular::lista_circular(string nome)
{
    head = new no;
    head->proximo = head;
    head->nome = nome;
    end = head;
}

no *lista_circular::insertNodeEnd(string nome)
{
    auto new_node = new no;
    new_node->proximo = end->proximo;
    new_node->nome = nome;

    end->proximo = new_node;
    end = end->proximo;
    return new_node;
}

int main()
{

    int pessoas = 0;
    float lGarrafa, lCuia;

    cin >> pessoas >> lGarrafa >> lCuia;

    string nomes[pessoas];

    for (int i = 0; i < pessoas; i++)
    {
        cin >> nomes[i];
    }

    lista_circular roda_do_mate(nomes[0]);

    for (int i = 1; i < pessoas; i++)
    {
        roda_do_mate.insertNodeEnd(nomes[i]);
    }

    float aux = lGarrafa;
    int cont = -1;
    while (1)
    {
        cont++;
        if (aux - lCuia <= 0)
        {
            break;
        }
        else
        {
            aux = round((aux - lCuia) * 10.0) / 10.0;
        }
    }

    // saida
    cout << nomes[cont % pessoas] << " " << aux << endl;

    return EXIT_SUCCESS;
}