#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>

// Floyd-Warshall.
std::vector<std::vector<unsigned short>>
floyd_warshall(std::vector<std::vector<unsigned short>>& ma_adj) {
	// Inicialização.	
	std::vector<std::vector<unsigned short>> dist = ma_adj;
	std::vector<std::vector<unsigned short>> pred = ma_adj;
	for (unsigned short i = 0; i < ma_adj.size(); i++) {
		for (unsigned short j = 0; j < ma_adj.size(); j++) {
			if (dist[i][j] != 0) {
				pred[i][j] = i;
			}
		}
	}

	// Laço principal.
	for (unsigned short k = 0; k < ma_adj.size(); k++) {
		for (unsigned short i = 0; i < ma_adj.size(); i++) {
			for (unsigned short j = 0; j < ma_adj.size(); j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k]+ dist[k][j];
					pred[i][j] = pred[k][j];
				}
			}
		}
	}

	return dist;
}

int main() {
	std::vector<std::vector<unsigned short>> ma_adj = {
		{ 0, 3,  1, 0,  7  }, 
		{ 3, 0,  0, 42, 2  }, 
		{ 1, 0,  0, 4,  5  }, 
		{ 0, 42, 4, 0,  20 }, 
		{ 7, 2,  5, 20, 0  } 
	};

	// Computar tempo de execução (clocks).
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<std::vector<unsigned short>> distances = floyd_warshall(ma_adj);
	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = finish - start;


	// Emitir retorno da função e o tempo de execução.
	for (unsigned short i = 0; i < distances.size(); i++) {
		for (unsigned short j = 0; j < distances.size(); j++) {
			std::cout << distances[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Tempo de execução: " << elapsed.count() << " segundos." << std::endl;

	return 0;
}
