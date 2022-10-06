#include <iostream>
#include <algorithm>

using namespace std;

// Classes
class Lista {
    public:
        int lista[100];
        int tamanho;
        Lista();
        void inserir(int valor);
};

class StringArray {
    public:
        string strings[100];
        int tamanho;
        StringArray();
        void add(string c);
        void printArray();
        Lista parse(int i);
        Lista handleNumber(string line, int i);
};

class GrausDeEntrada {
    public: 
        int tamanho;
        GrausDeEntrada();
        int graus[100];
        void printGraus();
};

class Grafo {
    public:
        Lista listaRelacoes[100];
        int tamanhoListaRelacoes;
        void inserirNaLista(Lista lista);
        Grafo();
        void parse(StringArray SA);
        void printRelacoes();
        void findGraus(GrausDeEntrada& g);
        void reduzirGrau(GrausDeEntrada& g);
        bool isAllZero(GrausDeEntrada g);
        int listaOrdenada[100];
        void adicionarNaListaOrdenada(int valor);
        int tamanhoListaOrdenada;
        void printListaOrdenada();
};

// Construtores 
GrausDeEntrada:: GrausDeEntrada(){
    this->tamanho = 0;
};

Lista:: Lista(){
    tamanho = 0;
};

Grafo:: Grafo(){
    this->tamanhoListaRelacoes = 0;
    this->tamanhoListaOrdenada = 0;
};

StringArray:: StringArray(){
    this->tamanho = 0;
};

// Métodos
bool isNumber(string s){
    return std::any_of(s.begin(), s.end(), ::isdigit);
}

int getNumeroDeVertices(string line){
    int i = 0;
    string numeroEmString = "";
    while(line[i] != ' '){
        numeroEmString += line[i];
        i++;
    }
    return stoi(numeroEmString);
};

void Grafo:: findGraus(GrausDeEntrada& g){
    for(int i = 0; i < tamanhoListaRelacoes; i++){
        int vertice = i + 1;
        int grau = 0;
        for(int k = 0; k < tamanhoListaRelacoes; k++){
            for(int j = 0; j < listaRelacoes[k].tamanho; j++){
                if(listaRelacoes[k].lista[j] == vertice){
                    grau++;
                }
            }
        }
        g.graus[i] = grau;
        g.tamanho++;
    }
};

void Grafo:: adicionarNaListaOrdenada(int valor){
    listaOrdenada[tamanhoListaOrdenada] = valor;
    tamanhoListaOrdenada++;
};

void Grafo:: printListaOrdenada(){
    for(int i = 0; i < this->tamanhoListaOrdenada; i++){
        cout << this->listaOrdenada[i] << " ";
    }
    cout << endl;
}

void Lista::inserir(int valor){
    lista[tamanho] = valor;
    tamanho++;
};

void StringArray:: add(string c){
    strings[tamanho] = c;
    tamanho++;
};

void Grafo:: inserirNaLista(Lista lista){
    this->listaRelacoes[tamanhoListaRelacoes] = lista;
    tamanhoListaRelacoes++;
};

void StringArray:: printArray(){
    for(int i = 0; i < tamanho; i++){
        cout<< i + 1<<": "<<strings[i]<<endl;
    }
    cout<<endl;
};

Lista StringArray:: handleNumber(string line, int i){
    Lista lista;
    int n = line.length();
    int j = 0;
    string substring = "";
    while(j < n){
        if(line[j] != ' '){
            substring += line[j];
        }
        else{
            int valor = stoi(substring);
            lista.inserir(valor);
            substring = "";
        }
        j++;
    }
    if(substring != "" && substring != " "){
        int valor = stoi(substring);
        lista.inserir(valor);
    } 
    return lista;
};

Lista StringArray:: parse(int i){
    Lista lista;
    string line = strings[i];
    if(isNumber(line)){
        lista = handleNumber(line, i);
    }
    return lista;
};

void Grafo:: parse(StringArray SA){
    for(int i = 0; i < SA.tamanho; i++){
        Lista lista = SA.parse(i);
        this->inserirNaLista(lista);
    }
};

void Grafo:: printRelacoes(){
    for(int i = 0; i < this->tamanhoListaRelacoes; i++){
        cout<<"\n Aresta "<<i + 1<<endl;
        for(int j = 0; j < this->listaRelacoes[i].tamanho; j++){
            cout<<this->listaRelacoes[i].lista[j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
};

bool Grafo:: isAllZero(GrausDeEntrada g){
    bool notZero = true;
    for(int i = 0; i < tamanhoListaRelacoes; i++){
        if(g.graus[i] > -1){
            notZero = false;
        }
    }
    return notZero;
};

void GrausDeEntrada:: printGraus(){
    for(int i = 0; i < tamanho; i++){
        cout<<"Grau de entrada do vertice "<<i + 1<<": "<<graus[i]<<endl;
    }
    cout<<endl;
};

void Grafo:: reduzirGrau(GrausDeEntrada& g){
    for(int i = 0; i < tamanhoListaRelacoes; i++){
        int grauVerticeAnalisado = g.graus[i];
        if(grauVerticeAnalisado == 0){
            g.graus[i] = -1;
            adicionarNaListaOrdenada(i + 1);
            for(int j = 0; j < listaRelacoes[i].tamanho; j++){
                int vertice = listaRelacoes[i].lista[j];
                g.graus[vertice - 1]--;
            }
        }
    }
};

int main() {
    Grafo grafo;
    GrausDeEntrada graus;
    StringArray lines;

    string firstLine = "";
    getline(cin, firstLine);
    int nVertices = getNumeroDeVertices(firstLine);

    for(int i = 0; i < nVertices; i++){
        string line = "";
        getline(cin, line);
        lines.add(line);
    }

    grafo.parse(lines);
    grafo.findGraus(graus);
    
    while(!grafo.isAllZero(graus)){
        grafo.reduzirGrau(graus);
    }

    grafo.printListaOrdenada();
}