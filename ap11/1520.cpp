#include <iostream>

using namespace std;

int main()
{
    int acl;

    int i, j, inicio, fim, iter;

    while (cin >> iter)
    {
        int vet[101] = {};
        for (j = 0; j < iter; j++)
        {
            cin >> inicio >> fim;
            for (i = inicio; i <= fim; i++)
                ++vet[i];
        }

        acl = 0;
        cin >> j;

        if (vet[j])
        {
            for (i = 1; i < j; i++)
                acl += vet[i];
            cout << j << " found from " << acl << " to " << (acl + vet[i] - 1) << endl;
        }
        else
            cout << j << " not found" << endl;
    }
    return 0;
}