#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float randomFloat(float a, float b) {
    return a + ((float) rand() / RAND_MAX) * (b - a);
}

int main() {
    int N=100;
    int temp_min=36;
    int temp_max=38;
    printf("Simulación de temperatura corporal. Genera un archivo con la evolución de temperatura para un sujeto de nombre dado.\n");

    srand(time(0));
    char subject[100];
    printf("Nombre del sujeto: ");
    scanf("%s", subject);

    // Tiempo y formato
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char timestamp[20];
    strftime(timestamp, 20, "%Y%m%d%H%M%S", tm_info);

    // Flename
    char filename[150];
    //snprintf(filename, sizeof(filename), "%s_%s.csv", subject, timestamp);
    snprintf(filename, sizeof(filename), "%s.csv", subject);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("No se pudo abrir para escribir.\n");
        return 1;
    }

    // Header
    fprintf(file, "Index,Temperature\n");

    // Generar temp
    int i;
    for (i = 0; i < N; ++i) {
        float temp = randomFloat(temp_min,temp_max);
        fprintf(file, "%d,%.2f\n", i + 1, temp);
    }

    // Close the file
    fclose(file);

    printf("Se genero el archivo '%s'.\n", filename);
    return 0;
}
