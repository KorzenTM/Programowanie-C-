#include <iostream>
#include <chrono>

int main()
{
    int N=180000;
    std:: chrono::time_point<std::chrono::system_clock> start , end , start_1 , end_1;
    start = std:: chrono:: system_clock:: now();
    for(unsigned n = 1; n <= N; ++n)
    {
        int *p = new int [n];
        delete [] p;
    }
    end = std:: chrono:: system_clock:: now();
    std:: chrono:: duration<double> elapsed_seconds = end - start;

    std:: cout << "Dla N rownego = " << N << " czas wykonania wynosi: " << elapsed_seconds.count() << " s" << std:: endl;
    std:: cout << "Czas wykonania pojedynczej pary instrukcji new/delete jest rowny = " << elapsed_seconds.count()/N << " s" << std::endl;

    start_1 = std:: chrono:: system_clock:: now();

    for(unsigned n = 1; n <= N; ++n)
    {
        int * tab[n];
    }

    end_1 = std:: chrono:: system_clock:: now();
    std:: chrono:: duration<double> elapsed_seconds_1 = end_1 - start_1;

    std:: cout << "Koszt pojedyczego dodawania: " << elapsed_seconds_1.count()/N << std::endl;
    return 0;
}

