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
    class1

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"


/*
    Three kind of members.
    private: accesible only from within other members of the same class
    public: memebers are accessible from anywhere where the object is visibile
    protected: accessible from other memebers of the same class
*/

// del P = 128*mu*Q*L/pi*d^4 => mu and Q, d
// Re = 4 Q/(pi*D*mu) => mu and Q, d

class fluid_flow
{
    protected:

        scalar mu, u, d;

    public:

        void set_values(scalar a, scalar b, scalar c)
        {
            mu = a;
            u = b;
            d = c;
        };

        scalar flowRate()
        {
            scalar area = (3.14/4)*pow(d,2);
            return u*area;
        };
};

class pressure_cal: public fluid_flow
{
    private:
    scalar length;

        public:
        // void set_values(scalar, scalar, scalar, scalar);
        // Constructor

        void set_length(scalar l)
        {
          length = l;
        };


        scalar Pressure_val()
        {
            return (128*mu*flowRate()*length)/(3.14*pow(d,4));
        };

};

class reynolds_num: public fluid_flow
{
    public:
    scalar cal_Re()
    {
        return (4*flowRate()/(3.14*d*mu));
    };

};
/*
void pressure_cal::set_values(scalar a, scalar b, scalar c, scalar d)
{
    mu = a;
    u = b;
    length = c;
    dia = d;
}
*/

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{



     pressure_cal press1;
     press1.set_values(1e-5, 1.2,3e-3);
     press1.set_length(20e-2);
     reynolds_num Re1;
     Re1.set_values(1e-5, 1.2,3e-3);
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<<"The pressure drop: "<< press1.Pressure_val() << endl;
    Info<<"The Reynold's number: " <<Re1.cal_Re() << endl;
    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
