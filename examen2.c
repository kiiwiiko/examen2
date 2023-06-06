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
    float calificaciones[NUM_ALUMNOS][NUM_PROGRESOS];

    // Generar calificaciones aleatorias para los alumnos
    srand(time(0)); // Semilla para generar números aleatorios

    for (int i = 0; i < NUM_ALUMNOS; i++) {
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            calificaciones[i][j] = rand() % 11; // Generar números aleatorios entre 0 y 11
        }
    }

    // Imprimir las calificaciones de los alumnos
    printf("Calificaciones de los alumnos:\n");
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        printf("Alumno %d:\n", i + 1);
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            printf("Progreso %d: %.2f\n", j + 1, calificaciones[i][j]);
        }
    }

    // Calcular y mostrar los resultados
    printf("\nResultados:\n");

    // 1- Obtener el promedio de calificaciones de cada alumno durante el semestre
    printf("Promedio de calificaciones de cada alumno:\n");
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        float promedio = obtenerPromedioAlumno(calificaciones[i]);
        printf("Alumno %d: %.2f\n", i + 1, promedio);
    }

    // 2- La nota promedio del grupo de estudiantes para cada progreso
    printf("\nNota promedio del grupo para cada progreso:\n");
    for (int j = 0; j < NUM_PROGRESOS; j++) {
        float promedioGrupo = obtenerPromedioGrupo(calificaciones, j);
        printf("Progreso %d: %.2f\n", j + 1, promedioGrupo);
    }

    // 3- El alumno que obtuvo el mayor promedio de calificación durante el semestre
    int mejorAlumno = encontrarMejorAlumno(calificaciones);
    printf("\nAlumno con el mayor promedio de calificación durante el semestre:\n");
    printf("Alumno %d\n", mejorAlumno + 1);

    getch();
    return 0;
}
