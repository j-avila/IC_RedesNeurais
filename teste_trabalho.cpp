#include <iostream>
#include <cmath>  // Necessário para cálculos matemáticos

using namespace std;

// Definindo o tamanho máximo dos padrões e da matriz
const int SIZE = 4;

// Função para multiplicação de vetores e armazenamento na matriz de pesos
void hebbianLearning(int weights[SIZE][SIZE], int patterns[][SIZE], int numPatterns) {
    // Inicializa matriz de pesos com zeros
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            weights[i][j] = 0;
        }
    }

    // Ajuste dos pesos baseado nos padrões
    for (int p = 0; p < numPatterns; ++p) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                weights[i][j] += patterns[p][i] * patterns[p][j];
            }
        }
    }
}

// Função para recuperação de padrão usando a matriz de pesos (sem ativação)
void recoverPattern(int weights[SIZE][SIZE], int input[SIZE], int output[SIZE]) {
    // Inicializa o vetor de saída com zeros
    for (int i = 0; i < SIZE; ++i) {
        output[i] = 0;
    }

    // Multiplica o vetor de entrada pela matriz de pesos
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            output[i] += weights[i][j] * input[j];
        }
    }
}

// Função para calcular a similaridade do cosseno com valores intermediários
double cosineSimilarity(int A[SIZE], int B[SIZE]) {
    int dotProduct = 0;
    int normA = 0;
    int normB = 0;
    
    // Calcula o produto escalar e as normas
    for (int i = 0; i < SIZE; ++i) {
        dotProduct += A[i] * B[i];
        normA += A[i] * A[i];
        normB += B[i] * B[i];
    }

    // Calcula a similaridade do cosseno
    return dotProduct / (sqrt(normA) * sqrt(normB));
}

// Função para exibir um padrão com conversão para +1 e -1
void printPatternWithActivation(int pattern[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        // Converte para +1 e -1
        if (pattern[i] >= 0) {
            cout << "+1 ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main() {
    // Padrões conhecidos (para treinamento)
    int patterns[10][SIZE] = {
        { 1, 1, 1, 1 },  
        { -1, -1, -1, -1},  
        { 1, 1, 1, -1 },
        { 1, 1, -1, 1},
        {1, -1, 1, 1},
        {-1, 1, 1, 1},
        {-1, 1, 1, -1},
        {-1, 1, -1, 1},
        {-1, -1, 1, 1},
        {1,-1,1,-1}
    };
    int numPatterns = 10;

    // Matriz de pesos para armazenamento dos padrões
    int weights[SIZE][SIZE];
    hebbianLearning(weights, patterns, numPatterns);

    // Exibe a matriz de pesos resultante
    cout << "Matriz de Pesos apos o Aprendizado:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << weights[i][j] << " ";
        }
        cout << endl;
    }

    // Entrada para teste de recuperação (padrão parcial ou distorcido)
    int testInput[SIZE] = { 1, -1, -1, -1 };

    // Recupera o padrão (sem ativação)
    int recoveredPattern[SIZE];
    recoverPattern(weights, testInput, recoveredPattern);

    // Exibe o padrão recuperado com valores intermediários
    cout << "Padrao Recuperado com Valores Intermediarios (Antes da Ativacao):" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << recoveredPattern[i] << " ";
    }
    cout << endl;

    // Exibe o padrão recuperado após a conversão para +1 e -1
    cout << "Padrao Recuperado (Apos Conversão para +1 e -1):" << endl;
    printPatternWithActivation(recoveredPattern);

    // Calcula e exibe a similaridade do cosseno com os valores intermediários
    double similarity = cosineSimilarity(testInput, recoveredPattern);
    cout << "Similaridade do Cosseno (Valores Intermediarios): " << similarity << endl;

    return 0;
}
