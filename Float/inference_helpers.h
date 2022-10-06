//
// Created by Mark Van der Merwe, Fall 2018
//
// Edited/Changed by Amir Sabbagh Molahosseini, Summer 2022
//

#ifndef CUPGM_PARALLEL_INFERENCE_SERIAL_INFERENCE_HELPERS_H_
#define CUPGM_PARALLEL_INFERENCE_SERIAL_INFERENCE_HELPERS_H_

#include <vector>
#include "header.h"
#include <iostream>

// Update given edge, return the message delta.
float compute_message(pgm* pgm, std::vector<float> &workspace, int edge_id, bool write_to_edges=false);

float message_delta(std::vector<float> edges, std::vector<float> workspace, int edge_start);

void compute_marginals(pgm* pgm);

void print_doubles(std::vector<float> values);

#endif // CUPGM_PARALLEL_INFERENCE_SERIAL_INFERENCE_HELPERS_H_
