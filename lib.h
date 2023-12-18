#define M 4
#define N 5

void view_file(const char *filename);

void create_matrix(const char *F1, int matrix[M][N]);

void print_matrix(int matrix[M][N], const char *F2);

void count_negative_elements(int matrix[M][N], const char *F2);

void product_of_positive_elements_with_zero(int matrix[M][N], const char *F2);

void max_elements_by_row(int matrix[M][N], const char *F2);

void create_dynamic_array(int matrix[M][N], int *&dynamic_array, const char *F2);

void copy_digits(const char *input_filename, const char *output_filename);

void calculate_average_lengths(const char *input_filename, const char *output_filename);