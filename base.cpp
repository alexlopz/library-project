#include <stdio.h>
#include <iostream>

/*
author: Erick Jeronimo
*/

using namespace std;

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

int main(void){
	saveBook();
}

