/*
 * < General Calculator for the Hessian>
 * Copyright (C) 2023 Conrad Hübler <Conrad.Huebler@gmx.net>
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

#include "src/core/global.h"

#include "external/CxxThreadPool/include/CxxThreadPool.h"

#include "src/core/energycalculator.h"

#include <functional>

#pragma once

class HessianThread : public CxxThread {
public:
    HessianThread(const std::string& method, const json& controller, int i, int j, int xi, int xj, bool fullnumerical = true);
    ~HessianThread();

    void setMolecule(const Molecule& molecule);

    int execute() override;

    int I() const { return m_i; }
    int J() const { return m_j; }
    int XI() const { return m_xi; }
    int XJ() const { return m_xj; }
    double DD() const { return m_dd; }
    Matrix Gradient() const { return m_gradient; }

private:
    void Numerical();
    void Seminumerical();
    std::function<void(void)> m_schema;

    EnergyCalculator* m_calculator;
    std::string m_method;
    json m_controller;
    Molecule m_molecule;
    Matrix m_gradient;
    std::vector<std::array<double, 3>> m_geom_ip_jp, m_geom_im_jp, m_geom_ip_jm, m_geom_im_jm;
    int m_i, m_j, m_xi, m_xj;
    bool m_fullnumerical = true;
    double m_dd = 0;
    double m_d = 1e-5;
};

class Hessian {
public:
    Hessian(const std::string& method, const json& controller, int threads);

    void setMolecule(const Molecule& molecule);

    void CalculateHessian(bool fullnumerical = false);

private:
    void CalculateHessianNumerical();
    void CalculateHessianSemiNumerical();
    void FiniteDiffHess();

    Vector ConvertHessian(Matrix& hessian);

    Matrix m_eigen_geometry, m_eigen_gradient, m_hessian;
    Molecule m_molecule;
    std::string m_method;
    json m_controller;
    int m_threads = 1;
};
