#include <iostream>
#include <string>

#define MAXTAM 1000;

class TipoCelula
{
public:
    TipoCelula();

private:
    int item;
    TipoCelula *prox;
    friend class FilaEncadeada;
};
TipoCelula::TipoCelula()
{
    item = -1;
    prox = NULL;
}

class Fila
{
public:
    Fila() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };
    virtual void Enfileira(int item) = 0;
    virtual int Desenfileira() = 0;
    virtual void Limpa() = 0;

protected:
    int tamanho;
};

class FilaEncadeada : public Fila
{
public:
    FilaEncadeada();
    virtual ~FilaEncadeada();
    void Enfileira(int item);
    int Desenfileira();
    void Limpa();

private:
    TipoCelula *frente;
    TipoCelula *tras;
};

FilaEncadeada::FilaEncadeada() : Fila()
{
    frente = new TipoCelula; // Célula cabeça;
    tras = frente;
}
FilaEncadeada::~FilaEncadeada()
{
    Limpa();
    delete frente;
}
void FilaEncadeada::Enfileira(int item)
{
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    tras->prox = nova;
    tras = nova;
    tamanho++;
}

int FilaEncadeada::Desenfileira()
{
    TipoCelula *p;
    int aux;
    if (tamanho == 0)
        throw "Fila está vazia!";
    aux = frente->prox->item;
    p = frente;
    frente = frente->prox;
    delete p;
    tamanho--;
    return aux;
}

void FilaEncadeada::Limpa()
{
    TipoCelula *p;
    p = frente->prox;
    while (p != NULL)
    {
        frente->prox = p->prox;
        delete p;
        p = frente->prox;
    }
    tamanho = 0;
    tras = frente;
}

class TipoNo
{
public:
    TipoNo();
    int item;
    TipoNo *esq;
    TipoNo *dir;
    friend class ArvoreBinaria;
};

TipoNo::TipoNo()
{
    item = -1;
    esq = NULL;
    dir = NULL;
}

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(int item);
    void CaminhaNivel(TipoNo *&p);
    void Limpa();
    void InsereRecursivo(TipoNo *&p, int indice);
    void ApagaRecursivo(TipoNo *p);
    TipoNo *raiz;
};

ArvoreBinaria::ArvoreBinaria()
{
    raiz = new TipoNo();
    raiz->item = -1;
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

void ArvoreBinaria::Insere(int item)
{
    InsereRecursivo(raiz, item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo *&p, int indice)
{
    if (p->item == -1 || p == NULL)
    {
        p = new TipoNo();
        p->item = indice;
    }
    else
    {
        if (indice < p->item)
            InsereRecursivo(p->esq, indice);
        else
            InsereRecursivo(p->dir, indice);
    }
}

void ArvoreBinaria::CaminhaNivel(TipoNo *&p)
{
    FilaEncadeada F; // fila de apontadores para nos
    F.Enfileira(raiz->item);
    while (!F.Vazia())
    {
        p->item = F.Desenfileira();
        if (p != NULL)
        {
            std::cout << p->item;
            F.Enfileira(p->esq->item);
            F.Enfileira(p->dir->item);
        }
    }
}

int main()
{
    int casos;
    std::cin >> casos;
    std::cout << "casos " << casos << std::endl;
    Arvore = new ArvoreBinaria;
    for (int i = 0; i < casos; i++)
    {
        int tamanho;
        std::cin >> tamanho;
        std::cout << "tamanho " << tamanho << std::endl;
        int conteudoArvore[tamanho];

        for (int i = 0; i < tamanho; i++)
        {
            int dados[tamanho];
            std::cin >> dados[i];
            conteudoArvore[i] = dados[i];
            std::cout << "conteudo arvore " << conteudoArvore[i] << std::endl;
            int indice = conteudoArvore[i];
            Arvore.Insere(indice);
            std::cout << "inserido " << Arvore.raiz->item;
        }

        Arvore.CaminhaNivel(Arvore.raiz);
    }
    return 0;
}