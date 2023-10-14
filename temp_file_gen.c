#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random floating-point number between a and b
float randomFloat(float a, float b) {
    return a + ((float) rand() / RAND_MAX) * (b - a);
}

int main() {
    int N=20;
    int temp_min=36;
    int temp_max=36;
    printf("Temperature data simulation. Insert subject name to simulated temperature evolution.\n");

    // Seed the random number generator
    srand(time(0));

    // Get the subject name from the user
    char subject[100];
    printf("Enter the subject name: ");
    scanf("%s", subject);

    // Get the current time and format it
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char timestamp[20];
    strftime(timestamp, 20, "%Y%m%d%H%M%S", tm_info);

    // Generate the filename
    char filename[150];
    //snprintf(filename, sizeof(filename), "%s_%s.csv", subject, timestamp);
    snprintf(filename, sizeof(filename), "%s.csv", subject);

    // Open the file for writing
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open the file for writing.\n");
        return 1;
    }

    // Write header
    fprintf(file, "Index,Temperature\n");

    // Generate and write 100 simulated body temperatures
    int i;
    for (i = 0; i < N; ++i) {
        float temp = randomFloat(temp_min,temp_max);
        fprintf(file, "%d,%.2f\n", i + 1, temp);
    }

    // Close the file
    fclose(file);

    printf("Simulated temperature data has been written to '%s'.\n", filename);
    return 0;
}
