#include <iostream>
#include <vector>

using namespace std;


bool Verificacao(std::vector<std::vector<int>> Tabuleiro, int Linha, int Coluna){

    int ii;

    for(ii=0; ii<Tabuleiro.size(); ii++){

        if(Tabuleiro[Coluna][ii] == 1){
            return false;
        }
        if(Tabuleiro[ii][Linha] == 1){
            return false;
        }
        // Diagonal
        if( (Coluna-ii >= 0) && (Linha+ii < Tabuleiro.size()) && Tabuleiro[Coluna-ii][Linha+ii] == 1){
            return false;
        }

        if((Linha-ii >= 0) && (Coluna+ii < Tabuleiro.size()) && Tabuleiro[Coluna+ii][Linha-ii] == 1 ){
            return false;
        }

        if((Coluna+ii) < Tabuleiro.size() && (Linha+ii) < Tabuleiro.size() && Tabuleiro[Coluna+ii][Linha+ii] == 1 ){
            return false;
        }

        if((Coluna-ii) >= 0 && (Linha-ii) >= 0 && (Tabuleiro[Coluna-ii][Linha-ii] == 1)){
            return false;
        }
    }

    return true;
}

void ImpressaoTabuleiro(std::vector<std::vector<int>> Tabuleiro){

    int ii, jj;

    for(ii=0; ii<Tabuleiro.size(); ii++){
        for(jj=0; jj<Tabuleiro.size(); jj++){

            cout << Tabuleiro[ii][jj] << " ";

        }
        cout << endl;
    }
}

int BTNRainhas(std::vector<std::vector<int>>& Tabuleiro, int TamTabuleiro, int ColunaVerificar){

    int ii, Valor;

    if(ColunaVerificar == TamTabuleiro){
       ImpressaoTabuleiro(Tabuleiro);

       return 1;
    }

    for(ii=0; ii<TamTabuleiro; ii++){
        if(Verificacao(Tabuleiro, ii, ColunaVerificar)){

            Tabuleiro[ColunaVerificar][ii] = 1;

            Valor = BTNRainhas(Tabuleiro, TamTabuleiro, ColunaVerificar + 1);

            if(Valor == 0){
                Tabuleiro[ColunaVerificar][ii] = 0;
            }

            else{
                return 1;
            }
        }
    }

    return 0;
}


void GeraTabuleiro(std::vector<std::vector<int>>& Tabuleiro, int TamTabuleiro){

    int ii, jj;

    for(ii=0; ii<TamTabuleiro; ii++){
        for(jj=0; jj<TamTabuleiro; jj++){
            Tabuleiro[ii][jj] = 0;
        }
    }
}

int main(){

    cout << "Lista 06 - Questao 02 - Letra b" << endl;

    int TamTabuleiro = 5;

    std::vector<std::vector<int>> Tabuleiro(TamTabuleiro,std::vector<int>(TamTabuleiro));

    GeraTabuleiro(Tabuleiro, TamTabuleiro);

    int Resultado;

    BTNRainhas(Tabuleiro, TamTabuleiro, 0);

}
