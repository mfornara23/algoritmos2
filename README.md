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
