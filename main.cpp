#include "histogram.h"
#include <iostream>
#include "svg.h"
#include <curl/curl.h>
using namespace std;

vector<double> input_numbers(istream& in, size_t count);



Input read_input(istream& in, bool prompt)
{
    Input data;

    if(prompt)
    {
        cerr << "Enter number count: ";
    }
    size_t number_count;
    in >> number_count;

    if(prompt)
    {
        cerr << "Enter numbers: ";
    }
    data.numbers = input_numbers(in, number_count);
    if(prompt)
    {
        cerr << "Enter column count: ";
    }
    cin >> data.bin_count;

    return data;
}

int main(int argc, char* argv[]) {

    if (argc > 1) {
        cerr << "argc = " << argc << endl;
        for (size_t i = 0; i < argc; i++) {
            cerr << "argv[" << i << "] = " << argv[i] << endl;
        }
        return 0;
    }

    curl_global_init(CURL_GLOBAL_ALL);

    Input input = read_input(cin, true);
    vector<size_t> bins = make_histogram(input);
    show_histogram_svg(bins, input.bin_count);

    return 0;
}


vector<double> input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}
