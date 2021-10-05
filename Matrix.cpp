#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int columns = 0, int rows = 0)
{
    set_default_settings(columns, rows);
    fill_matrix();  	
}

int Matrix::get_colums() {
	return this->columns;
}

int Matrix::get_rows() {
	return this->rows;
}

int Matrix::get_all_nums() {
	return this->count_nums;
}

vector<float> Matrix::get_matrix() {
	return this->matrix;
}

void Matrix::set_default_settings(int cols, int rows) {
    this->columns = cols;
    this->rows = rows;
    this->count_nums = cols * rows;
}

void Matrix::fill_matrix() {
	if (columns == 0 && rows == 0) cout << "matrix cant be 0x0" << endl;
	else {
		for(int i = 1; i<=count_nums; i++) {
			float n;
			cout << "number#" << i << " from the " << count_nums << endl;
			cin >> n;
			matrix.push_back(n);
		}
	}
}

void Matrix::print_matrix() {
    /* 
        For example: creating matrix 2x2 ( Matrix m(2,2); )
        2x2
        2 5 4 2 -> 2 5
                   4 2
        3x2 
        1 3 4 2 1 2 -> 1 3 
                       4 2 
                       1 2 
        4x2 
        1 3 4 5 1 2 2 2 -> 1 3 
                           4 5
                           1 2
                           2 2 
        2x3
        2 3 2 1 5 6 -> 2 3 2
                       1 5 6
    */
	for(int i=0; i<matrix.size(); i++)
		if ((i + 1) % rows == 0) cout << matrix[i] << endl;
		else cout << matrix[i] << "\t";
}


ostream& operator<<(ostream &out, const Matrix &mat) {
	out << "Columns: " << mat.columns << endl;
	out << "Rows: " << mat.rows << endl;
	out << "Matrix: " << endl;
	for(int i=0; i<mat.matrix.size(); i++) 
		if ((i + 1) % mat.rows == 0) out << mat.matrix[i] << endl;
		else out << mat.matrix[i] << "\t";
	return out;
}


// OVERLOADING OPERATORS +, +=, -, -=, *, *=, /, /= 

Matrix& Matrix::operator+(const Matrix &other_matrix) {
	if (this->columns != other_matrix.columns || this->rows != other_matrix.rows) cout << "matrixes different" << endl;
	else {
		for(int i=0; i<matrix.size(); i++) {
			matrix[i] += other_matrix.matrix[i];
		}
	}
}

Matrix& Matrix::operator+=(const Matrix &other_matrix) {
	if (this->columns != other_matrix.columns || this->rows != other_matrix.rows) cout << "matrixes different" << endl;
	else {
		for(int i=0; i<matrix.size(); i++) {
			matrix[i] += other_matrix.matrix[i];
		}
	}
}

Matrix& Matrix::operator-(const Matrix &other_matrix) {
	if (this->columns != other_matrix.columns || this->rows != other_matrix.rows) cout << "matrixes different" << endl;
	else {
		for(int i=0; i<matrix.size(); i++) {
			matrix[i] -= other_matrix.matrix[i];
		}
	}
}

Matrix& Matrix::operator-=(const Matrix &other_matrix) {
	if (this->columns != other_matrix.columns || this->rows != other_matrix.rows) cout << "matrixes different" << endl;
	else {
		for(int i=0; i<matrix.size(); i++) {
			matrix[i] -= other_matrix.matrix[i];
		}
	}
}



