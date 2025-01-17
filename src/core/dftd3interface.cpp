/*
 * < C++ XTB and tblite Interface >
 * Copyright (C) 2020 - 2023 Conrad Hübler <Conrad.Huebler@gmx.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "s-dftd3.h"

#include "src/core/global.h"
#include "src/tools/general.h"

#include "src/core/molecule.h"

#include <iostream>
#include <math.h>
#include <stdio.h>

#include "dftd3interface.h"

DFTD3Interface::DFTD3Interface(const json& controller)
{
    json parameter = MergeJson(DFTD3Settings, controller);

    m_d3_a1 = parameter["d_a1"];
    m_d3_a2 = parameter["d_a2"];
    m_d3_alp = parameter["d_alp"];

    m_d3_s6 = parameter["d_s6"];
    m_d3_s8 = parameter["d_s8"];
    m_d3_s9 = parameter["d_s9"];
    m_bet = parameter["d_bet"];

    m_atm = parameter["d_atm"];
    m_damping = parameter["d_damping"];
    m_functional = parameter["d_func"];

    m_error = dftd3_new_error();
}

DFTD3Interface::~DFTD3Interface()
{
    dftd3_delete_model(&m_disp);
    dftd3_delete_structure(&m_mol);
    dftd3_delete_error(&m_error);
    delete m_coord;
    delete m_attyp;
}

void DFTD3Interface::PrintParameter() const
{
    std::cout << m_d3_s6 << " " << m_d3_s8 << " " << m_d3_s9 << " " << m_d3_a1 << " " << m_d3_a2 << " " << m_d3_alp << std::endl;
}
/*
void DFTD3Interface::LoadParameter()
{
    dftd3_delete_param(&m_param);
    char *cstr = new char[m_functional.length() + 1];
    strcpy(cstr, m_functional.c_str());
    if(m_damping.compare("bj") == 0)
    {
        m_param = dftd3_load_zero_damping(m_error, cstr, m_atm);
    }else if(m_damping.compare("zero") == 0)
    {
        m_param = dftd3_load_rational_damping(m_error, cstr, m_atm);
    }else if(m_damping.compare("bjm") == 0)
    {
        m_param = dftd3_load_mrational_damping(m_error, cstr, m_atm);
    }else if(m_damping.compare("zerom") == 0)
    {
        m_param = dftd3_load_mzero_damping(m_error, cstr, m_atm);
    }else if(m_damping.compare("op") == 0)
    {
        m_param = dftd3_load_optimizedpower_damping(m_error, cstr, m_atm);
    }
    delete [] cstr;
    PrintParameter();
}
*/
void DFTD3Interface::UpdateParameters(const json& controller)
{
    json parameter = MergeJson(DFTD3Settings, controller);
    m_d3_a1 = parameter["d_a1"];
    m_d3_a2 = parameter["d_a2"];
    m_d3_alp = parameter["d_alp"];

    m_d3_s6 = parameter["d_s6"];
    m_d3_s8 = parameter["d_s8"];

    m_d3_s9 = parameter["d_s9"];

    PrintParameter();
}

bool DFTD3Interface::InitialiseMolecule(const std::vector<int>& atomtypes)
{
    m_attyp = new int[atomtypes.size()];
    m_coord = new double[3 * atomtypes.size()];
    for (int i = 0; i < atomtypes.size(); ++i) {
        m_coord[3 * i + 0] = 0 / au;
        m_coord[3 * i + 1] = 0 / au;
        m_coord[3 * i + 2] = 0 / au;
        m_attyp[i] = atomtypes[i];
    }

    m_mol = dftd3_new_structure(m_error, atomtypes.size(), m_attyp, m_coord, NULL, NULL);
    m_disp = dftd3_new_d3_model(m_error, m_mol);

    return true;
}

void DFTD3Interface::UpdateAtom(int index, double x, double y, double z)
{
    m_coord[3 * index + 0] = x / au;
    m_coord[3 * index + 1] = y / au;
    m_coord[3 * index + 2] = z / au;
}

double DFTD3Interface::DFTD3Calculation(double* grad)
{
    double energy = 0;
    double sigma[9];
    dftd3_param param;

    if (m_d3_a1 > 1e-8 || m_d3_a2 > 1e-8 || m_d3_s6 > 1e-8 || m_d3_s8 > 1e-8 || m_d3_s9 > 1e-8) {
        if (m_damping.compare("bj")) {
            param = dftd3_new_rational_damping(m_error, m_d3_s6, m_d3_s8, m_d3_s9, m_d3_a1, m_d3_a2, m_d3_alp);
        } else if (m_damping.compare("zero")) {
            param = dftd3_new_zero_damping(m_error, m_d3_s6, m_d3_s8, m_d3_s9, m_d3_a1, m_d3_a2, m_d3_alp);
        } else if (m_damping.compare("bjm")) {
            param = dftd3_new_mrational_damping(m_error, m_d3_s6, m_d3_s8, m_d3_s9, m_d3_a1, m_d3_a2, m_d3_alp);
        } else if (m_damping.compare("zerom")) {
            param = dftd3_new_mzero_damping(m_error, m_d3_s6, m_d3_s8, m_d3_s9, m_d3_a1, m_d3_a2, m_d3_alp, m_bet);
        } else if (m_damping.compare("op")) {
            param = dftd3_new_optimizedpower_damping(m_error, m_d3_s6, m_d3_s8, m_d3_s9, m_d3_a1, m_d3_a2, m_d3_alp, m_bet);
        }
    } else {
        char* cstr = new char[m_functional.length() + 1];
        strcpy(cstr, m_functional.c_str());
        if (m_damping.compare("bj") == 0) {
            param = dftd3_load_rational_damping(m_error, cstr, m_atm);
        } else if (m_damping.compare("zero") == 0) {
            param = dftd3_load_zero_damping(m_error, cstr, m_atm);
        } else if (m_damping.compare("bjm") == 0) {
            param = dftd3_load_mrational_damping(m_error, cstr, m_atm);
        } else if (m_damping.compare("zerom") == 0) {
            param = dftd3_load_mzero_damping(m_error, cstr, m_atm);
        } else if (m_damping.compare("op") == 0) {
            param = dftd3_load_optimizedpower_damping(m_error, cstr, m_atm);
        }
        delete[] cstr;
    }
    dftd3_update_structure(m_error, m_mol, m_coord, NULL);
    dftd3_get_dispersion(m_error, m_mol, m_disp, param, &energy, grad, sigma);

    dftd3_delete_param(&param);

    return energy;
}

void DFTD3Interface::clear()
{
    dftd3_delete_model(&m_disp);
    dftd3_delete_structure(&m_mol);
    dftd3_delete_error(&m_error);
}
