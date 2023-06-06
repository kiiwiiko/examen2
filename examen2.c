#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define NUM_ALUMNOS 23
#define NUM_PROGRESOS 3

// Función para obtener el promedio de calificaciones de un alumno en un progreso
float obtenerPromedioAlumno(float calificaciones[NUM_PROGRESOS]) {
    float suma = 0;
    for (int i = 0; i < NUM_PROGRESOS; i++) {
        suma += calificaciones[i];
    }
    return suma / NUM_PROGRESOS;
}

// Función para obtener el promedio del grupo de estudiantes en un progreso
float obtenerPromedioGrupo(float calificacionesGrupo[NUM_ALUMNOS][NUM_PROGRESOS], int progreso) {
    float suma = 0;
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        suma += calificacionesGrupo[i][progreso];
    }
    return suma / NUM_ALUMNOS;
}

// Función para encontrar al alumno con el mayor promedio de calificación en el semestre
int encontrarMejorAlumno(float calificacionesGrupo[NUM_ALUMNOS][NUM_PROGRESOS]) {
    int mejorAlumno = 0;
    float mejorPromedio = obtenerPromedioAlumno(calificacionesGrupo[0]);

    for (int i = 1; i < NUM_ALUMNOS; i++) {
        float promedio = obtenerPromedioAlumno(calificacionesGrupo[i]);
        if (promedio > mejorPromedio) {
            mejorPromedio = promedio;
            mejorAlumno = i;
        }
    }
    return mejorAlumno;
}

int main(int argc, char const *argv[])
{
    getch();
    return 0;
}
