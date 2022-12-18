#include <bits/stdc++.h>
using namespace std;

string txt;
string patt;

void funcaopreprocessamento(int *b, string pat){
	int tamp = pat.length();
	b[0] = -1;

	for (int i = 0, j = -1; i < tamp; i++, j++){
		while (j>=0 && pat[i] != pat[j]) {
			j = b[j]; 
		}
		b[i] = j;     
	}

}

void kmp (int *b, string text, string pat){
	int tamanho = txt.size();
	int tamanhopath = patt.size();
	int c = 0;
	string saida;
	int i = 0, j = 0;
	while (i < tamanho){   
		while (j >= 0 &&  text[i] != pat[j]) {
			j = b[j];
		}
		i++; j++;
		if (j == tamanhopath) {
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
	int i = 0;
	while (i < casos) {
		cin >> txt;
		cin >> patt;
		funcaopreprocessamento(array, patt);
		kmp(array, txt, patt);
		cout << endl;
		}
	
	return 0;
}