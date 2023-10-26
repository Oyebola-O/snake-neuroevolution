#pragma once
#include "headers.h"
#include "functions.h"

class NeuralNetwork {
    class Layer {
        public:
            int layerSize;
            vector<double> bias;
            vector<double> nodeValues;
            vector<vector<double>> weights;

            Layer(int size, int nextSize){
                layerSize = size;
                bias.reserve(size);
                weights.reserve(size);

                for(int i = 0; i < size; i++){
                    bias.push_back(HOBO::randomDouble(0, 1));

                    weights.push_back(vector<double>());
                    weights[i].reserve(nextSize);
                    for(int j = 0; j < nextSize; j++){
                        weights[i].push_back(HOBO::randomDouble(0, 1));
                    }
                }
            }
    };

    vector<Layer> layers;
    public:
        NeuralNetwork(vector<int>);
        NeuralNetwork(NeuralNetwork, NeuralNetwork);

        void save();
        void mutate();
        void forward();
        void print();
};