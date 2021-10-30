#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;

/*
authors: 
	Erick Ottoniel Jeronimo Toj, Carné 5190-16-18967
	Francisco Alexander Lopez, Carn�: 5190-13-5530
	Juan Jose Casta�eda Giron, carn�: 5190-17-6503
*/

//fuctions references
void textPrincipalMenu();
void principalMenuOptions(int option);
int validateUserResponse(int min, int max);
void menuSaveBook();
void menuBookLoansOptions(int option);
void saveBook();
void showBooks();
void menuBookLoans();
void saveBookLoan();
void menuSaveBookOptions(int option);
void showBooksLoans();
void searchBook();
void validateLoan(string query);


//main fuction
int main(void){
	//text for main menu
	textPrincipalMenu();
	int option = validateUserResponse(0, 4);
	//menu options fuctions
	principalMenuOptions(option);
}

int validateUserResponse(int min, int max){
	int option;
	cin >> option;

	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main();
	}

	while(option < min || option > max){
		cout << "No ingresaste una opcion valida, Intenta de nuevo \n";
		cin >> option;
	}

	cout << "Tu respuesta fue ";
	cout << option;
	cout << "\n\n";
	return option;
}

void textPrincipalMenu(){
	cout << "\n\nINGRESA UNA OPCION POR FAVOR \n\n";
	cout << "1) Registros de libros. \n"; 
	cout << "2) Prestamos de libros. \n";
	cout << "3) Busqueda de Libros. \n";
	cout << "4) Limpiar pantalla. \n";
	cout << "0) Salir \n";
}

void principalMenuOptions(int option){
		switch(option){
			case 1:
				menuSaveBook();
				break;

			case 2:
				menuBookLoans();
				break;

			case 3:
				searchBook();
				break;
				
			case 4: 
					system("cls");	
					main();	
					break;
			case 0:
					exit(3);
	
			default:
				cout << "Opcion no registrada \n";
				main();
				break;
	
		}	
}

void menuSaveBook(){
	cout << "\n1) Registar libro \n";
	cout << "2) Mostrar libros registrados \n";
	cout << "0) Regresar al menu principal \n";
	int option = validateUserResponse(0, 2);
	menuSaveBookOptions(option);
}

void menuSaveBookOptions(int option){
	switch(option){
		case 1:
			saveBook();
			break;
		case 2:
			showBooks();
			break;
		
		case 0:
			main();
			break;
		default:
			cout << "Error \n";
			break;		
	}	
}

void saveBook(){
	//declare variables
	char id[5];
	char bookName[90];
	char author[90];
	char publishYear[90];
	FILE *books;

	//ask for data
	cout << "Registrar libro \n";
	cout << "Escribe el codigo del libro \n";
	cin.ignore();
	cin.getline(id, 5);

	cout << "Escribe el nombre del libro \n";
	cin.getline(bookName, 90);
	
	cout << "Escribe el autor del libro \n";
	cin.getline(author, 90);

	cout << "Escribe el anio de publicacion del libro \n";
	cin >> publishYear;

	//open book file
	books = fopen("./libros.txt", "a");	

	//validate books exist
	if (books != NULL) {
	 	fprintf(books, "%s|%s|%s|%s\n", id, bookName, author, publishYear);
		fclose(books);
		cout << "Registro guardado con exito!!!\n\n";
		menuSaveBook();
	}else{
		cout << " Error al Abrir el archivo libros.txt ";
	}
}

void showBooks(){
	//declare variales
	FILE *books;
	char line[256];
	
	// asign path file 
 	books= fopen("./libros.txt", "r"); 

	cout << "Listado de libros \n";
 	if (books != NULL) {// file validation
   		while (!feof(books)) {
     		if (!feof(books)) {
     			*line = 0;
     			fgets(line, 256, books);
     			     			
	 			for(int i = 0; i < strlen(line);i++){//print books
	 				if(line[i] == '|'){
	        			putchar(' ');
					} else {
						putchar(line[i]);
					}
	    		}
   			}
		}
	   fclose(books);//close file
	   menuSaveBook();//return book menu
	}else{
		cout << " Error al Abrir el archivo libros.txt  ";
	}	
}

void menuBookLoans(){
	cout << "\n1) Registar prestamo \n";
	cout << "2) Mostrar libros prestados \n";
	cout << "0) Regresar al menu principal \n";
	int option = validateUserResponse(0, 2);
	menuBookLoansOptions(option);
}

void menuBookLoansOptions(int option){
		switch(option){
		case 1:
			saveBookLoan();
			break;
		case 2:
			showBooksLoans();
			break;
		case 0:
			main();
			break;
		default:
			cout << "Error \n";
			break;		
	}
}

void saveBookLoan() {
	
	//declare variables
	FILE *loans;
 	char bookCode[5];
 	char loanDate[16];
 	char returDate[16];
 	char userName[128];
 	char userDocument[128];
 	
 	//initialize the file variable and pass the file path
 	loans = fopen("./prestamos.txt", "a");
 	
 	//validate that the prestamos.txt file exists and is not corrupted to start the flow
 	if(loans != NULL) {
 		
 		//capture data
		cout << "**Registrar prestamos de libros** \n";
		
		cout << "Escribe el codigo del libro por favor:\n";
		cin.ignore();
		cin.getline(bookCode, 5);
		
		cout << "Escribe la fecha del prestamo ejemplo: 01/01/2021 \n";
		cin.getline(loanDate, 16);
		
		cout << "Escribe la fecha de devolucion del libro ejemplo: 01/01/2021 \n";
		cin.getline(returDate, 16);
		
		cout << "Nombre de quien presta el libro \n";
		cin.getline(userName, 128);
		
		cout << "Numero de DPI de quien presta el libro \n";
		cin.getline(userDocument, 128);
		
		//Write and format the captured data to the file.
		fprintf(loans, "%s|%s|%s|%s|%s\n", bookCode, loanDate, returDate, userName, userDocument);
		fclose(loans);
		
		cout << "Registro guardado con exito!!!\n\n";
		menuBookLoans();
		
	} else {//Error message if the file does not exist or is corrupted
		cout << " Error al abrir el archivo prestamos.txt ";
	}
	 		
	return;	
 	
}

void showBooksLoans(){

	//declare variables
	FILE *loans;
	char line[256];
	
	//file path
 	loans= fopen("./prestamos.txt", "r"); 

	cout << "Listado de prestamos de libros \n\n";
 	if (loans != NULL) {
   		while (!feof(loans)) {
     		if (!feof(loans)) {
     			*line = 0;
     			fgets(line, 256, loans);
     			     			
	 			for(int i = 0; i < strlen(line);i++){//print loans
	 				if(line[i] == '|'){
	        			putchar(' ');
					} else {
						putchar(line[i]);
					}
	    		}
   			}
		}
	   fclose(loans);
	   menuBookLoans();
	}else{
		cout << " Error al Abrir el archivo libros.txt  ";
	}
}

void searchBook(){
	
	//declare variables
	string line;
	string query; 
	
	cout << "Busqueda de libros \n\n";
	cout << "Codigo del libro a buscar: " << endl;
	cin.ignore();
	cin >> query;
	
	//variable tipe strema
	ifstream  books("./libros.txt");

 	while(getline(books, line)){
 		
 		int position = line.find(query);
 		
 		if(position!=string::npos){
			int indexCod = 	line.find("|");
			int indexNam = line.find("|", indexCod + 1);
			
			cout << "Resultado: \n\n";
			cout << "Nombre libro: ";
			for(int i = indexCod+1; i < indexNam; i++ ){
				putchar(line[i]);
			}
			
			validateLoan(query);
			 			
		 }
 		
	 }
	 
	main();	//muestra el menu	
}

void validateLoan(string query){
	string lineLoans;
			
	ifstream  loans("./prestamos.txt");
 
	 while(getline(loans, lineLoans)){
	 
	 	int indexLoans = lineLoans.find(query);//se busca el codigo 
	 	
	 	if(indexLoans!=string::npos){//si existe el codigo se imprime la fecha de prestamo y nombre a quien se presto
	 		int indexCod = 	lineLoans.find("|");
			int indexDate = lineLoans.find("|", indexCod+1);
			int indexDev = lineLoans.find("|", indexDate+1);
			int indexName = lineLoans.find("|", indexDev+1);
			
	 		cout << "\nFecha Prestamo: ";
	 		for(int i = indexCod+1; i < indexDate; i++ ){
				putchar(lineLoans[i]);
			}
			
 			cout << "\nPrestado a: ";
	 		for(int i = indexDev+1; i < indexName; i++ ){
				putchar(lineLoans[i]);
			}					
		 }
	 }	
}



