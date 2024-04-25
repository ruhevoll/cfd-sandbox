/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2024 AUTHOR,AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    class2

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

class complex_num
    {
         public:
            scalar r;
            scalar i;
             complex_num();
             complex_num(scalar, scalar);
             complex_num operator +(complex_num&);
    };

complex_num::complex_num()
{
    r = 1.0;
    i = 2.0;
}

complex_num::complex_num(scalar a, scalar b)
{
    r = a;
    i = b;
}
complex_num complex_num::operator +(complex_num& num1)
{
    complex_num result;
    result.r = r + num1.r;
    result.i = i + num1.i;

    return result;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{

    // operator overloading a = 1 + 2i; b = 2 + 7i; a + b

    complex_num n1(1.0, 2.0);
    complex_num n2(4.2,1.3);
    complex_num res = n1 + n2;

    Info << "The sum of complex numbers is: " << res.r <<"+"<<res.i<<"i"<< endl;


    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
