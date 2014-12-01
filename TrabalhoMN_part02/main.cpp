#include <iostream>
#include <fstream>
#include <ctime>
#include "SquareMatrix.h"
#include "VectorN.h"
#include "DirectMethods.h"


int main(int argc, char **argv) {
	int n;
	SquareMatrix *A1;
	SquareMatrix *A2;
	VectorN *b1;
	VectorN *b2;
	std::ifstream in_file;
	std::ofstream out_file;

	if (argc < 2) {
		std::cout << "Erro! Arquivo de entrada nao especificado! Para executar este programa use:" << std::endl;
		std::cout << "$ ./<nome-do-programa> <nome-do-arquivo-de-entrada>" << std::endl;
		std::cout << "Saindo..." << std::endl;

		return -1;
	}
	else {

		/// Ler arquivo para povoar n, A e b
		in_file.open(argv[1]);
		if (!in_file.is_open()) {
			std::cout << "Erro! Arquivo de entrada nao encontrado! Para executar este programa use:" << std::endl;
			std::cout << "$ ./<nome-do-programa> <nome-do-arquivo-de-entrada>" << std::endl;
			std::cout << "Saindo..." << std::endl;

			return -1;
		}

		std::cout << "Lendo arquivo " << argv[1] << "..." << std::endl;
		// Lendo n (dimensão da matriz)
		in_file >> n;
		std::cout << "n = " << n << std::endl;

		// Lendo matriz A
		A1 = new SquareMatrix(n + 1);
		A2 = new SquareMatrix(n);
		std::cout << "Matriz A:" << std::endl;
		for (int i = 0; i < n; i++) {
			std::cout << "[\t";
			for (int j = 0; j < n; j++) {
				double value;
				in_file >> value;
				std::cout << value << "\t";
				A1->set_value(value, i + 1, j + 1);
				A2->set_value(value, i, j);
			}
			std::cout << "]" << std::endl;
		}

		// Lendo vetor b
		b1 = new VectorN(n + 1);
		b2 = new VectorN(n);
		std::cout << "Vetor b:" << std::endl;
		std::cout << "[\t";
		for (int i = 0; i < n; i++) {
			double value;
			in_file >> value;
			std::cout << value << "\t";
			b1->set_value(value, i + 1);
			b2->set_value(value, i);
		}
		std::cout << "]" << std::endl;
		in_file.close();


		/// Executando fatoracao LU com pivotacao
		clock_t start_time;
		start_time = clock();

		std::cout << "Calculando valores de c pela fatoracao LU com pivotacao..." << std::endl;
		VectorN *c1 = FatoracaoLU(n, A1, b1);
		double time_in_seconds1 = (clock() - start_time) / (double)CLOCKS_PER_SEC;
		std::cout << "Tempo de execucao: " << time_in_seconds1 << " segundos." << std::endl;
		std::cout << std::endl;

		/// Executando doolittle sem pivotacao
		start_time = clock();
		std::cout << "Calculando valores de c pela reducao de doolittle sem pivotacao..." << std::endl;
		VectorN *c2 = doolittleLU(*A2, *b2);
		double time_in_seconds2 = (clock() - start_time) / (double)CLOCKS_PER_SEC;
		std::cout << "Tempo de execucao: " << time_in_seconds2 << " segundos." << std::endl;
		std::cout << std::endl;


		/// Gravando resultados
		std::cout << "Gravando resultados no arquivo 'saida.txt'..." << std::endl;
		out_file.open("saida.txt");
		out_file << "Valor de c pela fatoracao LU com pivotacao:" << std::endl;
		std::cout << "Valor de c pela fatoracao LU com pivotacao:" << std::endl;
		out_file << "c = [\t";
		std::cout << "c = [\t";
		for (int i = 0; i < n; i++) {
			out_file << c1->get_value(i + 1) << "\t";
			std::cout << c1->get_value(i + 1) << "\t";
		}
		out_file << "]" << std::endl;
		out_file << "Tempo de execucao: " << time_in_seconds1 << " segundos." << std::endl;
		out_file << std::endl;
		std::cout << "]" << std::endl;
		std::cout << std::endl;

		out_file << "Valor de c pela reducao doolittle sem pivotacao:" << std::endl;
		std::cout << "Valor de c pela reducao doolittle sem pivotacao:" << std::endl;
		out_file << "c = [\t";
		std::cout << "c = [\t";
		for (int i = 0; i < n; i++) {
			out_file << c2->get_value(i) << "\t";
			std::cout << c2->get_value(i) << "\t";
		}
		out_file << "]" << std::endl;
		out_file << "Tempo de execucao: " << time_in_seconds2 << " segundos." << std::endl;
		out_file << std::endl;
		std::cout << "]" << std::endl;
		std::cout << std::endl;
		out_file.close();

		std::cout << "Terminado!" << std::endl;
	}


	return 0;
}
