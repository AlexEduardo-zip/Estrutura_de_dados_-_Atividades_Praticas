#include <iostream>
#include <string>

using namespace std;

typedef int TipoChave; // TipoChave é um inteiro

class TipoItem
{
public:
    TipoItem();
    TipoItem(TipoChave c);
    void SetChave(TipoChave c);
    TipoChave GetChave();
    void Imprime();

private:
    TipoChave chave;
    // outros membros
};

TipoItem::TipoItem()
{
    chave = -1; // indica um item vazio
}
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

class TipoNo
{
public:
    TipoNo();

private:
    TipoItem item;
    TipoNo *esq;
    TipoNo *dir;
    friend class ArvoreBinaria;
};

TipoNo::TipoNo()
{
    item.SetChave(-1);
    esq = NULL;
    dir = NULL;
}

class Fila
{
public:
    Fila() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };
    virtual void Enfileira(TipoItem item) = 0;
    virtual TipoItem Desenfileira() = 0;
    virtual void Limpa() = 0;

protected:
    int tamanho;
};

class FilaArranjo : public Fila
{
public:
    FilaArranjo();
    void Enfileira(TipoItem item);
    TipoItem Desenfileira();
    void Limpa();

private:
    int frente;
    int tras;
    static const int MAXTAM = 8;
    TipoItem itens[MAXTAM];
};

FilaArranjo::FilaArranjo() : Fila()
{
    frente = 0;
    tras = 0;
}

void FilaArranjo::Enfileira(TipoItem item)
{
    if (tamanho == MAXTAM)
        throw "Fila Cheia!";
    itens[tras] = item;
    // fila circular
    tras = (tras + 1) % MAXTAM;
    tamanho++;
}

TipoItem FilaArranjo::Desenfileira()
{
    TipoItem aux;
    if (tamanho == 0)
        throw "Fila está vazia!";
    aux = itens[frente];
    // fila circular
    frente = (frente + 1) % MAXTAM;
    tamanho--;
    return aux;
}

void FilaArranjo::Limpa()
{
    frente = 0;
    tras = 0;
    tamanho = 0;
}

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(TipoItem item);
    void CaminhaNivel();
    void Limpa();

private:
    void InsereRecursivo(TipoNo *p, TipoItem item);
    void ApagaRecursivo(TipoNo *p);
    TipoNo *raiz;
};

ArvoreBinaria::ArvoreBinaria()
{
    raiz = NULL;
}
void ArvoreBinaria::Limpa()
{
    ApagaRecursivo(raiz);
    raiz = NULL;
}
void ArvoreBinaria::ApagaRecursivo(TipoNo *p)
{
    if (p != NULL)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

ArvoreBinaria::~ArvoreBinaria()
{
    Limpa();
}

void ArvoreBinaria::Insere(TipoItem item)
{
    InsereRecursivo(raiz, item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo *&p, TipoItem item)
{
    if (p == NULL)
    {
        p = new TipoNo();
        p->item = item;
    }
    else
    {
        if (item.GetChave() < p->item.GetChave())
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void ArvoreBinaria::CaminhaNivel()
{
    FilaArranjo F; // fila de apontadores para nos
    TipoNo *p;
    F.Enfileira(raiz->item);
    while (!F.Vazia())
    {
        p->item = F.Desenfileira();
        if (p != NULL)
        {
            p->item.Imprime();
            F.Enfileira(p->esq->item);
            F.Enfileira(p->dir->item);
        }
    }
}

int main()
{
    int cases;
    cin >> cases;
    cout << "cases" << cases << endl;
    for (int i = 0; i < cases; i++)
    {
        int tamanho;
        cin >> tamanho;
        cout << "tamanho " << tamanho << endl;
        int conteudoArvore[tamanho];
        ArvoreBinaria Arvore;
        for (int i = 0; i < tamanho; i++)
        {
            string dados;
            cin >> dados;
            conteudoArvore[i] = dados[i];
            cout << "conteudo arvore " << conteudoArvore[i] << endl;
            Arvore.Insere(conteudoArvore[i]);
        }
        cout << "passou";
        Arvore.CaminhaNivel();
    }
    return 0;
}