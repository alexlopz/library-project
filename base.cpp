#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

/*
authors: 
	Erick Ottoniel Jeronimo Toj, Carné 5190-16-18967
	Francisco Alexander Lopez, Carn�: 5190-13-5530
	Juan Jose Casta�eda Giron, carn�: 5190-17-6503
*/

void menuBookLoans();
void registerBookLoan();
void menuSaveBook();
void saveBook();
void principalMenuOptions(int option);
void textPrincipalMenu();
void menuBookLoansOptions(int option);
void menuSaveBookOptions(int option);
void showBooks();
int validateUserResponse(int min, int max);

int main(void){
	textPrincipalMenu();
	int option = validateUserResponse(0, 4);
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
	cout << "\n";
	return option;
}

void textPrincipalMenu(){
	cout << "INGRESA UNA OPCION POR FAVOR \n\n";
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
	cout << "1) Registar libro \n";
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
	char id[10];
	char bookName[90];
	char author[90];
	char publishYear[90];
	FILE *books;

	//ask for data
	cout << "Registrar libro \n";
	cout << "Escribe el codigo del libro \n";
	cin.ignore();
	cin.getline(id, 10);

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

}

void menuBookLoans(){
	cout << "1) Registar prestamo \n";
	cout << "2) Mostrar libros prestados \n";
	cout << "0) Regresar al menu principal \n";
	int option = validateUserResponse(0, 2);
	menuBookLoansOptions(option);
}

void menuBookLoansOptions(int option){
		switch(option){
		case 1:
			registerBookLoan();
			break;
		case 2:
			break;
		
		case 0:
			main();
			break;
		default:
			cout << "Error \n";
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
		menuBookLoans();
		
	} else {//Error message if the file does not exist or is corrupted
		cout << " Error al abrir el archivo prestamos.txt ";
	}
	 		
	return;	
 	
}



