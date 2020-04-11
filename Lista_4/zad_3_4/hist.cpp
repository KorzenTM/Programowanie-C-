#include <iostream>
#include "hist.h"

Hist::Hist(std:: vector<double> w)
        :vec(std::move(w))
{
    std:: cout << "The data have been accepted!" << std:: endl;
}

void Hist::show_sort_data()
{
    std:: cout << "(";
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        std:: cout << vec[i] << ", ";
    }
    std:: cout << ")";
}

void Hist::draw_hist()
{
    double k = sqrt(vec.size()); //liczba przedziałów histogramu
    double max_value = *max_element(vec.begin(), vec.end()); //element najwiekszy
    double min_value = *min_element(vec.begin(), vec.end()); //element najmniejszy
    double h = (max_value - min_value) / k; //szerokość przedziałow
    std:: vector<double> range;
    double sum = 0.0;
    //Liczenie zakresów przedzialowych
    do
    {
        range.push_back(sum);
        std:: cout << sum << std:: endl;
        sum += h;
    }while (sum <= 1);
    //Zliczanie liczebnosci w danych zakresach
    int number = 0; //liczebnosc w poszczegolnych przedzialach klasowych
    for (unsigned int i = 0; i < range.size(); i++)
    {
        for (unsigned int j = 0; j < vec.size(); j++)
        {
            if (vec[j] >= range[i] and vec[j] < range[i+1])
            {
                number++;
            }
        }
        if (i+1 < range.size())
        {
            std:: cout.width(10);
            std:: cout << std::right <<range[i];
            std:: cout << "-";
            std:: cout.width(10);
            std:: cout << std::left << range[i+1];
            std:: cout.width(5);
            std:: cout << number;
            for (int k = 0; k < number; k++)
                std:: cout << "*";
            std:: cout << "\n";
            number=0;
        } else
            break;

    }



}

