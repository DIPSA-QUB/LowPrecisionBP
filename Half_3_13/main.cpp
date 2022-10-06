//
// Created by Mark Van der Merwe, Summer 2018
//
// Edited/Changed by Amir Sabbagh Molahosseini, Summer 2022
//

#include "header.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
// Run inference on the provided graph file. Graph representation can be found summarized in pgm.cpp
// Input: txt graph file, timeout, and runtime parameters.
// Output: marginal distributions of requested nodes.
int main(int argc, char *argv[]) {

  // Parse inputs.
  if (argc < 3) {
    std::cout << "Usage:\n   ./main.out <graph filename> <timeout> [...runtime params]\n   Graph filename should be a txt file containing the graph parameters. Runtime parameters should be integer to parameterize the run." << std::endl;
    return -1;
  }
  std::string filename = argv[1];
  int timeout = std::stoi(argv[2]);
  std::vector<int> runtime_params;
  for (int argc_iter = 3; argc_iter < argc; ++argc_iter) {
    runtime_params.push_back(std::stoi(argv[argc_iter]));
  }

  // Read in the graph from the file.
  pgm* test_pgm = new pgm(filename);
  
  // Debug - output graph representation.
  // test_pgm->print();

  // Run inference on graph.
  std::tuple<float, std::vector<float>, int, std::vector<std::pair<int, int>>, std::vector<std::pair<float,int>>> results = infer(test_pgm, 0.1, timeout, runtime_params, true);
  
  std::cout << "Runtime: " << std::get<0>(results) << " ms." << std::endl;

  //print_array(std::get<1>(results));
//---------------- write marginals to file
  std::ofstream marginals_file1;
  marginals_file1.open("1_Ising_17_c_2_e_0_1_half_3_13_marginals.txt");
  
  
  marginals_file1 << "1_Ising_17_c_2_e_0.1_half_3_13_marginals \n" << "Runtime: " << std::get<0>(results) << "\n"<< "Iterations: " << std::get<2>(results) << std::endl;
 
  marginals_file1 << test_pgm->marginal_rep.size() << "\n";
  
  for (float marginal: std::get<1>(results)) {
    marginals_file1 << marginal << "\n";
  }
  marginals_file1.close(); 
  
  //-----------------
  
  free(test_pgm);

  return 0;
}
