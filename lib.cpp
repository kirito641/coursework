#include "lib.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

void view_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == nullptr) {
        cout << "Неможливо відкрити файл\n";
        return;
    }

    cout << "\nДані у файлі " << filename << endl;

    char s[100];
    while (fgets(s, 100, f)) {
        cout << s;
    }

    fclose(f);
}

void create_matrix(const char *F1, int matrix[M][N]) {
    FILE *f = fopen(F1, "r");
    if (f == nullptr) {
        cout << "Неможливо відкрити файл\n";
        return;
    }

    int i = 0, j;
    char s[100];
    while (fgets(s, 100, f)) {
        istringstream iss(s);
        j = 0;
        while (iss >> matrix[i][j]) {
            j++;
        }
        i++;
    }

    fclose(f);
}

void print_matrix(int matrix[M][N], const char *F2) {
    cout << "\nДані матриці:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    FILE *f = fopen(F2, "w");
    if (f == nullptr) {
        cout << "Не вдалося відкрити файл для запису\n";
        return;
    }

    fprintf(f, "Матриця:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            fprintf(f, "%d ", matrix[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

void count_negative_elements(int matrix[M][N], const char *F2) {
    int negative_count = 0;
    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] < 0) {
                negative_count++;
            }
        }
    }
    FILE *f = fopen(F2, "a");
    if (f == nullptr) {
        cout << "Не вдалося відкрити файл для запису\n";
        return;
    }
    fprintf(f, "\nКількість від'ємних елементів у перших трьох рядках=%d\n", negative_count);
    cout << "\nКількість від'ємних елементів у перших трьох рядках=" << negative_count << endl;
    fclose(f);
}

void product_of_positive_elements_with_zero(int matrix[M][N], const char *F2) {
    FILE *f = fopen(F2, "a");
    if (f == nullptr) {
        cout << "Не вдалося відкрити файл для запису\n";
        return;
    }

    fprintf(f, "\nДобуток додатніх елементів рядків, які містять хоча б один нульовий елемент: ");

    cout << "\nДобуток додатніх елементів рядків, які містять хоча б один нульовий елемент:";

    long int product = 1;

    for (int i = 0; i < M; ++i) {
        bool contains_zero = false;

        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == 0) {
                contains_zero = true;
            }
            if (contains_zero) {
                for (int k = 0; k < N; ++k) {
                    if (matrix[i][k] > 0) {
                        product *= matrix[i][k];
                    }
                }
                break;
            }
        }

    }
    fprintf(f, "%ld\n", product);
    fclose(f);
    cout << product << endl;
}

void max_elements_by_row(int matrix[M][N], const char *F2) {
    FILE *f = fopen(F2, "a");
    if (f == nullptr) {
        cout << "Не вдалося відкрити файл для запису\n";
        return;
    }

    fprintf(f, "\nНайбільші за модулем елементи рядків: ");

    cout << endl << "Найбільші за модулем елементи рядків:";
    int vector[M];
    for (int i = 0; i < M; ++i) {
        vector[i] = matrix[i][0];
        for (int j = 1; j < N; ++j) {
            if (abs(matrix[i][j]) > abs(vector[i])) {
                vector[i] = matrix[i][j];
            }
        }
        fprintf(f, "%d ", vector[i]);
        cout << vector[i] << " ";
    }
    fprintf(f, "\n");
    fclose(f);
    cout << endl;
}

//перейменуй цю хуйню
void create_dynamic_array(int matrix[M][N], int *&dynamic_array, const char *F2) {
    int size = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (abs(matrix[i][j] - 5) <= 10) {
                size++;
            }
        }
    }

    dynamic_array = new int[size];
    FILE *f = fopen(F2, "a");
    if (f == nullptr) {
        cout << "Не вдалося відкрити файл F2 для запису\n";
        return;
    }
    fprintf(f, "\nЕлементи, які відрізняються від числа 5 не більше ніж на 10:");
    int temp = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (abs(matrix[i][j] - 5) <= 10) {
                dynamic_array[temp] = matrix[i][j];
                temp++;
                fprintf(f, " %d\t", dynamic_array[temp - 1]);
            }
        }
    }
    fprintf(f, "\n");
    fclose(f);

    cout << "\nЕлементи, які відрізняються від числа 5 не більше ніж на 10:";
    for (int i = 0; dynamic_array[i] < temp; ++i) {
        cout << " " << dynamic_array[i];
    }
}


double average_word_length(const char *words[], int word_count) {
    if (word_count == 0) {
        return 0.0;
    }

    int total_length = 0;

    for (int i = 0; i < word_count; ++i) {
        total_length += strlen(words[i]);
    }

    return (double) total_length / word_count;
}

double calculate_average_word_length(const char *line) {
    const char *delimiter = " ";
    const int max_words = 100; // Максимальна кількість слів (змініть за потребою)

    const char *words[max_words];
    int word_count = 0;

    char *token = strtok((char *) line, delimiter);
    while (token != nullptr && word_count < max_words) {
        words[word_count++] = token;
        token = strtok(nullptr, delimiter);
    }

    return average_word_length(words, word_count);
}

void copy_digits(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == nullptr) {
        printf("Could not open input file: %s\n", input_filename);
        return;
    }

    if (output_file == nullptr) {
        printf("Could not open output file: %s\n", output_filename);
        fclose(input_file);
        return;
    }

    printf("\nNew lines with digits:\n");
    fprintf(output_file, "New lines with digits:\n");

    int ch;

    while ((ch = fgetc(input_file)) != EOF) {
        if (ch == '\n') {
            printf("\n");
            fprintf(output_file, "\n");
        } else if (isdigit(ch)) {
            fputc(ch, output_file);
            putchar(ch);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void calculate_average_lengths(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "a");

    if (input_file == nullptr) {
        printf("Could not open input file: %s\n", input_filename);
        return;
    }

    if (output_file == nullptr) {
        printf("Could not open output file: %s\n", output_filename);
        fclose(input_file);
        return;
    }

    char line[5000];
    int line_number = 1;

    while (fgets(line, sizeof(line), input_file) != nullptr) {
        double avg_length = calculate_average_word_length(line);
        fprintf(output_file, "\nAverage word length in line %d: %.2f\n", line_number, avg_length);
        line_number++;
        cout << "\nAverage word length in line " << line_number << ": " << fixed << setprecision(2) << avg_length << endl;
    }

    fclose(input_file);
    fclose(output_file);

}