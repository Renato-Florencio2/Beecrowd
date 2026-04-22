// https://judge.beecrowd.com/pt/problems/view/1259

/*

Considerando a entrada de valores inteiros não negativos, ordene estes valores segundo o seguinte critério:

    Primeiro os Pares
    Depois os Ímpares

Sendo que deverão ser apresentados os pares em ordem crescente e depois os ímpares em ordem decrescente.
Entrada

A primeira linha de entrada contém um único inteiro positivo N (1 < N <= 105) Este é o número de linhas de entrada que
vem logo a seguir. As próximas N linhas conterão, cada uma delas, um valor inteiro não negativo.
Saída

Apresente todos os valores lidos na entrada segundo a ordem apresentada acima. Cada número deve ser impresso em uma
linha, conforme exemplo abaixo.
Exemplo de Entrada

10
4
32
34
543
3456
654
567
87
6789
98
	
Exemplo de Saída
4
32
34
98
654
3456
6789
567
543
87 

*/

#include <bits/stdc++.h>
using namespace std;
int main(){

    int nuns;
    cin>>nuns;

    vector<int> vt;
    for(int i = 0 ; i < nuns ; i++){
        int n;
        cin>>n;
        vt.push_back(n);
    }

    sort(vt.begin(), vt.end(), [](int a, int b){
        if(a % 2 == 0 && b % 2 == 0) return a < b;
        else if(a % 2 != 0 && b % 2 != 0) return a > b;
        else return a % 2 == 0;
    });

    for(int i:vt) cout<<i<<"\n";

    return 0;
}