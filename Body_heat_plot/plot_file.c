#include <stdio.h>
#include <stdlib.h>

int main() {
    int N_max=100;
    float temp_min=0;
    float temp_max=40;
    float scale = 3;  // Factor de escala

    char buffer[100];
    int index;
    float temp;
    int maxScale = (float)((temp_max-temp_min) * scale );
    int heights[100] = {0};

    printf("Nombre del sujeto: ");
    //char subject[100];scanf("%s", subject);
    printf("Gianni\n");char subject[100] = "Gianni"; //Hardcodeo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    char filename[150];
    snprintf(filename, sizeof(filename), "%s.csv", subject);
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open the file for reading.\n");
        return 1;
    }
    printf("%.d", sizeof(filename));

    fgets(buffer, sizeof(buffer), file);    // Skippeo header
    while (fscanf(file, "%d,%f\n", &index, &temp) != EOF) {
        heights[index - 1] = (int)((temp - temp_min) * scale);
    }

    for (int y = maxScale; y >= 0; y--) {
        // Cada 5 ploteo escala
        if (y % 5 == 0) {
            printf("%.1f | ", temp_min + (float)y / scale);
        } else {
            printf("     | ");
        }

        for (int x = 0; x < 100; x++) {
            if (heights[x] == y) {
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
