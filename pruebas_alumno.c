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

void pruebas_heap_alumno() {
    //PRUEBAS ALUMNO
	printf("~~Heap vacio~~:\n\n");
	pruebas_heap_vacio();



}
