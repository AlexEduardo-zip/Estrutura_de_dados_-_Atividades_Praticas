#include <iostream>
#include <string>

using namespace std;
struct paises
{
    string nome;
    int mOuro;
    int mPrata;
    int mBronze;
};

int main()
{
    int qPaises;
    cin >> qPaises;
    paises paisesArray[qPaises];
    for (int i = 0; i < qPaises; i++)
    {
        cin >> paisesArray[i].nome;
        cin >> paisesArray[i].mOuro;
        cin >> paisesArray[i].mPrata;
        cin >> paisesArray[i].mBronze;
    }
    // for (int i = 0; i < qPaises; i++)
    // {
    //     cout << paisesArray[i].nome << paisesArray[i].mOuro << paisesArray[i].mPrata << paisesArray[i].mBronze << endl;
    // }
    int i, j;
    paises aux;
    for (i = 1; i < qPaises; i++)
    {
        aux = paisesArray[i];
        j = i - 1;
        while ((j >= 0) && (aux.nome > paisesArray[j].nome))
        {
            paisesArray[j + 1] = paisesArray[j];
            j--;
        }
        paisesArray[j + 1] = aux;
    }
    for (i = 1; i < qPaises; i++)
    {
        aux = paisesArray[i];
        j = i - 1;
        while ((j >= 0) && (aux.mBronze < paisesArray[j].mBronze))
        {
            paisesArray[j + 1] = paisesArray[j];
            j--;
        }
        paisesArray[j + 1] = aux;
    }
    for (i = 1; i < qPaises; i++)
    {
        aux = paisesArray[i];
        j = i - 1;
        while ((j >= 0) && (aux.mPrata < paisesArray[j].mPrata))
        {
            paisesArray[j + 1] = paisesArray[j];
            j--;
        }
        paisesArray[j + 1] = aux;
    }
    for (i = 1; i < qPaises; i++)
    {
        aux = paisesArray[i];
        j = i - 1;
        while ((j >= 0) && (aux.mOuro < paisesArray[j].mOuro))
        {
            paisesArray[j + 1] = paisesArray[j];
            j--;
        }
        paisesArray[j + 1] = aux;
    }
    for (int i = qPaises - 1; i >= 0; i--)
    {
        cout << paisesArray[i].nome << " " << paisesArray[i].mOuro << " " << paisesArray[i].mPrata << " " << paisesArray[i].mBronze << endl;
    }

    return 0;
}