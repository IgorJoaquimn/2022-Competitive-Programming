#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

#define mp(x, y) std::make_pair(int(x), int(y))

#define NT 0
#define MANTER 1
#define PASSAR 2

int transformaChar(char c){
    if (c == 'A') return 0;
    else if (c == 'D') return 9;
    else if (c == 'Q') return 10;
    else if (c == 'J') return 11;
    else if (c == 'K') return 12;
    else return ((int)c)-49;
}

int main() {
    int n,k, vencedor = 0;
    char jogo[4];
    cin >> n >> k;
    int coringa[n];
    int jogos[n][13];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 13; j++){
            jogos[i][j] = 0;
        }
        cin >> jogo;
        if (i == k-1) coringa[i] = MANTER;
        else coringa[i] = NT;
        for (int j = 0; j < 4; j++){
            jogos[i][transformaChar(jogo[j])]++;
        }
        if (jogos[i][transformaChar(jogo[0])] == 4 && vencedor == 0 && coringa[i] == NT){
            vencedor = i+1;
        }
    }
    int jogador = k-1, proximoJogador;
    bool passou;
    while (vencedor == 0){
        passou = false;
        int cartasDuplas[2] = {-1,-1};
        if (jogador != n-1){
            proximoJogador = jogador+1;
        } else {
            proximoJogador = 0;
        }
        if (coringa[jogador] == PASSAR){
            for (int i = 0; i < 13; i++){
                if (jogos[jogador][i] == 4) vencedor = jogador+1;
            }
            coringa[proximoJogador] = MANTER;
            coringa[jogador] = NT;
            jogador = proximoJogador;
            continue;
        } else if (coringa[jogador] == MANTER){
            coringa[jogador] = PASSAR;
        }
        for (int i = 0; i < 13; i++){
            if (jogos[jogador][i] == 1){
                if (passou) continue;
                jogos[proximoJogador][i]++;
                jogos[jogador][i]--;
                passou = true;
            } else if (jogos[jogador][i] == 2){
                if (passou) continue;
                if (cartasDuplas[0] == -1) cartasDuplas[0] = i;
                else cartasDuplas[1] = i;
            } else if (jogos[jogador][i] == 3) {
                cartasDuplas[1] = i;
            } else if (jogos[jogador][i] == 4){
                if (coringa[jogador] == NT){
                    vencedor = jogador+1;
                } else {
                    jogos[proximoJogador][i]++;
                    jogos[jogador][i]--;
                }
                break;
            }
        }
        if (cartasDuplas[0] != -1 && cartasDuplas[1] != -1 && !passou){
            jogos[proximoJogador][cartasDuplas[0]]++;
            jogos[jogador][cartasDuplas[0]]--;
        }
        jogador = proximoJogador;
    }
    cout << vencedor << endl;
    return 0;
}