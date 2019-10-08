#include "util.h"
#include <iostream>

vector<vector<NUMS>> mat_dot(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2)
{
	MAT_DOT_CHECK(a1, a2);
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};

	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a2.ray[0].size,
			(NUMS*)malloc(sizeof(NUMS) * a2.ray[0].size),
		};
		for (int j = 0; j < a2.ray[0].size; j++) {
			NUMS total = 0;
			for (int k = 0; k < a2.size; k++) {
				total += a1.ray[i].ray[k] * a2.ray[k].ray[j];
			}
			mat.ray[i].ray[j] = total;
		}
	}
	return mat;
}

vector<vector<NUMS>> mat_mult(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2)
{
	MAT_MULT_CHECK(a1, a2);
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};
	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a1.ray[i].size,
			(NUMS*)malloc(sizeof(NUMS) * a1.ray[i].size),
		};
		#pragma ivdep
		for (int j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] * a2.ray[i].ray[j];
		}
	}
	return mat;
}

vector<vector<NUMS>> mat_add(const vector<vector<NUMS>>& a1, const NUMS& b1)
{
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};

	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a1.ray[0].size,
			(NUMS*)malloc(sizeof(NUMS) * a1.ray[0].size),
		};
		for (int j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] + b1;
		}
	}
	return mat;
}

vector<vector<NUMS>> sigmoid(const vector<vector<NUMS>>& a1)
{
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};
	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a1.ray[i].size,
			(NUMS*)malloc(sizeof(NUMS) * a1.ray[i].size),
		};
		for (int j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = F(a1.ray[i].ray[j]);
		}
	}
	return mat;
}

void delete_vector(vector<vector<vector<NUMS>>>& a1)
{
	for (int i = 0; i < a1.size; i++) {
		delete_vector(a1.ray[i]);
	}
}

void delete_vector(vector<vector<NUMS>>& a1)
{
	for (int i = 0; i < a1.size; i++) {
		delete_vector(a1.ray[i]);
	}
}

void delete_vector(vector<NUMS>& a1)
{
	delete[] a1.ray;
}
