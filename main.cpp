#include <iostream>
#include "lib.h"
using namespace std;

int main() {
    system("chcp 65001");
    const char *F1 = R"(C:\Users\Dismal Lord\Desktop\F1.txt)";
    const char *F2 = "F2.txt";

    int matrix[M][N];

    view_file(F1);

    create_matrix(F1, matrix);

    print_matrix(matrix, F2);

    count_negative_elements(matrix, F2);

    product_of_positive_elements_with_zero(matrix, F2);

    max_elements_by_row(matrix, F2);

    int *dynamic_array;

    create_dynamic_array(matrix, dynamic_array, F2);

    delete[] dynamic_array;

    const char *input_filename = R"(C:\Users\Dismal Lord\Desktop\F3.txt)";

    const char *output_filename = "F4.txt";

    view_file(input_filename);

    copy_digits(input_filename, output_filename);

    calculate_average_lengths(input_filename, output_filename);

    return 0;
}
