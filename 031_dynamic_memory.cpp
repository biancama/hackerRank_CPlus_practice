//
// Created by Massimo Biancalani on 08/10/2019.
//

#include "031_dynamic_memory.h"
#include <cstdlib>
using namespace std;
Available_Workshops* initialize (int start_time[], int duration[], int n) {
    Available_Workshops *result = new Available_Workshops;
    result->n = n;
    result->workshops = new Workshop[n];
    for (int i = 0; i < n; ++i) {
        result->workshops[i].start_time = start_time[i];
        result->workshops[i].end_time = start_time[i] + duration[i];
        result->workshops[i].duration = duration[i];
    }
    return result;
}
bool isOverlapping (const Workshop*const ptr, int max_end_time) {
    return ptr->start_time < max_end_time;
}
int CalculateMaxWorkshops(Available_Workshops* ptr) {

    qsort(ptr->workshops, ptr->n, sizeof (Workshop), [] (const void* a, const void*b){
        Workshop workshop1 = *static_cast<const Workshop*>(a);
        Workshop workshop2 = *static_cast<const Workshop*>(b);
        if (workshop1.end_time == workshop2.end_time) {
            if (workshop1.start_time < workshop2.start_time) {
                return 1;
            } else {
                return -1;
            }
        } else if (workshop1.end_time < workshop2.end_time) {
            return - 1;
        } else {
            return 1;
        }
        ///return 0;
    } );
    int result = 0;
    int max_end_date = 0;
    for (int i = 0; i < ptr->n; ++i) {
        if (!isOverlapping(&ptr->workshops[i], max_end_date)) {
            result++;
            max_end_date = ptr->workshops[i].end_time;
        }
    }
    return result;
}