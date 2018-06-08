#include <string.h>

void pruebas_heap_vacio(){
	heap_t* heap = heap_crear(strcmp);

	print_test("heap esta vacio", heap_esta_vacio(heap) == 0);
	print_test("cantidad 0", heap_cantidad(heap) == 0);
	print_test("desencolar es falso", !heap_desencolar(heap));
	print_test("ver el maximo es falso", !heap_ver_max(heap));

	heap_destruir(heap, NULL);
	print_test("Destruyo el heap", true);
}

void pruebas_heap_encolar(){
	heap_t* heap = heap_crear(strcmp);

	char* valor1 = "1";
	char* valor2 = "5";
	char* valor3 = "2";
	char* valor4 = "3";
	char* valor5 = "4";
	char* valor6 = "6";

	print_test("heap esta vacio", heap_esta_vacio(heap) == 0);
	print_test("cantidad 0", heap_cantidad(heap) == 0);

	bool ok = true;

	ok += heap_encolar(heap,valor1);
	ok += heap_encolar(heap,valor2);
	ok += heap_encolar(heap,valor3);
	ok += heap_encolar(heap,valor4);
	ok += heap_encolar(heap,valor5);
	ok += heap_encolar(heap,valor6);

	print_test("se encolaron todos los valores correctamente",ok);
	print_test("cantidad de elementos es 6", heap_cantidad(heap) == 6);


	heap_destruir(heap, NULL);
	print_test("Destruyo el heap", true);
}

void pruebas_heap_desencolar(){
	heap_t* heap = heap_crear(strcmp);

	char* valor1 = "1";
	char* valor2 = "5";
	char* valor3 = "2";
	char* valor4 = "3";
	char* valor5 = "4";
	char* valor6 = "6";

	print_test("heap esta vacio", heap_esta_vacio(heap) == 0);
	print_test("cantidad 0", heap_cantidad(heap) == 0);

	bool ok = true;

	ok += heap_encolar(heap,valor1);
	ok += heap_encolar(heap,valor2);
	ok += heap_encolar(heap,valor3);
	ok += heap_encolar(heap,valor4);
	ok += heap_encolar(heap,valor5);
	ok += heap_encolar(heap,valor6);

	print_test("se encolaron todos los valores correctamente",ok);
	print_test("cantidad de elementos es 6", heap_cantidad(heap) == 6);

	for (int i = 0; i<6; i++){
		char* tope = heap_ver_max(heap);
		ok += strcmp(*(char*)heap_desencolar(heap),*(char*)tope) == 0;
	}

	print_test("se desencolaron todos los elementos correctamente",ok);
	print_test("cantidad de elementos 0", heap_cantidad(heap) == 0);
	print_test("heap vacio",heap_esta_vacio(heap));


	heap_destruir(heap, NULL);
	print_test("Destruyo el heap", true);
}

void pruebas_heap_alumno() {

	printf("~~Heap vacio~~:\n\n");
	pruebas_heap_vacio();

	printf("\n~~Heap encolar~~\n\n");
	pruebas_heap_encolar();

	printf("\n~~Heap desencolar~~\n\n");
	pruebas_heap_desencolar();


}
