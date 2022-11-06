/*
 * <Simple UFF implementation for Cucuma. >
 * Copyright (C) 2022 Conrad Hübler <Conrad.Huebler@gmx.net>
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

/*
 * originally published at: J. Am. Chem. Soc. (1992) 114(25) p. 10024-10035.
 * as universal force field parameters
 */

#pragma once

#include <vector>

const std::vector<std::vector<double>> UFFParameters{
    { 0.01, 180, 0.4, 5000, 12, 10.0, 0, 0, 9.66, 14.92, 0.7 }, // Du    0
    { 0.354, 180, 2.886, 0.044, 12, 0.712, 0, 0, 4.528, 6.9452, 0.371 }, // H_ 1
    { 0.354, 180, 2.886, 0.044, 12, 0.712, 0, 0, 4.528, 6.9452, 0.371 }, // D 2
    { 0.46, 83.5, 2.886, 0.044, 12, 0.712, 0, 0, 4.528, 6.9452, 0.371 }, // H_b 3
    { 0.849, 90, 2.362, 0.056, 15.24, 0.098, 0, 0, 9.66, 14.92, 1.3 }, // He4+4 4
    { 1.336, 180, 2.451, 0.025, 12, 1.026, 0, 2, 3.006, 2.386, 1.557 }, // Li 5
    { 1.074, 109.47, 2.745, 0.085, 12, 1.565, 0, 2, 4.877, 4.443, 1.24 }, // Be3+2 6
    { 0.838, 109.47, 4.083, 0.18, 12.052, 1.755, 0, 2, 5.11, 4.75, 0.822 }, // B_3 7
    { 0.828, 120, 4.083, 0.18, 12.052, 1.755, 0, 2, 5.11, 4.75, 0.822 }, // B_2 8
    { 0.757, 109.47, 3.851, 0.105, 12.73, 1.912, 2.119, 2, 5.343, 5.063, 0.759 }, // C_3 9
    { 0.729, 120, 3.851, 0.105, 12.73, 1.912, 0, 2, 5.343, 5.063, 0.759 }, // C_R 10
    { 0.732, 120, 3.851, 0.105, 12.73, 1.912, 0, 2, 5.343, 5.063, 0.759 }, // C_2 11
    { 0.706, 180, 3.851, 0.105, 12.73, 1.912, 0, 2, 5.343, 5.063, 0.759 }, // C_1 12
    { 0.7, 106.7, 3.66, 0.069, 13.407, 2.544, 0.45, 2, 6.899, 5.88, 0.715 }, // N_3 13
    { 0.699, 120, 3.66, 0.069, 13.407, 2.544, 0, 2, 6.899, 5.88, 0.715 }, // N_R 14
    { 0.685, 111.2, 3.66, 0.069, 13.407, 2.544, 0, 2, 6.899, 5.88, 0.715 }, // N_2 15
    { 0.656, 180, 3.66, 0.069, 13.407, 2.544, 0, 2, 6.899, 5.88, 0.715 }, // N_1 16
    { 0.658, 104.51, 3.5, 0.06, 14.085, 2.3, 0.018, 2, 8.741, 6.682, 0.669 }, // O_3 17
    { 0.528, 146, 3.5, 0.06, 14.085, 2.3, 0.018, 2, 8.741, 6.682, 0.669 }, // O_3_z 18
    { 0.68, 110, 3.5, 0.06, 14.085, 2.3, 0, 2, 8.741, 6.682, 0.669 }, // O_R 19
    { 0.634, 120, 3.5, 0.06, 14.085, 2.3, 0, 2, 8.741, 6.682, 0.669 }, // O_2 20
    { 0.639, 180, 3.5, 0.06, 14.085, 2.3, 0, 2, 8.741, 6.682, 0.669 }, // O_1 21
    { 0.668, 180, 3.364, 0.05, 14.762, 1.735, 0, 2, 10.874, 7.474, 0.706 }, // F_ 22
    { 0.92, 90, 3.243, 0.042, 15.44, 0.194, 0, 2, 11.04, 10.55, 1.768 }, // Ne4+4 23
    { 1.539, 180, 2.983, 0.03, 12, 1.081, 0, 1.25, 2.843, 2.296, 2.085 }, // Na 24
    { 1.421, 109.47, 3.021, 0.111, 12, 1.787, 0, 1.25, 3.951, 3.693, 1.5 }, // Mg3+2 25
    { 1.244, 109.47, 4.499, 0.505, 11.278, 1.792, 0, 1.25, 4.06, 3.59, 1.201 }, // Al3 26
    { 1.117, 109.47, 4.295, 0.402, 12.175, 2.323, 1.225, 1.25, 4.168, 3.487, 1.176 }, // Si3  27
    { 1.101, 93.8, 4.147, 0.305, 13.072, 2.863, 2.4, 1.25, 5.463, 4, 1.102 }, // P_3+3 28
    { 1.056, 109.47, 4.147, 0.305, 13.072, 2.863, 2.4, 1.25, 5.463, 4, 1.102 }, // P_3+5 29
    { 1.056, 109.47, 4.147, 0.305, 13.072, 2.863, 2.4, 1.25, 5.463, 4, 1.102 }, // P_3+q 30
    { 1.064, 92.1, 4.035, 0.274, 13.969, 2.703, 0.484, 1.25, 6.928, 4.486, 1.047 }, // S_3+2 31
    { 1.049, 103.2, 4.035, 0.274, 13.969, 2.703, 0.484, 1.25, 6.928, 4.486, 1.047 }, // S_3+4 32
    { 1.027, 109.47, 4.035, 0.274, 13.969, 2.703, 0.484, 1.25, 6.928, 4.486, 1.047 }, // S_3+6 33
    { 1.077, 92.2, 4.035, 0.274, 13.969, 2.703, 0, 1.25, 6.928, 4.486, 1.047 }, // S_R 34
    { 0.854, 120, 4.035, 0.274, 13.969, 2.703, 0, 1.25, 6.928, 4.486, 1.047 }, // S_2 35
    { 1.044, 180, 3.947, 0.227, 14.866, 2.348, 0, 1.25, 8.564, 4.946, 0.994 }, // Cl 36
    { 1.032, 90, 3.868, 0.185, 15.763, 0.3, 0, 1.25, 9.465, 6.355, 2.108 }, // Ar4+4 37
    { 1.953, 180, 3.812, 0.035, 12, 1.165, 0, 0.7, 2.421, 1.92, 2.586 }, // K_ 38
    { 1.761, 90, 3.399, 0.238, 12, 2.141, 0, 0.7, 3.231, 2.88, 2 }, // Ca6+2 39
    { 1.513, 109.47, 3.295, 0.019, 12, 2.592, 0, 0.7, 3.395, 3.08, 1.75 }, // Sc3+3 40
    { 1.412, 109.47, 3.175, 0.017, 12, 2.659, 0, 0.7, 3.47, 3.38, 1.607 }, // Ti3+4 41
    { 1.412, 90, 3.175, 0.017, 12, 2.659, 0, 0.7, 3.47, 3.38, 1.607 }, // Ti6+4 42
    { 1.402, 109.47, 3.144, 0.016, 12, 2.679, 0, 0.7, 3.65, 3.41, 1.47 }, // V_3+5 43
    { 1.345, 90, 3.023, 0.015, 12, 2.463, 0, 0.7, 3.415, 3.865, 1.402 }, // Cr6+3 44
    { 1.382, 90, 2.961, 0.013, 12, 2.43, 0, 0.7, 3.325, 4.105, 1.533 }, // Mn6+2 45
    { 1.27, 109.47, 2.912, 0.013, 12, 2.43, 0, 0.7, 3.76, 4.14, 1.393 }, // Fe3+2 46
    { 1.335, 90, 2.912, 0.013, 12, 2.43, 0, 0.7, 3.76, 4.14, 1.393 }, // Fe6+2 47
    { 1.241, 90, 2.872, 0.014, 12, 2.43, 0, 0.7, 4.105, 4.175, 1.406 }, // Co6+3 48
    { 1.164, 90, 2.834, 0.015, 12, 2.43, 0, 0.7, 4.465, 4.205, 1.398 }, // Ni4+2 49
    { 1.302, 109.47, 3.495, 0.005, 12, 1.756, 0, 0.7, 4.2, 4.22, 1.434 }, // Cu3+1 50
    { 1.193, 109.47, 2.763, 0.124, 12, 1.308, 0, 0.7, 5.106, 4.285, 1.4 }, // Zn3+2 51
    { 1.26, 109.47, 4.383, 0.415, 11, 1.821, 0, 0.7, 3.641, 3.16, 1.211 }, // Ga3+3 52
    { 1.197, 109.47, 4.28, 0.379, 12, 2.789, 0.701, 0.7, 4.051, 3.438, 1.189 }, // Ge3 53
    { 1.211, 92.1, 4.23, 0.309, 13, 2.864, 1.5, 0.7, 5.188, 3.809, 1.204 }, // As3+3 54
    { 1.19, 90.6, 4.205, 0.291, 14, 2.764, 0.335, 0.7, 6.428, 4.131, 1.224 }, // Se3+2 55
    { 1.192, 180, 4.189, 0.251, 15, 2.519, 0, 0.7, 7.79, 4.425, 1.141 }, // Br 56
    { 1.147, 90, 4.141, 0.22, 16, 0.452, 0, 0.7, 8.505, 5.715, 2.27 }, // Kr4+4 57
    { 2.26, 180, 4.114, 0.04, 12, 1.592, 0, 0.2, 2.331, 1.846, 2.77 }, // Rb 58
    { 2.052, 90, 3.641, 0.235, 12, 2.449, 0, 0.2, 3.024, 2.44, 2.415 }, // Sr6+2 59
    { 1.698, 109.47, 3.345, 0.072, 12, 3.257, 0, 0.2, 3.83, 2.81, 1.998 }, // Y_3+3 60
    { 1.564, 109.47, 3.124, 0.069, 12, 3.667, 0, 0.2, 3.4, 3.55, 1.758 }, // Zr3+4 61
    { 1.473, 109.47, 3.165, 0.059, 12, 3.618, 0, 0.2, 3.55, 3.38, 1.603 }, // Nb3+5 62
    { 1.467, 90, 3.052, 0.056, 12, 3.4, 0, 0.2, 3.465, 3.755, 1.53 }, // Mo6+6 63
    { 1.484, 109.47, 3.052, 0.056, 12, 3.4, 0, 0.2, 3.465, 3.755, 1.53 }, // Mo3+6 64
    { 1.322, 90, 2.998, 0.048, 12, 3.4, 0, 0.2, 3.29, 3.99, 1.5 }, // Tc6+5 65
    { 1.478, 90, 2.963, 0.056, 12, 3.4, 0, 0.2, 3.575, 4.015, 1.5 }, // Ru6+2 66
    { 1.332, 90, 2.929, 0.053, 12, 3.5, 0, 0.2, 3.975, 4.005, 1.509 }, // Rh6+3 67
    { 1.338, 90, 2.899, 0.048, 12, 3.21, 0, 0.2, 4.32, 4, 1.544 }, // Pd4+2 68
    { 1.386, 180, 3.148, 0.036, 12, 1.956, 0, 0.2, 4.436, 3.134, 1.622 }, // Ag1+1 69
    { 1.403, 109.47, 2.848, 0.228, 12, 1.65, 0, 0.2, 5.034, 3.957, 1.6 }, // Cd3+2 70
    { 1.459, 109.47, 4.463, 0.599, 11, 2.07, 0, 0.2, 3.506, 2.896, 1.404 }, // In3+3 71
    { 1.398, 109.47, 4.392, 0.567, 12, 2.961, 0.199, 0.2, 3.987, 3.124, 1.354 }, // Sn3 72
    { 1.407, 91.6, 4.42, 0.449, 13, 2.704, 1.1, 0.2, 4.899, 3.342, 1.404 }, // Sb3+3 73
    { 1.386, 90.25, 4.47, 0.398, 14, 2.882, 0.3, 0.2, 5.816, 3.526, 1.38 }, // Te3+2 74
    { 1.382, 180, 4.5, 0.339, 15, 2.65, 0, 0.2, 6.822, 3.762, 1.333 }, // I_ 75
    { 1.267, 90, 4.404, 0.332, 12, 0.556, 0, 0.2, 7.595, 4.975, 2.459 }, // Xe4+4 76
    { 2.57, 180, 4.517, 0.045, 12, 1.573, 0, 0.1, 2.183, 1.711, 2.984 }, // Cs
    { 2.277, 90, 3.703, 0.364, 12, 2.727, 0, 0.1, 2.814, 2.396, 2.442 }, // Ba6+2
    { 1.943, 109.47, 3.522, 0.017, 12, 3.3, 0, 0.1, 2.8355, 2.7415, 2.071 }, // La3+3
    { 1.841, 90, 3.556, 0.013, 12, 3.3, 0, 0.1, 2.774, 2.692, 1.925 }, // Ce6+3
    { 1.823, 90, 3.606, 0.01, 12, 3.3, 0, 0.1, 2.858, 2.564, 2.007 }, // Pr6+3
    { 1.816, 90, 3.575, 0.01, 12, 3.3, 0, 0.1, 2.8685, 2.6205, 2.007 }, // Nd6+3
    { 1.801, 90, 3.547, 0.009, 12, 3.3, 0, 0.1, 2.881, 2.673, 2 }, // Pm6+3
    { 1.78, 90, 3.52, 0.008, 12, 3.3, 0, 0.1, 2.9115, 2.7195, 1.978 }, // Sm6+3
    { 1.771, 90, 3.493, 0.008, 12, 3.3, 0, 0.1, 2.8785, 2.7875, 2.227 }, // Eu6+3
    { 1.735, 90, 3.368, 0.009, 12, 3.3, 0, 0.1, 3.1665, 2.9745, 1.968 }, // Gd6+3
    { 1.732, 90, 3.451, 0.007, 12, 3.3, 0, 0.1, 3.018, 2.834, 1.954 }, // Tb6+3
    { 1.71, 90, 3.428, 0.007, 12, 3.3, 0, 0.1, 3.0555, 2.8715, 1.934 }, // Dy6+3
    { 1.696, 90, 3.409, 0.007, 12, 3.416, 0, 0.1, 3.127, 2.891, 1.925 }, // Ho6+3
    { 1.673, 90, 3.391, 0.007, 12, 3.3, 0, 0.1, 3.1865, 2.9145, 1.915 }, // Er6+3
    { 1.66, 90, 3.374, 0.006, 12, 3.3, 0, 0.1, 3.2514, 2.9329, 2 }, // Tm6+3
    { 1.637, 90, 3.355, 0.228, 12, 2.618, 0, 0.1, 3.2889, 2.965, 2.158 }, // Yb6+3
    { 1.671, 90, 3.64, 0.041, 12, 3.271, 0, 0.1, 2.9629, 2.4629, 1.896 }, // Lu6+3
    { 1.611, 109.47, 3.141, 0.072, 12, 3.921, 0, 0.1, 3.7, 3.4, 1.759 }, // Hf3+4
    { 1.511, 109.47, 3.17, 0.081, 12, 4.075, 0, 0.1, 5.1, 2.85, 1.605 }, // Ta3+5
    { 1.392, 90, 3.069, 0.067, 12, 3.7, 0, 0.1, 4.63, 3.31, 1.538 }, // W_6+6
    { 1.526, 109.47, 3.069, 0.067, 12, 3.7, 0, 0.1, 4.63, 3.31, 1.538 }, // W_3+4
    { 1.38, 109.47, 3.069, 0.067, 12, 3.7, 0, 0.1, 4.63, 3.31, 1.538 }, // W_3+6
    { 1.372, 90, 2.954, 0.066, 12, 3.7, 0, 0.1, 3.96, 3.92, 1.6 }, // Re6+5
    { 1.314, 109.47, 2.954, 0.066, 12, 3.7, 0, 0.1, 3.96, 3.92, 1.6 }, // Re3+7
    { 1.372, 90, 3.12, 0.037, 12, 3.7, 0, 0.1, 5.14, 3.63, 1.7 }, // Os6+6
    { 1.371, 90, 2.84, 0.073, 12, 3.731, 0, 0.1, 5, 4, 1.866 }, // Ir6+3
    { 1.364, 90, 2.754, 0.08, 12, 3.382, 0, 0.1, 4.79, 4.43, 1.557 }, // Pt4+2
    { 1.262, 90, 3.293, 0.039, 12, 2.625, 0, 0.1, 4.894, 2.586, 1.618 }, // Au4+3
    { 1.34, 180, 2.705, 0.385, 12, 1.75, 0, 0.1, 6.27, 4.16, 1.6 }, // Hg1+2
    { 1.518, 120, 4.347, 0.68, 11, 2.068, 0, 0.1, 3.2, 2.9, 1.53 }, // Tl3+3
    { 1.459, 109.47, 4.297, 0.663, 12, 2.846, 0.1, 0.1, 3.9, 3.53, 1.444 }, // Pb3
    { 1.512, 90, 4.37, 0.518, 13, 2.47, 1, 0.1, 4.69, 3.74, 1.514 }, // Bi3+3
    { 1.5, 90, 4.709, 0.325, 14, 2.33, 0.3, 0.1, 4.21, 4.21, 1.48 }, // Po3+2
    { 1.545, 180, 4.75, 0.284, 15, 2.24, 0, 0.1, 4.75, 4.75, 1.47 }, // At
    { 1.42, 90, 4.765, 0.248, 16, 0.583, 0, 0.1, 5.37, 5.37, 2.2 }, // Rn4+4
    { 2.88, 180, 4.9, 0.05, 12, 1.847, 0, 0, 2, 2, 2.3 }, // Fr
    { 2.512, 90, 3.677, 0.404, 12, 2.92, 0, 0, 2.843, 2.434, 2.2 }, // Ra6+2
    { 1.983, 90, 3.478, 0.033, 12, 3.9, 0, 0, 2.835, 2.835, 2.108 }, // Ac6+3
    { 1.721, 90, 3.396, 0.026, 12, 4.202, 0, 0, 3.175, 2.905, 2.018 }, // Th6+4
    { 1.711, 90, 3.424, 0.022, 12, 3.9, 0, 0, 2.985, 2.905, 1.8 }, // Pa6+4
    { 1.684, 90, 3.395, 0.022, 12, 3.9, 0, 0, 3.341, 2.853, 1.713 }, // U_6+4
    { 1.666, 90, 3.424, 0.019, 12, 3.9, 0, 0, 3.549, 2.717, 1.8 }, // Np6+4
    { 1.657, 90, 3.424, 0.016, 12, 3.9, 0, 0, 3.243, 2.819, 1.84 }, // Pu6+4
    { 1.66, 90, 3.381, 0.014, 12, 3.9, 0, 0, 2.9895, 3.0035, 1.942 }, // Am6+4
    { 1.801, 90, 3.326, 0.013, 12, 3.9, 0, 0, 2.8315, 3.1895, 1.9 }, // Cm6+3
    { 1.761, 90, 3.339, 0.013, 12, 3.9, 0, 0, 3.1935, 3.0355, 1.9 }, // Bk6+3
    { 1.75, 90, 3.313, 0.013, 12, 3.9, 0, 0, 3.197, 3.101, 1.9 }, // Cf6+3
    { 1.724, 90, 3.299, 0.012, 12, 3.9, 0, 0, 3.333, 3.089, 1.9 }, // Es6+3
    { 1.712, 90, 3.286, 0.012, 12, 3.9, 0, 0, 3.4, 3.1, 1.9 }, // Fm6+3
    { 1.689, 90, 3.274, 0.011, 12, 3.9, 0, 0, 3.47, 3.11, 1.9 }, // Md6+3
    { 1.679, 90, 3.248, 0.011, 12, 3.9, 0, 0, 3.475, 3.175, 1.9 }, // No6+3
    { 1.698, 90, 3.236, 0.011, 12, 3.9, 0, 0, 3.5, 3.2, 1.9 } // Lw6+3
};

const std::vector<int> Conjugated = { 10, 11, 14, 15, 19, 20 };
const std::vector<int> Triples = { 12, 16, 21 };

const int cR = 0;
const int cTheta0 = 1;
const int cx = 2;
const int cD = 3;
const int cZeta = 4;
const int cZ = 5;
const int cV = 6;
const int cU = 7;
const int cXi = 8;
const int cHard = 9;
const int cRadius = 10;
