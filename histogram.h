#pragma once
#include <iostream>
#include <vector>
using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<double> input_numbers(size_t count);

void show_histogram_text(vector <size_t> bins);

struct Input {
    vector<double> numbers;
    size_t bin_count;
};

vector <size_t> make_histogram(Input input);
