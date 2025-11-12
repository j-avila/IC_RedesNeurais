#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int tamanho = 5;
const int caract = 4;

// Cálculo da similaridade cosseno entre dois vetores
float cosseno(int a[caract], int b[caract]) {
    float dot = 0, normA = 0, normB = 0;
    for (int i = 0; i < caract; i++) {
        dot += a[i] * b[i];
        normA += a[i] * a[i];
        normB += b[i] * b[i];
    }
    return dot / (sqrt(normA) * sqrt(normB) + 1e-8); // evita divisão por zero
}

// Função softmax para vetor de tamanho fixo
void softmax(float entrada[tamanho], float saida[tamanho], float beta) {
    float max_val = entrada[0];
    for (int i = 1; i < tamanho; i++) if (entrada[i] > max_val) max_val = entrada[i];

    float soma_exp = 0;
    for (int i = 0; i < tamanho; i++) {
        saida[i] = exp(beta * (entrada[i] - max_val));
        soma_exp += saida[i];
    }
    for (int i = 0; i < tamanho; i++) {
        saida[i] /= soma_exp;
    }
}

// Leitura diferenciável da memória (atenção suave)
void leitura_ntm(int rosto[caract][tamanho], int chave[caract], float beta, float saida[caract]) {
    float similaridade[tamanho];
    float pesos[tamanho];

    // Passo 1: calcular similaridade entre chave e cada vetor da memória
    for (int i = 0; i < tamanho; i++) {
        int vetor_memoria[caract];
        for (int j = 0; j < caract; j++) {
            vetor_memoria[j] = rosto[j][i];
        }
        similaridade[i] = cosseno(chave, vetor_memoria);
    }

    // Passo 2: aplicar softmax com beta
    softmax(similaridade, pesos, beta);

    // Passo 3: leitura como soma ponderada dos vetores
    for (int j = 0; j < caract; j++) {
        saida[j] = 0;
        for (int i = 0; i < tamanho; i++) {
            saida[j] += pesos[i] * rosto[j][i];
        }
    }

    // Mostrar os pesos
    cout << "\nPesos de atenção (soft):\n";
    for (int i = 0; i < tamanho; i++) {
        cout << fixed << setprecision(4) << pesos[i] << " ";
    }
    cout << endl;
}

int main() {
    int rosto[caract][tamanho], teste[caract];
    float leitura[caract];

    // Entrada dos vetores de rosto
    for (int j = 0; j < tamanho; j++) {
        cout << "Informe os traços do rosto " << j+1 << ":\n";
        for (int i = 0; i < caract; i++) {
            cin >> rosto[i][j];
        }
    }

    // Entrada do vetor de teste
    cout << "\nInforme o rosto para lembrar:\n";
    for (int i = 0; i < caract; i++) {
        cin >> teste[i];
    }

    // Parâmetro beta
    float beta;
    cout << "Informe o valor de beta (ex: 1.0, 5.0, 10.0): ";
    cin >> beta;

    // Realizar leitura NTM
    leitura_ntm(rosto, teste, beta, leitura);

    // Mostrar resultado da leitura
    cout << "\nResultado da leitura diferenciável (vetor médio ponderado):\n";
    for (int i = 0; i < caract; i++) {
        cout << fixed << setprecision(3) << leitura[i] << " ";
    }
    cout << endl;

    return 0;
}
