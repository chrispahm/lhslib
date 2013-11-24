/*
 *
 * maximinLHS.cpp: A C routine for creating Maximin Latin Hypercube Samples
 *                  used in the LHS package
 * Copyright (C) 2013  Robert Carnell
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include "CommonDefines.h"

/*
 * Arrays are passed into this routine to allow R to allocate and deallocate
 * memory within the wrapper function.
 * The R internal random numer generator is used that R can set.seed for
 * testing the functions.
 * Dimensions:  result  K x N
 * Parameters:
 *              N: The number of points to be sampled
 *              K: The number of dimensions (or variables) needed
 *              dup: The duplication factor which affects the number of points
 *                   that the optimization algorithm has to choose from
 * References:  Please see the package documentation
 *
 */
namespace lhslib 
{
    void maximinLHS(int n, int k, int dup, oacpp::matrix<int> & result, CRandom<double> & oRandom)
    {
        size_t nsamples = static_cast<size_t>(n);
        size_t nparameters = static_cast<size_t>(k);
        size_t duplication = static_cast<size_t>(dup);
        // *****  matrix_unsafe<int> m_result = matrix_unsafe<int>(nparameters, nsamples, result);
        /* the length of the point1 columns and the list1 vector */
        size_t len = duplication * (nsamples - 1);
        /* create memory space for computations */
        oacpp::matrix<int> avail = oacpp::matrix<int>(nparameters, nsamples);
        oacpp::matrix<int> point1 = oacpp::matrix<int>(nparameters, len);
        std::vector<int> list1 = std::vector<int>(len);
        std::vector<int> vec = std::vector<int>(nparameters);
        /* squared distance between corner (1,1,1,..) and (N,N,N,...) */
        double squaredDistanceBtwnCorners = static_cast<double>(nparameters * (nsamples - 1) * (nsamples - 1));

        /* index of the current candidate point */
        size_t point_index;
        /* index of the optimum point */
        size_t best;
        /* the squared distance between points */
        size_t distSquared;
        /* the minimum squared distance between points */
        double minSquaredDistBtwnPts;
        /*  The minumum candidate squared difference between points */
        size_t minCandidateSquaredDistBtwnPts;

        /* initialize the avail matrix */
        for (size_t irow = 0; irow < nparameters; irow++)
        {
            for (size_t jcol = 0; jcol < nsamples; jcol++)
            {
                avail(irow, jcol) = static_cast<int>(jcol + 1);
            }
        }

        /*
        * come up with an array of K integers from 1 to N randomly
        * and put them in the last column of result
        */
        for (size_t irow = 0; irow < nparameters; irow++)
        {
            result(irow, nsamples-1) = static_cast<int>(std::floor(oRandom.getNextRandom() * static_cast<double>(nsamples) + 1.0));
        }

        /*
        * use the random integers from the last column of result to place an N value
        * randomly through the avail matrix
        */
        for (size_t irow = 0; irow < nparameters; irow++)
        {
            avail(irow, static_cast<size_t>(result(irow, nsamples - 1) - 1)) = static_cast<int>(nsamples);
        }

        /* move backwards through the result matrix columns */
        for (int count = static_cast<int>(nsamples) - 1; count > 0; count--)
        {
            size_t ucount = static_cast<size_t>(count);
            for (size_t irow = 0; irow < nparameters; irow++)
            {
                for (size_t jcol = 0; jcol < duplication; jcol++)
                {
                    /* create the list1 vector */
                    for (size_t j = 0; j < ucount; j++)
                    {
                        list1[j + ucount*jcol] = avail(irow, j);
                    }
                }
                /* create a set of points to choose from */
                for (size_t jcol = ucount * duplication; jcol > 0; jcol--)
                {
                    point_index = static_cast<size_t>(std::floor(oRandom.getNextRandom() * static_cast<double>(jcol)));
                    point1(irow, jcol-1) = list1[point_index];
                    list1[point_index] = list1[jcol - 1];
                }
            }
            minSquaredDistBtwnPts = DBL_MIN;
            best = 0;
            for (size_t jcol = 0; jcol < duplication * ucount - 1; jcol++)
            {
                /* set min candidate equal to the maximum distance to start */
                minCandidateSquaredDistBtwnPts = static_cast<unsigned int>(std::ceil(squaredDistanceBtwnCorners));
                for (size_t j = ucount; j < nsamples; j++)
                {
                    distSquared = 0;
                    /*
                    * find the distance between candidate points and the points already
                    * in the sample
                    */
                    for (size_t k = 0; k < nparameters; k++)
                    {
                        vec[k] = point1(k, jcol) - result(k, j);
                        distSquared += vec[k] * vec[k];
                    }
                    /*
                    * if the distance squared value is the smallest so far, place it in the
                    * min candidate
                    */
                    if (minCandidateSquaredDistBtwnPts > distSquared) minCandidateSquaredDistBtwnPts = distSquared;
                }
                /*
                * if the candidate point is the largest minimum distance between points so
                * far, then keep that point as the best.
                */
                if (static_cast<double>(minCandidateSquaredDistBtwnPts) > minSquaredDistBtwnPts)
                {
                    minSquaredDistBtwnPts = static_cast<double>(minCandidateSquaredDistBtwnPts);
                    best = jcol;
                }
            }

            /* take the best point out of point1 and place it in the result */
            for (size_t irow = 0; irow < nparameters; irow++)
            {
                result(irow, ucount-1) = point1(irow, best);
            }
            /* update the numbers that are available for the future points */
            for (size_t irow = 0; irow < nparameters; irow++)
            {
                for (size_t jcol = 0; jcol < nsamples; jcol++)
                {
                    if (avail(irow, jcol) == result(irow, count-1))
                    {
                        avail(irow, jcol) = avail(irow, count-1);
                    }
                }
            }
        }

        /*
        * once all but the last points of result are filled in, there is only
        * one choice left
        */
        for (size_t irow = 0; irow < nparameters; irow++)
        {
            result(irow, 0u) = avail(irow, 0u);
        }

    //#ifdef _DEBUG
        int test = lhsCheck(static_cast<int>(nsamples), static_cast<int>(nparameters), result, 1);

        if (test == 0)
        {
            /* the error function should send an error message through R */
            std::runtime_error("Invalid Hypercube\n");
        }
    //#endif

    //#if PRINT_RESULT
        lhsPrint(n, k, result, 0);
    //#endif
    }
} // end namespace