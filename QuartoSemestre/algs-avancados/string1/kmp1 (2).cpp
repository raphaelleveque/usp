#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string txt;
string patt;

void preProcessamento(int *b, string patt){
	int tamanho = patt.length();
	int j = -1; 
	b[0] = -1;

	for (int i = 0; i < tamanho;){
		//printf("%d\n", j);
		while (j>=0 && patt[i] != patt[j]) { 
			j = b[j]; 
		}
		i++; j++;
		b[i] = j;  
	}

}

void kmp (int *b, string text, string pat){
	int tamanhotxt = txt.size();
	int tamp = patt.size();
	int c = 0;
	string saida;
	int i = 0, j = 0;
	while (i < tamanhotxt){    
		while (j >= 0 &&  text[i] != pat[j]) {
			j = b[j];
		}
		i++; j++;
		if (j == tamp) {
			c += 1;
			saida.append(to_string(i-j+1));
			saida.append(" ");
			j = b[j];    
		}
	}
	if (c == 0){
		cout << "Not Found" << endl;
	}else{
		cout << c << endl << saida << endl;
	}
}

int main()
{
	int array[100000];
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++)
	{
		cin >> txt >> patt;

		preProcessamento(array, patt);
		kmp(array, txt, patt);
		cout << endl;
		}
	
	return 0;
}