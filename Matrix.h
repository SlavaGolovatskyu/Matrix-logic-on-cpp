#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;

class Matrix {
private:
	int columns;
	int rows;
	int count_nums;
	vector<float> matrix;
public:
	Matrix(int columns, int rows);
	int get_colums();
	int get_rows();
	int get_all_nums();
	vector<float> get_matrix();
	void set_default_settings(int cols, int rows);
	void fill_matrix();
	void print_matrix();
	Matrix& operator+(const Matrix &other_matrix);
	Matrix& operator+=(const Matrix &other_matrix);
	Matrix& operator-(const Matrix &other_matrix);
	Matrix& operator-=(const Matrix &other_matrix);
	friend ostream& operator<<(ostream &out, const Matrix &mat);
};

#endif
