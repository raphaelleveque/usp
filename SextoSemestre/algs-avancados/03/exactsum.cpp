#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> livros(10000);

int main()
{
    long long N, M;

    while (cin >> N)
    {
        for (long long i = 0; i < N; ++i)
            cin >> livros[i];

        sort(livros.begin(), livros.begin() + N);

        cin >> M;

        long long i = 0, j = N - 1;
        long long bI, bJ;
        for (; i < j;)
        {
            if (livros[i] + livros[j] < M)
                ++i;
            else if (livros[i] + livros[j] == M)
            {
                bI = i;
                bJ = j;
                ++i;
                --j;
            }
            else
                --j;
        }

        cout << "Peter deve comprar os livros com preços " << livros[bI] << " e " << livros[bJ] << ".\n\n";
    }
}
