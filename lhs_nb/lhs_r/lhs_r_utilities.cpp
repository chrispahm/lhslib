#include "lhs_r_utilities.h"

namespace lhs_r 
{
    void findorder_zero(const Rcpp::NumericVector & v, Rcpp::IntegerVector & order)
    {
        std::vector<double> vlocal = Rcpp::as<std::vector<double> >(v);
        std::vector<int> orderlocal(v.size());
        bclib::findorder_zero(vlocal, orderlocal);
        order = Rcpp::IntegerVector::import(orderlocal.begin(), orderlocal.end());
        // TODO: could we have done orderlocal = Rcpp::as<std::vector<int> >(order); ??
    }

    Rcpp::NumericMatrix convertIntegerToNumericLhs(const bclib::matrix<int> & intMat)
    {
        bclib::matrix<int>::size_type rows;
        bclib::matrix<int>::size_type cols;
        rows = intMat.rowsize();
        cols = intMat.colsize();
        Rcpp::NumericMatrix result(rows, cols);
        Rcpp::NumericVector eps = Rcpp::runif(static_cast<int>(rows*cols));
        unsigned int counter = 0;
        // I think this is right (iterate over rows within columns
        for (bclib::matrix<int>::size_type col = 0; col < cols; col++)
        {
            for (bclib::matrix<int>::size_type row = 0; row < rows; row++)
            {
                result(row, col) = static_cast<double>(intMat(row, col) - 1) + eps[counter];
                result(row, col) /= static_cast<double>(rows);
                counter++;
            }
        }

        return result;
    }

    Rcpp::NumericMatrix convertIntegerToNumericLhs(const Rcpp::IntegerMatrix & intMat)
    {
        int n = intMat.rows();
        int k = intMat.cols();
        Rcpp::NumericMatrix result(n, k);
        Rcpp::NumericVector eps = Rcpp::runif(static_cast<int>(n*k));
        unsigned int counter = 0;
        // I think this is right (iterate over rows within columns
        for (bclib::matrix<int>::size_type col = 0; col < static_cast<unsigned int>(k); col++)
        {
            for (bclib::matrix<int>::size_type row = 0; row < static_cast<unsigned int>(n); row++)
            {
                result(row, col) = static_cast<double>(intMat(row, col) - 1) + eps[counter];
                result(row, col) /= static_cast<double>(n);
                counter++;
            }
        }

        return result;
    }

    Rcpp::NumericMatrix convertMatrixToNumericLhs(const bclib::matrix<double> & intMat)
    {
        std::vector<double>::iterator i = intMat.getDataVector().begin();
        bclib::matrix<int>::size_type rows = intMat.rowsize();
        bclib::matrix<int>::size_type cols = intMat.colsize();
        Rcpp::NumericMatrix result(rows, cols, i);

        return result;
    }

    Rcpp::IntegerVector runifint(unsigned int n, int min_int, int max_int)
    {
        Rcpp::NumericVector r = Rcpp::runif(n);
        Rcpp::IntegerVector intv(n);
        Rcpp::IntegerVector::iterator intv_it;
        Rcpp::NumericVector::iterator r_it;
        double range = static_cast<double>(max_int + 1 - min_int);
        for (intv_it = intv.begin(), r_it = r.begin();
                intv_it != intv.end() && r_it != r.end(); ++intv_it, ++r_it)
        {
            *intv_it = min_int + static_cast<int>(floor(static_cast<double>(*r_it) * range));
        }
        return intv;
    }
} // end namespace
