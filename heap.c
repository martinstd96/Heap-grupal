#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "heap.h"

#define TAMANIO_INICIAL 30
#define TAMANIO_REDIMENSION 2

struct heap{
  size_t cantidad;
  size_t capacidad;
  void** datos;
  cmp_func_t cmp;
};

heap_t* heap_crear(cmp_func_t cmp){
  heap_t* heap=malloc(sizeof(heap_t));
  if (!heap) return NULL;
  void** datos=malloc(sizeof(void*)*TAMANIO_INICIAL);
  if (!datos){
    free(heap);
    return NULL;
  }
  heap->datos=datos;
  heap->capacidad=TAMANIO_INICIAL;
  heap->cantidad=0;
  heap->cmp=cmp;
  return heap;
}

void swap(void* x,void* y){
  void* auxiliar=*x;
  *x=*y;
  *y=auxiliar;
}

bool redimensionar_heap(heap_t* heap,size_t tamanio_nuevo){
  void** datos_nuevos=realloc(heap->datos,sizeof(void*)*tamanio_nuevo);
  if (!datos_nuevos) return false;
  heap->datos=datos_nuevos;
  heap->capacidad=tamanio_nuevo;
  return true;
}

void upheap(void** arreglo,size_t posicion,cmp_func_t cmp){
  if (posicion==0) return;
  int padre=(posicion-1)/2;
  if (cmp(arreglo[posicion],arreglo[padre])<0) return;
  swap(&arreglo[posicion],&arreglo[padre]);
  upheap(arreglo,padre,cmp);
}

bool heap_encolar(heap_t* heap,void* elem){
  if (heap->cantidad==heap->capacidad){
    size_t tamanio_nuevo=heap->capacidad*TAMANIO_REDIMENSION;
    bool esta_redimensionado_heap=redimensionar_heap(heap,tamanio_nuevo);
    if (!esta_redimensionado_heap) return false;
  }
  heap->datos[cantidad]=elem;
  upheap(heap->datos,heap->cantidad,heap->cmp);
  heap->cantidad++;
  return true;
}

int comparar(void** arreglo,cmp_func_t cmp,size_t posicion1,size_t posicion2){
  return cmp(arreglo[posicion1],arreglo[posicion2]);
}

void downheap(void** arreglo,size_t cantidad,size_t posicion_padre,cmp_func_t cmp){
  if (posicion_padre>=cantidad) return;
  size_t posicion_hijo_izquierdo=(2*posicion_padre)+1;
  size_t posicion_hijo_derecho=(2*posicion_padre)+2;
  size_t posicion_maximo=posicion_padre;
  if (posicion_hijo_izquierdo<cantidad && comparar(arreglo,cmp,posicion_padre,posicion_hijo_izquierdo)<0 && comparar(arreglo,cmp,posicion_hijo_izquierdo,posicion_hijo_derecho)>0) posicion_maximo=posicion_hijo_izquierdo;
  if (posicion_hijo_derecho<cantidad && comparar(arreglo,cmp,posicion_padre,posicion_hijo_derecho)<0 && comparar(arreglo,cmp,posicion_hijo_derecho,posicion_hijo_izquierdo)>0) posicion_maximo=posicion_hijo_derecho;
  if (posicion_padre==posicion_maximo) return;
  swap(&arreglo[posicion_padre],&arreglo[posicion_maximo]);
  downheap(arreglo,cantidad,posicion_maximo,cmp);
}

void* heap_desencolar(heap_t* heap){
  if (heap->cantidad==0) return NULL;
  swap(&heap->datos[0],&heap->datos[heap->cantidad-1]);
  void* dato_desencolado=heap->datos[heap->cantidad-1];
  heap->cantidad--;
  downheap(heap->datos,heap->cantidad,0,heap->cmp);
  size_t un_cuarto_de_heap=heap->cantidad/4;
  size_t tamanio_nuevo=heap->capacidad/TAMANIO_REDIMENSION;
  if (un_cuarto_de_heap==heap->cantidad && tamanio_nuevo>=TAMANIO_INICIAL) redimensionar_heap(heap,tamanio_nuevo);
  return dato_desencolado;
}

void* heap_ver_max(const heap_t* heap){
  return heap->cantidad==0? NULL:heap->datos[0];
}

bool heap_esta_vacio(const heap_t* heap){
  return heap->cantidad==0;
}

size_t heap_cantidad(const heap_t* heap){
  return heap->cantidad;
}

void heap_destruir(heap_t* heap,void destruir_elemento(void* e)){
  if (destruir_elemento){
    for (size_t i=0; i<heap->cantidad; i++) destruir_elemento(heap->datos[i]);
  }
  free(heap->datos);
  free(heap);
}

heap_t* heap_crear_arr(void* arreglo[],size_t n,cmp_func_t cmp){
  heap_t* heap=malloc(sizeof(heap_t));
  if (!heap) return NULL;
  void** datos=malloc(sizeof(void*)*TAMANIO_INICIAL);
  if (!datos){
    free(heap);
    return NULL;
  }
  heap->datos=datos;
  heap->capacidad=TAMANIO_INICIAL;
  heap->cantidad=0;
  heap->cmp=cmp;
  for (size_t i=0; i<n; i++) heap_encolar(heap,arreglo[i]);
  return heap;
}
