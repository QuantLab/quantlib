
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

/*! \file controlvariatedpathpricer.cpp

    $Source$
    $Log$
    Revision 1.7  2001/05/24 13:57:52  nando
    smoothing #include xx.hpp and cutting old Log messages

*/

#include "ql/MonteCarlo/controlvariatedpathpricer.hpp"

namespace QuantLib {

    namespace MonteCarlo {

        ControlVariatedPathPricer::ControlVariatedPathPricer(
            Handle<PathPricer > pricer,
            Handle<PathPricer > controlVariate,
            double controlVariateValue)
        : pricer_(pricer), controlVariate_(controlVariate),
          controlVariateValue_(controlVariateValue) {
            isInitialized_=true;
        }

        double ControlVariatedPathPricer::value(const Path &path) const {
            QL_REQUIRE(isInitialized_,
                "SinglePathControlVariatedPricer not initialized");
            return pricer_->value(path) - controlVariate_->value(path) +
                controlVariateValue_;
        }

    }

}
