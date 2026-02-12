#include <iostream>
using namespace std;
const int N = 4;
const int R_SIZE = 6;
int R[R_SIZE][2] = {
    {1,1},
    {1,2},
    {2,1},
    {3,4},
    {4,2},
    {4,4}
};
int main(){
    int M[N][N] = {0};
    for(int i = 0; i < R_SIZE; i++){
        int a = R[i][0] - 1;  
        int b = R[i][1] - 1;
        M[a][b] = 1;
    }
    cout << "Матриця відношення R1:\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    bool reflexive = true, irreflexive = true;
    bool symmetric = true, antisymmetric = true, asymmetric = true;
    bool transitive = true;
    // Рефлексивність / іррефлексивність
    for(int i = 0; i < N; i++){
        if(M[i][i] == 0) reflexive = false;
        if(M[i][i] == 1) irreflexive = false;
    }
    // Симетричність, антисиметричність, асиметричність
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(M[i][j] != M[j][i]) symmetric = false;
            if(i != j && M[i][j] == 1 && M[j][i] == 1) antisymmetric = false;
            if(M[i][j] == 1 && M[j][i] == 1) asymmetric = false; 
        }
    }
    // Транзитивність
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(M[i][j] == 1){
                for(int k = 0; k < N; k++){
                    if(M[j][k] == 1 && M[i][k] == 0){
                        transitive = false;
                    }
                }
            }
        }
    }
    cout << "\nВластивості відношення:\n";
    cout << "Рефлексивне: " << (reflexive ? "так" : "ні") << endl;
    cout << "Іррефлексивне: " << (irreflexive ? "так" : "ні") << endl;
    cout << "Симетричне: " << (symmetric ? "так" : "ні") << endl;
    cout << "Антисиметричне: " << (antisymmetric ? "так" : "ні") << endl;
    cout << "Асиметричне: " << (asymmetric ? "так" : "ні") << endl;
    cout << "Транзитивне: " << (transitive ? "так" : "ні") << endl;
    // --- 3. Алгоритм Уоршелла ---
    int T[N][N];
    // копіюємо матрицю
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            T[i][j] = M[i][j];
    // сам алгоритм
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(T[i][j] == 0 && (T[i][k] == 1 && T[k][j] == 1)){
                    T[i][j] = 1;
                }
            }
        }
    }
    cout << "\nТранзитивне замикання (алгоритм Уоршелла):\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
