//
// Created by Massimo Biancalani on 08/10/2019.
//

#ifndef HACKERRANK_CPLUS_PRACTICE_031_DYNAMIC_MEMORY_H
#define HACKERRANK_CPLUS_PRACTICE_031_DYNAMIC_MEMORY_H
struct Workshop {
    unsigned int start_time;
    unsigned int duration;
    unsigned int end_time;
};

struct Available_Workshops {
    unsigned int n;
    Workshop * workshops;
};
Available_Workshops* initialize (int start_time[], int duration[], int n);
int CalculateMaxWorkshops(Available_Workshops* ptr);
#endif //HACKERRANK_CPLUS_PRACTICE_031_DYNAMIC_MEMORY_H
