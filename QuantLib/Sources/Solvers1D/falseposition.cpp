
/*
 * Copyright (C) 2000-2001 QuantLib Group
 *
 * This file is part of QuantLib.
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.sourceforge.net/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated
 * in the QuantLib License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You should have received a copy of the license along with this file;
 * if not, contact ferdinando@ametrano.net
 * The license is also available at http://quantlib.sourceforge.net/LICENSE.TXT
 *
 * The members of the QuantLib Group are listed in the Authors.txt file, also
 * available at http://quantlib.sourceforge.net/Authors.txt
*/

/*! \file falseposition.cpp
    \brief false-position 1-D solver

    $Source$
    $Log$
    Revision 1.22  2001/05/24 13:57:52  nando
    smoothing #include xx.hpp and cutting old Log messages

*/

/* The implementation of the algorithm was inspired by
 * "Numerical Recipes in C", 2nd edition, Press, Teukolsky, Vetterling, Flannery
 * Chapter 9
 */


#include "ql/Solvers1D/falseposition.hpp"

namespace QuantLib {

    namespace Solvers1D {

        double FalsePosition::solve_(const ObjectiveFunction& f,
                                     double xAccuracy) const {

            double fl, fh, xl, xh, dx, del, froot;

            // Identify the limits so that xl corresponds to the low side
            if (fxMin_ < 0.0) {
                xl=xMin_;
                fl = fxMin_;
                xh=xMax_;
                fh = fxMax_;
            } else {
                xl=xMax_;
                fl = fxMax_;
                xh=xMin_;
                fh = fxMin_;
            }
            dx=xh-xl;
            while (evaluationNumber_<=maxEvaluations_) {  // False position loop
                // Increment with respect to latest value
                root_=xl+dx*fl/(fl-fh);
                froot=f(root_);
                evaluationNumber_++;
                if (froot < 0.0) {              // Replace appropriate limit
                    del=xl-root_;
                    xl=root_;
                    fl=froot;
                } else {
                    del=xh-root_;
                    xh=root_;
                    fh=froot;
                }
                dx=xh-xl;
                // Convergence criterion
               if (QL_FABS(del) < xAccuracy || froot == 0.0)  {
                   return root_;
               }
            }

            throw Error("FalsePosition: maximum number of "
                        "function evaluations (" +
                        IntegerFormatter::toString(maxEvaluations_) +
                        ") exceeded");
            QL_DUMMY_RETURN(0.0);
        }

    }

}
