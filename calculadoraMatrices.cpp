/*  Este programa muestra la reservación y liberación de matrices en tiempo de ejecución.
    El operador "new" es similar a malloc de C y "delete" es similar a "free" de C.
    Una vez creada la matriz dinámica, nótese que su uso es igual al de una matriz "normal". */

#include <iostream> //Biblioteca para flujos estándar de C++.

//Función que imprime una matriz. Nótese su manejo como matriz "normal".
//Recibe un apuntador de apuntadores representando la matriz y no regresa nada.
int N_FILAS;
int N_COLUS;

void imprimir_matriz(float **matriz) {
    for (int i = 0; i < N_FILAS; i++) {
        for (int j = 0; j < N_COLUS; j++) {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

//Función que llena con valores una matriz. Nótese su manejo como matriz "normal".
//Recibe un apuntador de apuntadores representando la matriz y no regresa nada.
void llenar_matriz(float **matriz) {
    for (int i = 0; i < N_FILAS; i++) {
        for (int j = 0; j < N_COLUS; j++) {
            std::cout << "Ingresa el elemento (" << i+1 <<", " << j+1 << "): ";
            std::cin >> matriz[i][j];
        }
    }
}

void suma(float **matriz, float **matrizb, float **matrizRes){
    for (int i = 0; i < N_FILAS; i++) {
        for (int j = 0; j < N_COLUS; j++) {
            matrizRes[i][j]=matriz[i][j]+matrizb[i][j];
        }
    }
}

void resta(float **matriz, float **matrizb, float **matrizRes){
    for (int i = 0; i < N_FILAS; i++) {
        for (int j = 0; j < N_COLUS; j++) {
            matrizRes[i][j]=matriz[i][j]-matrizb[i][j];
        }
    }
}

void multiplicacion(float **matriz, float **matrizb, float **matrizRes){
    for (int i = 0; i < N_FILAS; i++) {
        for (int j = 0; j < N_COLUS; j++) {
            matrizRes[i][j]=0;
            for(int k=0; k<N_FILAS; k++){
                matrizRes[i][j]+=matriz[i][k]*matrizb[k][j];
            }
        }
    }
}

int main(void) {
    float **matriz; //Apuntador a apuntador donde se guardará la referencia de la matriz.
    float **matrizb;
    float **matrizRes;

    std::cout<<"CALCULADORA PARA SUMA, RESTA Y MULTIPLICACION DE MATRICES NXN"<<std::endl;
    std::cout<<"Indica N: ";
    std::cin>>N_FILAS;
    N_COLUS=N_FILAS;

    //Se reserva memoria para N_FILAS cantidad de filas.
    matriz = new float*[N_FILAS];
    matrizb = new float*[N_FILAS];
    matrizRes = new float*[N_FILAS];
    //Por cada fila, se reserva memoria para N_COLUS.       
    for (int i = 0; i < N_FILAS; i++) {
        matriz[i] = new float[N_COLUS];
        matrizb[i] = new float[N_COLUS];
        matrizRes[i] = new float[N_COLUS];
    }

    //Se llena e imprime la matriz con las funciones creadas.
    std::cout<<"LLENA LA PRIMERA MATRIZ:"<<std::endl;
    llenar_matriz(matriz);
    std::cout<<"LLENA LA SEGUNDA MATRIZ:"<<std::endl;
    llenar_matriz(matrizb);

    //Operaciones y Resultados
    std::cout<<"El resultado de la suma de ambas matrices es:"<<std::endl;
    suma(matriz,matrizb,matrizRes);
    imprimir_matriz(matrizRes);
    std::cout<<"El resultado de la resta de ambas matrices es:"<<std::endl;
    resta(matriz,matrizb,matrizRes);
    imprimir_matriz(matrizRes);
    std::cout<<"El resultado de la multiplicacion de ambas matrices es:"<<std::endl;
    multiplicacion(matriz,matrizb,matrizRes);
    imprimir_matriz(matrizRes);


    //Se borra cada fila de la matriz.
    for (int i = 0; i < N_FILAS; i++) {
        delete[] matriz[i];
        delete[] matrizb[i];
        delete[] matrizRes[i];
    }
    //Se borran los apuntadores a cada fila de la matriz.
    delete[] matriz;
    delete[] matrizb;
    delete[] matrizRes;
    return 0;
}
