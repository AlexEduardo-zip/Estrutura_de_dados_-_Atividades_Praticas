#include <iostream>
#include <string>

using namespace std;

typedef int TipoChave;

/////////////////////////////
class TipoItem
{
public:
    TipoItem();
    TipoItem(TipoChave c);
    void SetChave(TipoChave c);
    TipoChave GetChave();
    void Imprime();
    bool Vazio();

private:
    TipoChave chave;
    // outros membros
};
bool TipoItem::Vazio()
{
    return chave;
}
TipoItem::TipoItem()
{
    chave = -1;
} // indica um item vazio
TipoItem::TipoItem(TipoChave c)
{
    chave = c;
}
void TipoItem::SetChave(TipoChave c)
{
    chave = c;
}
TipoChave TipoItem::GetChave()
{
    return chave;
}
void TipoItem::Imprime()
{
    printf("%d ", chave);
}

///////////////////////////////
class TipoCelula
{
public:
    TipoCelula();

private:
    TipoItem item;
    TipoCelula *prox;
    friend class ListaEncadeada;
};

TipoCelula::TipoCelula()
{
    item.SetChave(-1);
    prox = NULL;
}

///////////////////////////////////////////
class ListaEncadeada
{
public:
    ListaEncadeada();
    ~ListaEncadeada();
    TipoItem GetItem(int pos);
    void SetItem(TipoItem item, int pos);
    void InsereInicio(TipoItem item);
    void InsereFinal(TipoItem item);
    void InserePosicao(TipoItem item, int pos);
    TipoItem RemoveInicio();
    TipoItem RemoveFinal();
    TipoItem RemovePosicao(int pos);
    TipoItem RemoveItem(TipoChave c);
    TipoItem Pesquisa(TipoChave c);
    void Imprime();
    void Limpa();
    int getTamanho();

private:
    TipoCelula *primeiro;
    TipoCelula *ultimo;
    TipoCelula *Posiciona(int pos, bool antes);
    int tamanho = 0;
};

ListaEncadeada::ListaEncadeada()
{
    primeiro = new TipoCelula();
    ultimo = primeiro;
}
ListaEncadeada::~ListaEncadeada()
{
    Limpa();
    delete primeiro;
}
int ListaEncadeada::getTamanho()
{
    return tamanho;
}
void ListaEncadeada::InsereInicio(TipoItem item)
{
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;
    if (nova->prox == NULL)
        ultimo = nova;
};

TipoItem ListaEncadeada::RemovePosicao(int pos)
{
    TipoItem aux;
    TipoCelula *p, *q;
    if (tamanho == 0)
        cout << "ERRO: Lista vazia!";
    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q;
    if (p->prox == NULL)
        ultimo = p;
    return aux;
}
void ListaEncadeada::Limpa()
{
    TipoCelula *p;
    p = primeiro->prox;
    while (p != NULL)
    {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
};
void ListaEncadeada::Imprime()
{
    TipoCelula *p;
    p = primeiro->prox;
    while (p != NULL)
    {
        p->item.Imprime();
        p = p->prox;
    }
    // printf("\n");
};
// TipoItem ListaEncadeada::Pesquisa(TipoChave c)
// {
//     TipoItem aux;
//     TipoCelula *p;
//     if (tamanho == 0)
//         cout << "ERRO: Lista vazia!";
//     p = primeiro->prox;
//     aux.SetChave(-1);
//     while (p != NULL)
//     {
//         if (p->item.GetChave() == c)
//         {
//             aux = p->item;
//             break;
//         }
//         p = p->prox;
//     }
//     return aux;
// };
TipoItem ListaEncadeada::Pesquisa(TipoChave c)
{
    TipoItem aux; // construtor seta o item para -1;
    TipoCelula *p;
    p = primeiro->prox;
    while (p != NULL)
    {
        if (p->item.GetChave() == c)
        {
            aux = p->item;
            break;
        }
        p = p->prox;
    }
    return aux;
};
TipoItem ListaEncadeada::RemoveFinal()
{
    TipoItem aux;
    TipoCelula *p;
    if (tamanho == 0)
        cout << "ERRO: Lista vazia!";
    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);
    p->prox = NULL;
    tamanho--;
    aux = ultimo->item;
    delete ultimo;
    ultimo = p;
    return aux;
}
TipoItem ListaEncadeada::RemoveInicio()
{
    ;
    TipoItem aux;
    TipoCelula *p;
    if (tamanho == 0)
        cout << "ERRO: Lista vazia!";
    p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;
    if (primeiro->prox == NULL)
        ultimo = primeiro;
    aux = p->item;
    delete p;
    return aux;
}
void ListaEncadeada::InserePosicao(TipoItem item, int pos)
{
    TipoCelula *p, *nova;
    p = Posiciona(pos, true); // posiciona na célula anterior
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;
    if (nova->prox == NULL)
        ultimo = nova;
};

TipoCelula *ListaEncadeada::Posiciona(int pos, bool antes = false)
{
    TipoCelula *p;
    int i;
    if ((pos > tamanho) || (pos <= 0))
        cout << "ERRO: Posicao Invalida!";
    // Posiciona na célula anterior a desejada
    p = primeiro;
    for (i = 1; i < pos; i++)
    {
        p = p->prox;
    }
    // vai para a próxima
    // se antes for false
    if (!antes)
        p = p->prox;
    return p;
}
TipoItem ListaEncadeada::GetItem(int pos)
{
    TipoCelula *p;
    p = Posiciona(pos);
    return p->item;
}
void ListaEncadeada::SetItem(TipoItem item, int pos)
{
    TipoCelula *p;
    p = Posiciona(pos);
    p->item = item;
}
void ListaEncadeada::InsereFinal(TipoItem item)
{
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = NULL;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
};
TipoItem ListaEncadeada::RemoveItem(TipoChave c)
{
    TipoItem aux;
    TipoCelula *p, *q;
    // Posiociona p na célula anterior ao item procurado
    p = primeiro;
    while ((p->prox != NULL) && (p->prox->item.GetChave() != c))
        p = p->prox;
    // remove a célula contendo o item, retornando-o
    if (p->prox == NULL)
        cout << "Erro: item não está presente";
    else
    {
        q = p->prox;
        p->prox = q->prox;
        aux = q->item;
        delete q;
        tamanho--;
        if (p->prox == NULL)
            ultimo = p;
    }
    return aux;
};

/////////////////////////////////////////
class Hash_LE
{
public:
    Hash_LE();
    TipoItem Pesquisa(TipoChave chave);
    void Insere(TipoItem item);
    void Remove(TipoChave chave);
    void SetM(int iM);
    int GetM();
    void ImprimeTabela();

private:
    int m;
    static const int M = 100;
    int Hash(TipoChave Chave);
    ListaEncadeada Tabela[M];
};
Hash_LE::Hash_LE()
{
}
void Hash_LE::ImprimeTabela()
{
    for (int i = 0; i < m; i++)
    {
        if (Tabela[i].getTamanho() == 0)
        {
            cout << i << " -> \\";
        }
        else
        {
            cout << i;
            int tamanho = Tabela[i].getTamanho();
            for (int j = 1; j <= tamanho + 1; j++)
            {
                if (j == tamanho + 1)
                {
                    cout << " -> \\";
                }
                else
                {
                    cout << " -> " << Tabela[i].GetItem(j).GetChave();
                }
            }
        }
        // Tabela[i].Imprime();
        cout << endl;
    }
}

int Hash_LE::Hash(TipoChave Chave)
{
    // cout << Chave << m << endl;
    return (Chave % m);
}
void Hash_LE::SetM(int iM)
{
    m = iM;
}

int Hash_LE::GetM()
{
    return m;
}
TipoItem Hash_LE::Pesquisa(TipoChave chave)
{
    int pos;
    TipoItem item;
    pos = Hash(chave);
    item = Tabela[pos].Pesquisa(chave);
    return item;
}
// Retorna o item encontrado ou um item vazio
// (chave == -1) se não estiver presente

void Hash_LE::Insere(TipoItem item)
{
    TipoItem aux;
    int pos;
    aux = Pesquisa(item.GetChave());
    if (!aux.Vazio())
        cout << ("Erro: Item já está presente");
    pos = Hash(item.GetChave());
    Tabela[pos].InsereFinal(item);
}

void Hash_LE::Remove(TipoChave chave)
{
    int pos;
    pos = Hash(chave);
    Tabela[pos].RemoveItem(chave);
}

int main()
{
    int casos;
    cin >> casos;

    for (int i = 0; i < casos; i++)
    {
        int M;
        int qNumeros;
        cin >> M;
        cin >> qNumeros;
        Hash_LE tabelaHash;
        tabelaHash.SetM(M);
        for (int i = 0; i < qNumeros; i++)
        {
            TipoItem numero;
            int indice;
            cin >> indice;
            numero.SetChave(indice);
            tabelaHash.Insere(numero);
        }
        tabelaHash.ImprimeTabela();
        if (i == casos - 1)
        {
        }
        else
            cout << endl;
    }
    return 0;
}