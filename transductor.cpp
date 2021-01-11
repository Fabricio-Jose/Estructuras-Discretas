#include <iostream>
#include <string>
using namespace std;

void raiz(char ***matriz,int tam, int i,int j,int k,int l){
    for(int g=0;g<tam;g++){
    	if(matriz[l][g][0]!='-'){ 
	    matriz[i][g][0]=matriz[l][g][0];
	    matriz[i][g][1]=matriz[l][g][1];
	    raiz(matriz,tam,i,j,k,l);
	}
    }
}

int main(){
    cout<<"ingrese numero de estados: "<<endl;
    int tam,q0,aceptacion_n,inicial,falso;
    falso=0;    
    cin >> tam ;
    char ***matriz = new char**[tam];
    for(int i=0; i<tam; i++) {
        matriz[i] = new char*[tam];
        for(int j=0; j<tam; j++){
            matriz[i][j] = new char[2];
        }
    } 
    //ingresando estado inicial
    cout<<"ingrese el estado inicial: ";
    cin>>q0;
    //ingresando estados de aceptación
    cout<<"cuantos estados de aceptacion tendra? ";
    cin>>aceptacion_n;
    int *aceptacion = new int[aceptacion_n];
    cout<<"ingrese el/los estados de aceptacion: "<<endl;
    for(int i=0; i<aceptacion_n;i++){
	    cin>>aceptacion[i];
    }
    //llenando matriz
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
	    cout<<"Ingrese dato a leer ["<<i<<"]["<<j<<"]: ";
            cin>>matriz[i][j][0] ;
            if(matriz[i][j][0]!='-'){
                cout<<"Ingrese altura: ";
                cin>>matriz[i][j][1];
            }
        }
    }
    //mostrando matriz de adyacencia
    cout<<"mostrando matriz de adyacencia: nodo // altura"<<endl;
    for (int i=0; i<tam; i++){
        for (int j=0; j<tam; j++){
            cout<<"["<<matriz[i][j][0]<<","<<matriz[i][j][1]<<"]"<<" ";
        }
        cout<<endl;
    }

    //dominique revuz
    //estados equivalentes =h

    for (int i=0; i<tam; i++){
        for (int j=0; j<tam; j++){
// 	    matriz[i][j][0]		
	    for(int k=0;k<tam;k++){
	       for(int l=0;l<tam;l++){
		   if( i!=k){
		        if(matriz[i][j][0]!='-' && matriz[k][l][0]!='-'){
			    if( matriz[i][j][0]==matriz[k][l][0] && matriz[i][j][1]==matriz[k][l][1]){ 
				 matriz[k][j][0]=matriz[k][l][0];
				 matriz[k][j][1]=matriz[k][l][1];
				 matriz[k][l][0]='-';
				 matriz[k][l][1]=' ';
				 //recursion
				raiz(matriz,tam,i,j,k,l);
				 

			     }
			}
		   }else
		    if(j!=l && matriz[i][j][0]!='-' && matriz[k][l][0]!='-'){
			    if(matriz[i][j][0]==matriz[k][l][0] && matriz[i][j][1]==matriz[k][l][1]){			  
                		matriz[k][j][0]=matriz[k][l][0];
		                matriz[k][j][1]=matriz[k][l][1];
		                matriz[k][l][0]='-';
		                matriz[k][l][1]=' ';
				raiz(matriz,tam,i,j,k,l);

		   	    }
		    }
		   
	       }
	    }
        }
        cout<<endl;
    }

    //volviendo a mostrar matriz nueva

    cout<<"mostrando matriz de adyacencia: nodo // altura"<<endl;
    for (int i=0; i<tam; i++){
        for (int j=0; j<tam; j++){
            cout<<"["<<matriz[i][j][0]<<","<<matriz[i][j][1]<<"]"<<" ";
        }
        cout<<endl;
    }

/*  char y;
    y='y';
    int q=q0;
	while(y=='y'){
    //validamos cadena y transformamos
    int fin;
    string cadena, transducida;
    cout<<"ingresar cadena de enteros: ";
    cin>>cadena;
    transducida=cadena;
    for(int i=0; i<cadena.size(); i++){        
        for(int j=0; j<tam; j++){
            if(cadena[i]==matriz[q][j][0]){
                transducida[i]=matriz[q][j][1];
                fin=j;
                q=fin;
                break;
            }            
        }
    }
    
    //confirmamos estado final
    for (int i=0; i<aceptacion_n;i++){
        if(fin==aceptacion[i]){
            cout<<"cadena ingresada: "<<cadena<<endl;
            cout<<"cade transducida: "<<transducida<<endl;
        }
        if((fin!=aceptacion[i]) && (i==aceptacion_n-1))
            cout<<"cadena no aceptada"<<endl;        
    }
    //repetir proceso
    cout<<"desea continuar? y/n: ";
    cin>>y;    
	q=q0;
    }*/

    return 0;
}
