#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;


const int tamanho =10;
const int caract =4;
void transposta(int matriz[caract][tamanho], int transposta[tamanho][caract]);
void multmatriz(int produto [caract][caract],int matriz[caract][tamanho], int transposta [tamanho][caract]);
void reconstrucao (int a[caract][caract] ,int b[caract],int c[caract]);
float similaridadeCos (int a[caract],int b[caract]);


int main(){
    int W[caract][caract],rostos[caract][tamanho],TRANS[tamanho][caract], teste[caract], resposta[caract];
    float resultado;
    for (int j=0;j<caract;j++){
        for (int i=0;i<caract;i++){
            W[i][j]=0;
        }
    }
    for (int j=0;j<tamanho;j++){
        for (int i=0;i<caract;i++){
            cout << "Informe os tracos do rosto "<< j+1 <<" :"<< endl;
            cin >> rostos[i][j];
        }
    }
    cout << "\nMatriz rostos:" << endl;
    for (int i = 0; i < caract; i++){
        for (int j = 0; j < tamanho; j++) {
            cout << setw(4) << rostos[i][j] << " ";
        }
        cout << endl;
    }
    transposta(rostos, TRANS);
    cout << "Matriz transposta:" << endl;
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < caract; j++) {
            cout << setw(4) << TRANS[i][j] << " ";
        }
        cout << endl;
    }
    multmatriz(W,rostos,TRANS);
    cout << "Matriz multiplicada:" << endl;
    for (int i = 0; i < caract; i++){
        for (int j = 0; j < caract; j++) {
            cout << setw(4) << W[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Insira o rosto que deseja que seja lembrado: "<< endl;
    for (int i=0; i<caract; i++){
        cin >> teste[i];
    }
    reconstrucao(W, teste , resposta);
    for (int j = 0; j < caract; j++){
            cout << resposta[j] << " ";
    }
    resultado = similaridadeCos (resposta,teste);
    cout << "\nsimilaridade por cosseno: " << resultado;
}

void transposta(int matriz[caract][tamanho], int transposta[tamanho][caract]){
    for (int j=0;j<tamanho;j++){
        for (int i=0;i<caract;i++){
            transposta[j][i]=matriz[i][j];
        }
    }
}

void multmatriz(int produto [caract][caract],int matriz[caract][(tamanho)], int transposta [(tamanho)][caract]){
    int a=0;
    for (int k=0;k<caract;k++){
        for (int i=k;i<caract;i++){
            for (int j=0;j<tamanho;j++){
                a=a+matriz[i][j]*transposta[j][i-k];
            }
            produto [i][i-k]=a;
            a=0;
        }
    }
    for (int k=1; k<caract; k++){
        for (int i=0; i<caract-k; i++){
            for (int j=0; j<tamanho; j++){
                a+=matriz [i][j]*transposta[j][i+k];
            }
            produto [i][i+k]=a;
            a=0;
        }
    }
}
void reconstrucao (int a[caract][caract] ,int b[caract],int c[caract]){
    for (int i = 0; i < caract; i++){
        c[i]=0;
        for (int j = 0; j < caract; j++){
            c[i]+=a[i][j]*b[j];
        }
    }
}
float similaridadeCos (int a[caract],int b[caract]){
    int x=0,y=0,z=0;
        for (int i = 0 ;i < caract; i++){
            z+=a[i]*b[i];
            x+=a[i]*a[i];
            y+=b[i]*b[i];
    }
    return z/(sqrt(x)*sqrt(y));
}