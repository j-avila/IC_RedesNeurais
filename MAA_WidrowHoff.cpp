#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const double eta = 0.15;
double X[4][2] = {{-1,1},{-1,-1},{1,-1},{-1,1}};
double W[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
double erro[4][2];
double output[4][2];
double delta[4][4];

void zerarMatrizes();
void resposta();
void calcularErro();
void deltaCalculo();
void corrigirW();

int main(){
    for (int epoca =0; epoca<30; epoca++){
        cout << epoca+1 << "a iteracao" << endl;
        zerarMatrizes();
        resposta();
        calcularErro();
        deltaCalculo();
        corrigirW();
    }
}

void zerarMatrizes(){
    for (int i=0; i<4; i++){
        for (int j=0; j<2; j++){
            output[i][j]=0;
        }
    }

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            delta[i][j]=0;
        }
    }
}

void resposta(){
    cout << "Resposta:" << endl;
    for (int i=0; i<4; i++){
        for (int k=0; k<2; k++){
            for (int j=0; j<4; j++){
                output[i][k]+=W[i][j]*X[j][k];
            }
        }
    }

    for(int i=0; i<4; i++){
        for(int k=0; k<2; k++){
            cout << setw(10) << fixed << setprecision(3) << output[i][k];
        }
        cout << endl;
    }
    cout << endl;
}

void calcularErro(){
    cout << "Erro:" << endl;
    for (int i=0; i<4; i++){
        for (int k=0; k<2; k++){
            erro[i][k]=X[i][k]-output[i][k];
            cout << setw(10) << fixed << setprecision(3) << erro[i][k];
        }
        cout << endl;
    }
    cout << endl;
}

void deltaCalculo(){
    cout << "Matriz Delta:" << endl;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            for (int k=0; k<2; k++){
                delta[i][j] += erro[i][k]*X[j][k];
            }
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            delta[i][j] *= eta;
            cout << setw(10) << fixed << setprecision(3) << delta[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void corrigirW(){
    cout << "W corrigida" << endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            W[i][j] += delta[i][j];
            cout << setw(10) << fixed << setprecision(3) << W[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
