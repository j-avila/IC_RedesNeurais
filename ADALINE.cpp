#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double eta = 0.01;
double W[6][3] = {{-0.4410, 0.0369,  0.1774}, 
                  {-0.1722, -0.0568, -0.3871}, 
                  {0.4373,  0.0138,  0.5009}, 
                  {-0.2144, 0.3218,  -0.1554}, 
                  {0.0561,  0.4341,  -0.1156}, 
                  {-0.1280, 0.3057,  -0.3583}};
double X[6][9] = {{1,1,0,0,1,1,0,0,0},
                  {0,0,0,1,0,1,1,1,1},
                  {0,0,0,0,0,0,1,1,1},
                  {0,0,0,1,1,1,1,0,1},
                  {1,1,1,0,0,0,0,1,0},
                  {1,0,1,0,1,1,1,0,0}};
double T[3][9] = {{0,0,0,0,0,0,1,1,1},
                  {1,1,1,0,0,0,0,0,0},
                  {0,0,0,1,1,1,0,0,0}};
double erro[3][9];
double output[3][9];
double delta[6][3];
                  
void zerarMatrizes();
void resposta();
void calcularErro();
void deltaCalculo();
void corrigirW();

int main(){
    for (int epoca=0; epoca<300; epoca++){
        cout << epoca+1 << "a iteracao" << endl;
        zerarMatrizes();
        resposta();
        calcularErro();
        deltaCalculo();
        corrigirW();
    }
}

void zerarMatrizes(){
    for(int i=0; i<3; i++){
        for(int j=0; j<9; j++){
            output[i][j] = 0;
        }
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            delta[i][j] = 0;
        }
    }
}

void resposta(){
    cout << "RESPOSTA: " << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<9; j++){
            for(int k=0; k<6; k++){
                output[i][j] += W[k][i]*X[k][j];
            }
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<9; j++){
            cout << setw(10) << fixed << setprecision(4) << output[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void calcularErro(){
    cout << "Erro:" << endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<9; j++){
            erro[i][j]=T[i][j]-output[i][j];
            cout << setw(10) << fixed << setprecision(4) << erro[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void deltaCalculo(){
    cout << "Matriz DELTA:" << endl;
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<9; k++){
                delta[i][j] += X[i][k]*erro[j][k];
            }
        }
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            delta[i][j] *= eta;
            cout << setw(10) << fixed << setprecision(4) << delta[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void corrigirW(){
    cout << "W corrigida:" << endl;
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            W[i][j] += delta[i][j];
            cout << setw(10) << fixed << setprecision(4) << W[i][j];
        }
        cout << endl;
    }
    cout << endl;
}