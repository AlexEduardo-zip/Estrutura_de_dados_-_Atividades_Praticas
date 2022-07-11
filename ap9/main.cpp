#include <iostream>
#include <string>
#include <cstdio>
#include <string.h>

using namespace std;

typedef char TipoItem;

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
    item = -1;
    esq = NULL;
    dir = NULL;
};

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(TipoItem item);
    void Caminha(int tipo);
    TipoItem Pesquisa(TipoItem chave);
    void Remove(TipoItem chave);
    void Limpa();
    void setprimeiro(int set);

private:
    void InsereRecursivo(TipoNo *&p, TipoItem item);
    void ApagaRecursivo(TipoNo *p);
    TipoItem PesquisaRecursivo(TipoNo *p, TipoItem chave);
    void RemoveRecursivo(TipoNo *&p, TipoItem chave);
    void Antecessor(TipoNo *q, TipoNo *&r);
    void PreOrdem(TipoNo *p);
    void InOrdem(TipoNo *p);
    void PosOrdem(TipoNo *p);
    int primeiro = 1;
    TipoNo *raiz;
};
ArvoreBinaria::ArvoreBinaria()
{
    raiz = NULL;
}
ArvoreBinaria::~ArvoreBinaria()
{
    Limpa();
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
TipoItem ArvoreBinaria::Pesquisa(TipoItem chave)
{
    return PesquisaRecursivo(raiz, chave);
}
TipoItem ArvoreBinaria::PesquisaRecursivo(TipoNo *no, TipoItem chave)
{
    TipoItem aux;
    if (no == NULL)
    {
        aux = -1; // Flag para item não presente
        return aux;
    }
    if (chave < no->item)
        return PesquisaRecursivo(no->esq, chave);
    else if (chave > no->item)
        return PesquisaRecursivo(no->dir, chave);
    else
        return no->item;
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
        if (item < p->item)
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}
void ArvoreBinaria::Remove(TipoItem chave)
{
    return RemoveRecursivo(raiz, chave);
}
void ArvoreBinaria::RemoveRecursivo(TipoNo *&no, TipoItem chave)
{
    TipoNo *aux;
    if (no == NULL)
    {
        throw("Item nao está presente");
    }
    if (chave < no->item)
        return RemoveRecursivo(no->esq, chave);
    else if (chave > no->item)
        return RemoveRecursivo(no->dir, chave);
    else
    {
        if (no->dir == NULL)
        {
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if (no->esq == NULL)
        {
            aux = no;
            no = no->dir;
            free(aux);
        }
        else
            Antecessor(no, no->esq);
    }
}
void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo *&r)
{
    if (r->dir != NULL)
    {
        Antecessor(q, r->dir);
        return;
    }
    q->item = r->item;
    q = r;
    r = r->esq;
    free(q);
}
void ArvoreBinaria::setprimeiro(int set)
{
    primeiro = set;
}
void ArvoreBinaria::PreOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        if (primeiro)
        {
            primeiro = 0;
            cout << p->item;
        }
        else
            cout << " " << p->item;
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}
void ArvoreBinaria::InOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        InOrdem(p->esq);
        if (primeiro)
        {
            primeiro = 0;
            cout << p->item;
        }
        else
            cout << " " << p->item;
        InOrdem(p->dir);
    }
}
void ArvoreBinaria::PosOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        if (primeiro)
        {
            primeiro = 0;
            cout << p->item;
        }
        else
            cout << " " << p->item;
    }
}
void ArvoreBinaria::Caminha(int tipo)
{
    if (tipo == 1)
    {
        this->PreOrdem(raiz);
    }
    else if (tipo == 2)
    {
        this->InOrdem(raiz);
    }
    else if (tipo == 3)
    {
        this->PosOrdem(raiz);
    };
};

int main()
{
    ArvoreBinaria ArvoreLetras;
    string comando;
    while (cin >> comando)
    {

        if (comando == "I")
        {
            TipoItem letra;
            cin >> letra;
            ArvoreLetras.Insere(letra);
            continue;
        }
        else if (comando == "P")
        {
            TipoItem letra;
            cin >> letra;
            if (ArvoreLetras.Pesquisa(letra) == -1)
            {
                cout << letra << " nao existe" << endl;
            }
            else
            {
                cout << letra << " existe" << endl;
            };
            continue;
        }
        else if (comando == "INFIXA")
        {
            ArvoreLetras.setprimeiro(1);
            ArvoreLetras.Caminha(2);
            cout << endl;
            continue;
        }
        else if (comando == "POSFIXA")
        {
            ArvoreLetras.setprimeiro(1);
            ArvoreLetras.Caminha(3);
            cout << endl;
            continue;
        }
        else if (comando == "PREFIXA")
        {
            ArvoreLetras.setprimeiro(1);
            ArvoreLetras.Caminha(1);
            cout << endl;
            continue;
        };
    };
    return 0;
}