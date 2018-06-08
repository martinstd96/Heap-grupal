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

	char *clave1 = "perro", *valor1 = "guau";
  char *clave2 = "gato", *valor2 = "miau";
  char *clave3 = "vaca", *valor3 = "mu";
  char *clave4 = "chancho", *valor4 = "oing";
  char *clave5 = "Martin", *valor5 = "peludo";
  char *clave6 = "Leo", *valor6 = "metalero";
	/*
  char *clave7 = "Gian", *valor7 = "corrector";
  char *clave8 = "Papa", *valor8 = "Francisco";
  char *clave9 = "Tesla", *valor9 = "autazos";
  char *clave10 = "cola", *valor10 = "nodo";
  char *clave11 = "COD", *valor11 = "tiros";
  char *clave12 = "FIFA", *valor12 = "futbol";
  char *clave13 = "ATP", *valor13 = "tenis";
  char *clave14 = "asado", *valor14 = "argentino";
  char *clave15 = "fernet", *valor15 = "cordobes";
  char* clave16 = "Lenovo", *valor16 = "Motorola";
  char *clave17 = "Apple", *valor17 = "IPhone";
  char *clave18 = "Fiuba", *valor18 = "jodida";
  char *clave19 = "fisica", *valor19 = "Newton";
	char *clave20 = "ARM", *valor20 = "microprocesador";
	*/

	print_test("heap esta vacio", heap_esta_vacio(heap) == 0);
	print_test("cantidad 0", heap_cantidad(heap) == 0);

	bool ok = true;

	ok = heap_encolar(heap,clave1,valor1);
	ok = heap_encolar(heap,clave2,valor2);
	ok = heap_encolar(heap,clave3,valor3);
	ok = heap_encolar(heap,clave4,valor4);
	ok = heap_encolar(heap,clave5,valor5);
	ok = heap_encolar(heap,clave6,valor6);

	print_test("se encolaron todos los valores correctamente",ok);
	print_test("cantidad de elementos es 6", heap_cantidad(heap) == 6);


	heap_destruir(heap, NULL);
	print_test("Destruyo el heap", true);
}

void pruebas_heap_alumno() {

	printf("~~Heap vacio~~:\n\n");
	pruebas_heap_vacio();

	printf("\n~~Heap encolar~~\n\n");
	pruebas_heap_encolar();


}
