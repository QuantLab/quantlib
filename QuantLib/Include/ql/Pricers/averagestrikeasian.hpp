
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

/*! \file averagestrikeasian.hpp

    $Source$
    $Log$
    Revision 1.3  2001/05/24 13:57:51  nando
    smoothing #include xx.hpp and cutting old Log messages

*/

#ifndef quantlib_pricers_average_strike_asian_pricer_h
#define quantlib_pricers_average_strike_asian_pricer_h

#include "ql/options.hpp"
#include "ql/rate.hpp"
#include "ql/MonteCarlo/mcpricer.hpp"

namespace QuantLib {

    namespace Pricers {
        /*! This is an example of Monte Carlo pricer that
            uses a control variate.
        */

        class AverageStrikeAsian: public McPricer {
        public:
            AverageStrikeAsian(Option::Type type, double underlying,
               double strike, Rate dividendYield, Rate riskFreeRate,
               double residualTime, double volatility, int timesteps,
               long samples, long seed = 0);
        };

    }

}


#endif
