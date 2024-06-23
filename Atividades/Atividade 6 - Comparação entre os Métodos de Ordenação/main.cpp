#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

// Função para contar operações de leitura e escrita no vetor
struct OperationCount {
    long readCount = 0;
    long writeCount = 0;
};

void bubbleSort(int arr[], int n, OperationCount &ops) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            ops.readCount += 2; // comparando arr[j] e arr[j+1]
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                ops.readCount += 2; // lendo arr[j] e arr[j+1] para swap
                ops.writeCount += 2; // escrevendo arr[j] e arr[j+1] para swap
            }
        }
    }
}

void insertionSort(int arr[], int n, OperationCount &ops) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        ops.readCount++; // lendo arr[i]
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            ops.readCount++; // lendo arr[j]
            arr[j + 1] = arr[j];
            ops.readCount++; // lendo arr[j] para atribuição
            ops.writeCount++; // escrevendo arr[j + 1]
            j = j - 1;
        }
        arr[j + 1] = key;
        ops.writeCount++; // escrevendo arr[j + 1]
    }
}

void selectionSort(int arr[], int n, OperationCount &ops) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            ops.readCount += 2; // comparando arr[j] com arr[min_idx]
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[min_idx], arr[i]);
        ops.readCount += 2; // lendo arr[min_idx] e arr[i] para swap
        ops.writeCount += 2; // escrevendo arr[min_idx] e arr[i] para swap
    }
}

void generateVectors(std::vector<int> &ascending, std::vector<int> &random, std::vector<int> &descending, const std::string &filename) {
    std::ifstream file(filename);
    int n;
    file >> n;
    random.resize(n);
    for (int i = 0; i < n; i++) {
        file >> random[i];
    }
    ascending = random;
    std::sort(ascending.begin(), ascending.end());
    descending = ascending;
    std::reverse(descending.begin(), descending.end());
}

void runSortingAlgorithms(const std::vector<int> &vecAsc, const std::vector<int> &vecRand, const std::vector<int> &vecDesc) {
    std::ofstream resultFile("results.txt");

    for (int size = 100; size <= 100000; size = (size < 1000) ? size + 100 : (size < 10000) ? size + 1000 : size + 10000) {
        std::vector<int> vecAscSub(vecAsc.begin(), vecAsc.begin() + size);
        std::vector<int> vecRandSub(vecRand.begin(), vecRand.begin() + size);
        std::vector<int> vecDescSub(vecDesc.begin(), vecDesc.begin() + size);

        OperationCount opsBubbleAsc, opsBubbleRand, opsBubbleDesc;
        OperationCount opsInsertionAsc, opsInsertionRand, opsInsertionDesc;
        OperationCount opsSelectionAsc, opsSelectionRand, opsSelectionDesc;

        bubbleSort(vecAscSub.data(), size, opsBubbleAsc);
        bubbleSort(vecRandSub.data(), size, opsBubbleRand);
        bubbleSort(vecDescSub.data(), size, opsBubbleDesc);

        vecAscSub.assign(vecAsc.begin(), vecAsc.begin() + size);
        vecRandSub.assign(vecRand.begin(), vecRand.begin() + size);
        vecDescSub.assign(vecDesc.begin(), vecDesc.begin() + size);

        insertionSort(vecAscSub.data(), size, opsInsertionAsc);
        insertionSort(vecRandSub.data(), size, opsInsertionRand);
        insertionSort(vecDescSub.data(), size, opsInsertionDesc);

        vecAscSub.assign(vecAsc.begin(), vecAsc.begin() + size);
        vecRandSub.assign(vecRand.begin(), vecRand.begin() + size);
        vecDescSub.assign(vecDesc.begin(), vecDesc.begin() + size);

        selectionSort(vecAscSub.data(), size, opsSelectionAsc);
        selectionSort(vecRandSub.data(), size, opsSelectionRand);
        selectionSort(vecDescSub.data(), size, opsSelectionDesc);

        resultFile << "Size: " << size << "\n";
        resultFile << "Bubble Sort (Ascending) - Reads: " << opsBubbleAsc.readCount << ", Writes: " << opsBubbleAsc.writeCount << "\n";
        resultFile << "Bubble Sort (Random) - Reads: " << opsBubbleRand.readCount << ", Writes: " << opsBubbleRand.writeCount << "\n";
        resultFile << "Bubble Sort (Descending) - Reads: " << opsBubbleDesc.readCount << ", Writes: " << opsBubbleDesc.writeCount << "\n";
        resultFile << "Insertion Sort (Ascending) - Reads: " << opsInsertionAsc.readCount << ", Writes: " << opsInsertionAsc.writeCount << "\n";
        resultFile << "Insertion Sort (Random) - Reads: " << opsInsertionRand.readCount << ", Writes: " << opsInsertionRand.writeCount << "\n";
        resultFile << "Insertion Sort (Descending) - Reads: " << opsInsertionDesc.readCount << ", Writes: " << opsInsertionDesc.writeCount << "\n";
        resultFile << "Selection Sort (Ascending) - Reads: " << opsSelectionAsc.readCount << ", Writes: " << opsSelectionAsc.writeCount << "\n";
        resultFile << "Selection Sort (Random) - Reads: " << opsSelectionRand.readCount << ", Writes: " << opsSelectionRand.writeCount << "\n";
        resultFile << "Selection Sort (Descending) - Reads: " << opsSelectionDesc.readCount << ", Writes: " << opsSelectionDesc.writeCount << "\n";
        resultFile << "\n";
    }

    resultFile.close();
}

int main() {
    std::vector<int> ascending, random, descending;
    generateVectors(ascending, random, descending, "numbers.txt");
    runSortingAlgorithms(ascending, random, descending);

    std::cout << "Sorting completed and results saved to results.txt" << std::endl;

    return 0;
}
