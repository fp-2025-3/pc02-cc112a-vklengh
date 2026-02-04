#include <iostream>
#include <cstring> // para usar strlen()
#include <cctype> // tolower()
using namespace std;


char* leerFrase() {
    char temp[100]; 
    cout << "Ingrese una frase: ";
    cin.getline(temp,100);

    int len = strlen(temp);
    // realizar la asignación dinámica
    char *frase = new char[len + 1];

    for (int i = 0; i <= len; ++i) {
        frase[i] = temp[i];
    }

    return frase;
}


char* normalizarFrase(char* frase) {
    char temp[100];
    int i = 0;
    int j = 0;

    //Falta analizar si hay multiples espacios... TAREA
    while (frase[i] != '\0') {
        if(!isspace(frase[i])) {
            temp[j] = tolower(frase[i]);
            ++j;
        }else { // modificar aquí
            temp[j]= ' ';
            j++;
        }
        ++i;
    }

    temp[j] = '\0';

    char *normalizada = new char[j + 1];
    //Otra forma
    strcpy(normalizada, temp);

    return normalizada;
}



int contarPalabras(char* frase) {
    int cont = 0;
    bool estoyPalabra = false;

    for (int i = 0; frase[i]!= '\0'; ++i) {
        if (!isspace(frase[i]) && !estoyPalabra) {
            cont++;
            estoyPalabra = true;
        }
        if(isspace(frase[i])) {
            estoyPalabra = false;
        }
    }

    return cont;
}


char** separarPalabras(char* frase, int n) {

    char** palabras = new char*[n];

    int i = 0; // para recorrer frase
    int j = 0; // para manipular indices de palabras[j]

    while(frase[i] != '\0') {

        while(isspace(frase[i])){
            i++;
        }

        int inicio = i;
        int len = 0;

        while (frase[i] != '\0' && !isspace(frase[i])) {
            i++;
            len++;
        }

        palabras[j] = new char[len + 1];

        for (int k = 0; k < len; ++k) {
            palabras[j][k] = frase[inicio + k];
        }
        palabras[j][len] = '\0';

        j++;
    }

    return palabras;  // Como libero memoria dinámica

}



void mostrarPalabras(char** palabras, int n) {
    for (int i = 0; i < n; ++i) {
        cout << palabras[i] << "\t" << strlen(palabras[i]) <<endl;
    } 

}

void liberarMemoria(char** palabras, int n) {
    for (int i = 0; i < n; ++i){
        delete [] palabras[i];
    }
    delete [] palabras;
}


int main(){

    char *frase = leerFrase(); // debo liberar memoria

    char *normalizada = normalizarFrase(frase); // debo liberar memoria

    int numPal = contarPalabras(frase); 

    char** palabras = separarPalabras(normalizada,numPal); // debo liberar

    mostrarPalabras(palabras, numPal);

    delete [] frase;
    frase = nullptr;

    delete [] normalizada;
    normalizada = nullptr;

    liberarMemoria(palabras, numPal);
    palabras = nullptr;
    return 0;
}

