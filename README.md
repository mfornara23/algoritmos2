# Obligatorio Algoritmos 2 - ORT - 2022

## Ejercicio 1
### Letra
Se tiene una base de datos de usuario identificados por e-mail pero se empezo a notar de que existen usuarios duplicados (comparten el mismo e-mail) por lo cual se quiere calcular cuantos usuarios reales existen.

### Input
La primera línea de la entrada contiene un número entero positivo N (2 ≤ N ≤ 10^5), el número de usuarios acutales del sistema.

### Salida
Imprime el único número entero: la cantidad real de usuarios (sin repetidos).

### Restricciones
* Utilizar una tabla de hash cerrado.
* Resolver en orden temporal: O(N) promedio, siendo N la cantidad de usuarios.

### Solución

Hash cerrado (open addressing) que implementa la [siguiente función de hash](https://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-15.html) y double-hashing para la resolución de colisiones.

Para contar la cantidad de mail sin repertir retorna count de los elemnentos insertados que no colisionaron a través de la operación `getCount()`

## Ejercicio 2

# SORTING	Nombre de archivo: ejercicio2.cpp

## Letra
Se desea ordenar un conjunto de números enteros, no acotados. Se solicita que implemente un algoritmo basado en el uso de un heap, en particular mediante el uso de la técnica de “heapificación” (heapify en inglés).

### Input

La primera línea de la entrada contiene un número entero positivo N (2 ≤ N ≤ 10^5), el largo del conjunto de números.

Las siguientes N líneas contienen los números del conjunto.

### Salida
Imprime N líneas con los números ordenados de menor a mayor

### Restricciones

- Utilizar la técnica heapify.
- Resolver en orden temporal: O(N log N) promedio, siendo el tamaño del conjunto.
- Resolver en orden espacial auxiliar (sin contar el array de números): O(1)
