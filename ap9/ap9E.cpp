#include <iostream>
#include <string>

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
class Fila
{
public:
    Fila() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };
    virtual void Enfileira(TipoItem item) = 0;
    virtual TipoNo Desenfileira() = 0;
    virtual void Limpa() = 0;

protected:
    int tamanho;
};
class FilaArranjo : public Fila
{
public:
    FilaArranjo();
    void Enfileira(TipoItem item);
    TipoNo Desenfileira();
    void Limpa();

private:
    int frente;
    int tras;
    static const int MAXTAM = 100;
    TipoNo itens[MAXTAM];
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
TipoNo *FilaArranjo::Desenfileira()
{
    TipoNo aux;
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
    void CaminhaNivel();
    int tamanho = 0;
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
    tamanho = set;
}
void ArvoreBinaria::CaminhaNivel()
{
    FilaArranjo F; // fila de apontadores para nos
    TipoNo *p;
    int fila[1000];
    fila[tamanho] = raiz->item;
    tamanho++;
    while (tamanho > 0)
    {
        p = F.Desenfileira();
        if (p != NULL)
        {
            cout << p->item;
            F.Enfileira(p->esq->item);
            F.Enfileira(p->dir->item);
        }
    }
}
void ArvoreBinaria::Caminha(int tipo)
{
    CaminhaNivel();
};

int main()
{
    ArvoreBinaria ArvoreExpressao;
    cout << "cria";
    string comando;
    getline(std::cin, comando);
    cout << "pegou linha" << comando << endl;
    while (1)
    {
        cout << "here" << comando;
        for (int i = 0; i < comando.size(); i++)
        {
            if (comando[i] != ' ')
            {
                cout << "laço" << i << endl;
                ArvoreExpressao.Insere(comando[i]);
            }
        }
        ArvoreExpressao.Caminha(1);
        // if (comando == "I")
        // {
        //     TipoItem letra;
        //     cin >> letra;
        //     ArvoreExpressao.Insere(letra);
        //     continue;
        // }
        // else if (comando == "P")
        // {
        //     TipoItem letra;
        //     cin >> letra;
        //     if (ArvoreExpressao.Pesquisa(letra) == -1)
        //     {
        //         cout << letra << " nao existe" << endl;
        //     }
        //     else
        //     {
        //         cout << letra << " existe" << endl;
        //     };
        //     continue;
        // }
        // else if (comando == "INFIXA")
        // {
        //     ArvoreExpressao.setprimeiro(1);
        //     ArvoreExpressao.Caminha(2);
        //     cout << endl;
        //     continue;
        // }
        // else if (comando == "POSFIXA")
        // {
        //     ArvoreExpressao.setprimeiro(1);
        //     ArvoreExpressao.Caminha(3);
        //     cout << endl;
        //     continue;
        // }
        // else if (comando == "PREFIXA")
        // {
        //     ArvoreExpressao.setprimeiro(1);
        //     ArvoreExpressao.Caminha(1);
        //     cout << endl;
        //     continue;
        // };
    };
    return 0;
}