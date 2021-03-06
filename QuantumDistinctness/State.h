/*
 * Quatum Element Distinctness Simulator
 *
 * File: State.h
 *
 * Created on: 2014
 *    Authors: Alexandre Santiago de Abreu
 *             Matheus Manzoli Ferreira
 *
 *      Email: santiago@cos.ufrj.br
 *             matheusmanzoli@gmail.com
 *
 * B.Sc. dissertation for the 
 * Universidade Federal Fluminense.
 * Institute of Computing.
 * Niter�i, Rio de Janeiro, Brazil.
 *
 * This file contains the methods of State class.
 * All description are in cpp file.
 */

#ifndef STATE_H_
#define STATE_H_

#include "Library.h"

class State {

public:
    State();
    virtual ~State();

    void insert_in_S(int *elements, int length);
    void insert_in_y(int *elements, int length);

    void display_in_file_without_x(ofstream& quantumFile);
    void display_in_file_with_x(ofstream& quantumFile, int *elements);
    void display_in_file_with_x_with_0(ofstream& quantumFile, int *elements);

    void search_equals_change_signal(int *elements, int kDistinctness);
    void transformation_mapping(float factor);

    void change_amplitude(int first, double amplitude);

    double measurement(double cumulativeProbability, double random, unsigned int root, int &found);

    bool amplitudes_equals_of_y();
    double getAmplitude();

    set<int> getS();
    map<int, double> getY();

private:
    set<int> S;
    map<int, double> y;

};

#endif
