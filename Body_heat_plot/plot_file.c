#include <stdio.h>
#include <stdlib.h>

int main() {
    int N=80;
    float temp_min=35.8;
    float temp_max=38.0;

    printf("Nombre del sujeto: ");
    char subject[100];scanf("%s", subject);
    //printf("Gianni\n");char subject[100] = "Gianni"; //Hardcoded !!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    char filename[150];
    snprintf(filename, sizeof(filename), "%s.csv", subject);
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open the file for reading.\n");
        return 1;
    }

    // Skip header line
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    int index;
    float temp;
    int scale = 20;  // Factor de escala
    int maxScale = 38 * scale - 36 * scale; // Asumo rango 38-36
    int heights[100] = {0};

    while (fscanf(file, "%d,%f\n", &index, &temp) != EOF) {
        heights[index - 1] = (int)((temp - 36.0) * scale);
    }

    for (int y = maxScale; y >= 0; y--) {
        // Cada 5
        if (y % 5 == 0) {
            printf("%.1f | ", 36.0 + (float)y / scale);
        } else {
            printf("     | ");
        }

        for (int x = 0; x < 100; x++) {
            if (heights[x] > y) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Add the horizontal axis
    printf("      ");
    for (int x = 0; x < 100; x++) {
        printf("-");
    }
    printf("\n");


    //plotScatter(heights,scale);

    fclose(file);

    return 0;
}
