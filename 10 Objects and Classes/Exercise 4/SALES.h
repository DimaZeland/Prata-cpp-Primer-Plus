#pragma once

#include <iostream>

namespace SALES {
    class Sales {
    public:
        Sales();

        Sales(const double ar[], int n);

        void showSales() const;

        static const int QUARTERS = 4;
    private:
        double sales[QUARTERS];
        double average;
        double max;
        double min;

    };
}