#include "nn.h"

NeuralNetwork::NeuralNetwork(vector<int> shape) {
    for(int i = 0; i < shape.size() - 1; i++){
        layers.push_back(Layer(shape[i], shape[i + 1]));
    }
    layers.push_back(Layer(shape.back(), 0));
}

void NeuralNetwork::forward() {
    for(int layer = 1; layer < layers.size(); layer++){
        Layer& currLayer = layers[layer];
        Layer& prevLayer = layers[layer - 1];
        for(int node = 0; node < currLayer.layerSize; node++){
            double value = 0;
            for(int prevNode = 0; prevNode < prevLayer.layerSize; prevNode++){
                value += prevLayer.weights[prevNode][node] * prevLayer.nodeValues[prevNode];
            }
            value += currLayer.bias[node];
            currLayer.nodeValues[node] = HOBO::relu(value);
        }
    }
}

void NeuralNetwork::print() {
    for(int l = 0; l < layers.size(); l++){
        std::cout << "Layer " << l + 1 << ":\n";
        for(int n = 0; n < layers[l].layerSize; n++){
            std::cout << "  Node " << n + 1 << ": Value = " << layers[l].nodeValues[n];
            std::cout << ", Bias = " << layers[l].bias[n] << "\n";
            if(l < layers.size() - 1) { // No weights for the last layer
                std::cout << "    Weights: ";
                for(int w = 0; w < layers[l + 1].layerSize; w++){
                    std::cout << layers[l].weights[n][w] << " ";
                }
                std::cout << "\n";
            }
        }
        std::cout << "----------------------------------\n";
    }
}
