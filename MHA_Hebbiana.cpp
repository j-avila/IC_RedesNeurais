#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double X[4][5] = {{1,-1,-1,1,-1},{1,-1,-1,-1,1},{1,1,-1,-1,-1},{-1,-1,-1,1,-1}};
double T[3][5] = {{1,-1,-1,1,-1},{1,1,-1,-1,1},{-1,-1,1,1,1}};
double W[4][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int xRosto[4] = {{1},{1},{1},{-1}};
int xNome[3] = {{1},{1},{-1}};

void calcularW();
void lembranca(int a[3]);
float similaridadeCos(int a[3], int b[3]);

int main(){
    int resposta[3] = {{0},{0},{0}};
    calcularW();
    lembranca(resposta);
    cout << endl << "COS: " << similaridadeCos(xNome, resposta);
    return 0;
}

void calcularW(){
cout << "Matriz W: " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 5; k++) {
                W[i][j] += X[i][k] * T[j][k];
            }
        }
    }
    for(int i=0; i<4; i++){
        for(int k=0; k<3; k++){
            cout << setw(10) << fixed << setprecision(3) << W[i][k];
        }
        cout << endl;
    }
    cout << endl;
}

void lembranca(int a[3]){
    cout << "Resposta: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            a[i] += W[j][i] * xRosto[j];
        }
        cout << a[i] << endl;
    }
}

float similaridadeCos(int a[3],int b[3]){
    int x=0,y=0,z=0;
        for (int i = 0 ;i < 3; i++){
            z+=a[i]*b[i];
            x+=a[i]*a[i];
            y+=b[i]*b[i];
    }
    return z/(sqrt(x)*sqrt(y));
}