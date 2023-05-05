#include <stdio.h>

int main() {
    FILE *source_file, *destination_file;
    char source_filename[] = "source.txt";
    char destination_filename[] = "destination.txt";
    char ch;

    // open source file for reading
    source_file = fopen(source_filename, "r");
    if (source_file == NULL) {
        printf("Error: Could not open file %s\n", source_filename);
        return 1;
    }

    // open destination file for writing
    destination_file = fopen(destination_filename, "w");
    if (destination_file == NULL) {
        printf("Error: Could not create file %s\n", destination_filename);
        return 1;
    }

    // copy contents of source file to destination file
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, destination_file);
    }

    // close files
    fclose(source_file);
    fclose(destination_file);

    printf("File copied successfully.\n");

    return 0;
}
