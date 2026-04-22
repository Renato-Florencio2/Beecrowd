//https://judge.beecrowd.com/pt/problems/view/1069

/*

João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". Ele deve excluir todas as
particulas de areia "." do processo e a cada retirada de diamante, novos diamantes poderão se formar. Se ele tem como
uma entrada .<...<<..>>....>....>>>., três diamantes são formados. O primeiro é retirado de <..>, resultando 
.<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando .<.......>....>>>. O terceiro diamante é então
retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.
Entrada

Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é um caso de teste
que contém até 1000 caracteres, incluindo "<,>, ."
Saída

Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.
Exemplo de Entrada

2
<..><.<..>>
<<<..<......<<<<....>
	
Exemplo de Saída
3
1

*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int casos;
    cin>>casos;
    while(casos--){
        string st;
        cin>>st;
        
        unordered_map<string, int> mp;
        for(auto i:st){
            if(i == '<') mp["abre"]++;
            else if(i == '>'){
                if(mp["abre"] >= mp["fecha"]+1){
                    mp["total"]++;
                    mp["abre"]--;
                }
            }
        }
        cout<<mp["total"]<<"\n";
    }

    return 0;
}