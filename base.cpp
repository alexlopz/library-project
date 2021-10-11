#include <stdio.h>
#include <iostream>

using namespace std;

/*
authors: 
	Erick Jeronimo
	Francisco Alexander Lopez, Carné: 5190-135530
*/
void saveBook()
{
	//declare variables
	int id;
	char bookName[90];
	char author[90];
	char publishYear[90];
	FILE *books;

	//ask for data
	cout << "Registrar libro";
	cout << "Escribe el nombre del libro \n";
	cin.ignore();
	cin.getline(bookName, 90);
	cout << "Escribe el autor del libro \n";
	cin.getline(author, 90);
	cout << "Escribe el anio de publicacion del libro \n";
	cin >> publishYear;

	//open book file
	books = fopen("./libros.txt", "a");	

	//validate books exist
	if (books != NULL) {
	 	fprintf(books, "%s|%s|%s\n",bookName,author,publishYear);
		fclose(books);
	}else{
		cout << " Error al Abrir el archivo libros.txt ";
	}

}

void menuBookLoans();
void registerBookLoan();

int main(void){

	int option;
	
	cout << "INGRESA UNA OPCION POR FAVOR \n\n";
	cout << "1) Registrar libros. \n";
	cout << "2) Prestamos de libros. \n";
	cout << "0) Salir \n";
	cin >> option;
	
	while(option != 0) {
		switch(option){
			case 1:
				saveBook();
				break;
			case 2:
				menuBookLoans();
				break;
			default:
				cout << "Opcion no registrada";
				break;
		}	
	}	
}

void menuBookLoans(){
	int option;
	cout << "1) Registar prestamo \n";
	cout << "0) Regresar al menu principal \n";
	cin >> option; 
	
	switch(option){
		case 1:
			registerBookLoan();
			break;
		case 0:
			main();
			break;
		default:
			cout << "Error";
			break;		
	}
	
}

void registerBookLoan() {
	
	//declare variables
	FILE *loans;
 	char bookCode[8];
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
		cin.getline(bookCode, 8);
		
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
		
	} else {//Error message if the file does not exist or is corrupted
		cout << " Error al abrir el archivo prestamos.txt ";
	}
	 		
	return;	
 	
}


